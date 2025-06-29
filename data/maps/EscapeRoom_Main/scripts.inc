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
	map_script_2 VAR_REMOVE_HELD_ITEM, 1, EscapeRoom_MapScripts_RemoveHeldItem
# 59 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ASK_RESET_PREDAMAGE, 1, EscapeRoom_MapScripts_AskResetPredamage
# 60 "data/maps/EscapeRoom_Main/scripts.pory"
	map_script_2 VAR_ROCK_SMASH_NPC_STATE, 1, EscapeRoom_MapScripts_CheckIfRockSmashed
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 68 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_HIDE_ANNIHILAPE, EscapeRoom_MapScript_OnTransitionScripts_2
EscapeRoom_MapScript_OnTransitionScripts_1:
# 73 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TRAINER3_DEFEATED, EscapeRoom_MapScript_OnTransitionScripts_4
	return

EscapeRoom_MapScript_OnTransitionScripts_2:
# 69 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_LOOK_AROUND
	goto EscapeRoom_MapScript_OnTransitionScripts_1

EscapeRoom_MapScript_OnTransitionScripts_4:
# 74 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectxyperm 5, 62, 10
# 75 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	return


EscapeRoom_MapScript_OnResumeScripts::
# 81 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 82 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_ge EscapeRoom_MapScript_OnResumeScripts_3
EscapeRoom_MapScript_OnResumeScripts_1:
# 97 "data/maps/EscapeRoom_Main/scripts.pory"
	getpartysize
# 98 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_7
EscapeRoom_MapScript_OnResumeScripts_6:
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_LIEPARD_SACKED, EscapeRoom_MapScript_OnResumeScripts_11
EscapeRoom_MapScript_OnResumeScripts_9:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_BALL_USED, EscapeRoom_MapScript_OnResumeScripts_18
EscapeRoom_MapScript_OnResumeScripts_16:
# 124 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScript_OnResumeScripts_22
EscapeRoom_MapScript_OnResumeScripts_21:
# 130 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_STOLEN, EscapeRoom_MapScript_OnResumeScripts_25
EscapeRoom_MapScript_OnResumeScripts_24:
# 135 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_28
EscapeRoom_MapScript_OnResumeScripts_27:
# 140 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_PLAYER_JUST_LOST, EscapeRoom_MapScript_OnResumeScripts_31
EscapeRoom_MapScript_OnResumeScripts_30:
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_JUST_HAD_ZERA_BATTLE, EscapeRoom_MapScript_OnResumeScripts_34
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 83 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERAORA_CAUGHT
# 86 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 87 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_FERRO_CUSTAP
# 88 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
# 91 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_3:
# 82 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_2
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_7:
# 99 "data/maps/EscapeRoom_Main/scripts.pory"
	partymonhasfainted
# 100 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_LIEPARD
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_14
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_10:
# 106 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MENTAL_HERB_USED_FOR_SACK
# 109 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MENTAL_HERB
# 110 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_REMOVE_LIEPARD_MENTAL_HERB
# 111 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 1
# 114 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 115 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_11:
# 104 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MENTAL_HERB_USED_FOR_SACK, EscapeRoom_MapScript_OnResumeScripts_10
	goto EscapeRoom_MapScript_OnResumeScripts_9

EscapeRoom_MapScript_OnResumeScripts_14:
# 101 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_SACKED
	goto EscapeRoom_MapScript_OnResumeScripts_6

EscapeRoom_MapScript_OnResumeScripts_17:
# 120 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	goto EscapeRoom_MapScript_OnResumeScripts_16

EscapeRoom_MapScript_OnResumeScripts_18:
# 119 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_17
	goto EscapeRoom_MapScript_OnResumeScripts_16

EscapeRoom_MapScript_OnResumeScripts_22:
# 126 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 1
	goto EscapeRoom_MapScript_OnResumeScripts_21

EscapeRoom_MapScript_OnResumeScripts_25:
# 131 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_CheckSpaceItemStolen
	goto EscapeRoom_MapScript_OnResumeScripts_24

EscapeRoom_MapScript_OnResumeScripts_28:
# 136 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScript_OnResumeScripts_27

EscapeRoom_MapScript_OnResumeScripts_31:
# 141 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 142 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_38
EscapeRoom_MapScript_OnResumeScripts_37:
# 145 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_PLAYER_JUST_LOST
	goto EscapeRoom_MapScript_OnResumeScripts_30

EscapeRoom_MapScript_OnResumeScripts_33:
# 150 "data/maps/EscapeRoom_Main/scripts.pory"
	partybackupisdifferent
# 151 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_OnResumeScripts_41
EscapeRoom_MapScript_OnResumeScripts_40:
# 154 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_JUST_HAD_ZERA_BATTLE
	return

EscapeRoom_MapScript_OnResumeScripts_34:
# 149 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_MapScript_OnResumeScripts_33
	return

EscapeRoom_MapScript_OnResumeScripts_38:
# 143 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_37

EscapeRoom_MapScript_OnResumeScripts_41:
# 152 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 1
	goto EscapeRoom_MapScript_OnResumeScripts_40


EscapeRoom_MapScript_OnWarpIntoScripts::
	return


EscapeRoom_MapScripts_FindBallAferUse::
# 166 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 167 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NewBallMessage, MSGBOX_AUTOCLOSE
# 168 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 169 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_ULTRA_BALL
# 170 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_BALL_USED
# 171 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 172 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_RetrievedItemMessage::
# 176 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 179 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DO_RECOVERED_ITEM_MESSAGE, EscapeRoom_MapScripts_RetrievedItemMessage_2
EscapeRoom_MapScripts_RetrievedItemMessage_1:
# 185 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_RETRIEVED_HELD_ITEM, 0
# 186 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_RetrievedItemMessage_2:
# 180 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HeldItemRecoveredMessage, MSGBOX_AUTOCLOSE
# 181 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 182 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
	goto EscapeRoom_MapScripts_RetrievedItemMessage_1


EscapeRoom_MapScripts_RemoveHeldItem::
# 191 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_FERRO_CUSTAP, EscapeRoom_MapScripts_RemoveHeldItem_2
EscapeRoom_MapScripts_RemoveHeldItem_1:
# 197 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_REMOVE_LIEPARD_MENTAL_HERB, EscapeRoom_MapScripts_RemoveHeldItem_5
EscapeRoom_MapScripts_RemoveHeldItem_4:
# 202 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_REMOVE_HELD_ITEM, 0
	return

EscapeRoom_MapScripts_RemoveHeldItem_2:
# 192 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_FERRO_CUSTAP
# 193 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveFerroCustap
	goto EscapeRoom_MapScripts_RemoveHeldItem_1

EscapeRoom_MapScripts_RemoveHeldItem_5:
# 198 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_REMOVE_LIEPARD_MENTAL_HERB
# 199 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_RemoveLiepardMentalHerb
	goto EscapeRoom_MapScripts_RemoveHeldItem_4


EscapeRoom_MapScripts_RemoveLiepardMentalHerb::
# 206 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 207 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 208 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveLiepardMentalHerb_1
	return

EscapeRoom_MapScripts_RemoveLiepardMentalHerb_1:
# 209 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 210 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MENTAL_HERB
	goto_if_eq EscapeRoom_MapScripts_RemoveLiepardMentalHerb_3
	return

EscapeRoom_MapScripts_RemoveLiepardMentalHerb_3:
# 211 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_RemoveFerroCustap::
# 217 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 218 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 219 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_MapScripts_RemoveFerroCustap_1
	return

EscapeRoom_MapScripts_RemoveFerroCustap_1:
# 220 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 221 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_MapScripts_RemoveFerroCustap_3
	return

EscapeRoom_MapScripts_RemoveFerroCustap_3:
# 222 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	return


EscapeRoom_MapScripts_CheckSpaceItemStolen::
# 228 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_COMET_SHARD
# 229 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_2
EscapeRoom_MapScripts_CheckSpaceItemStolen_1:
# 232 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 0
# 233 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_COMET_SHARD
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_5
EscapeRoom_MapScripts_CheckSpaceItemStolen_4:
# 236 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 1
# 237 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_COMET_SHARD
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_8
EscapeRoom_MapScripts_CheckSpaceItemStolen_7:
# 240 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem 2
# 241 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_COMET_SHARD
	goto_if_eq EscapeRoom_MapScripts_CheckSpaceItemStolen_10
	return

EscapeRoom_MapScripts_CheckSpaceItemStolen_2:
# 230 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_1

EscapeRoom_MapScripts_CheckSpaceItemStolen_5:
# 234 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_4

EscapeRoom_MapScripts_CheckSpaceItemStolen_8:
# 238 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	goto EscapeRoom_MapScripts_CheckSpaceItemStolen_7

EscapeRoom_MapScripts_CheckSpaceItemStolen_10:
# 242 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_STOLEN
	return


EscapeRoom_MapScripts_AskResetPredamage::
# 247 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 248 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskResetPredamageMessage, MSGBOX_YESNO
# 249 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_MapScripts_AskResetPredamage_2
EscapeRoom_MapScripts_AskResetPredamage_1:
# 253 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ASK_RESET_PREDAMAGE, 0
# 254 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MapScripts_AskResetPredamage_2:
# 250 "data/maps/EscapeRoom_Main/scripts.pory"
	restoreplayerparty
# 251 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox PreDamagedStateRestoredMessage, MSGBOX_AUTOCLOSE
	goto EscapeRoom_MapScripts_AskResetPredamage_1


EscapeRoom_MapScripts_CheckIfRockSmashed::
# 258 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRockSmashNPC
# 259 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ROCK_SMASH_NPC_STATE, 0
	return


EscapeRoom_MapScript_GameStartScripts::
# 266 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScript_GetPokedex
# 267 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetFirstPokemon
# 268 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetBadges
# 269 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_SetRespawn
# 270 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_GetItems
# 271 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MapScripts_TurnOfBagUse
# 272 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ANNIHILAPE
# 273 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 274 "data/maps/EscapeRoom_Main/scripts.pory"
	setobjectmovementtype 31, MOVEMENT_TYPE_FACE_UP
# 275 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 276 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
	return


EscapeRoom_MapScript_GetPokedex::
# 280 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 281 "data/maps/EscapeRoom_Main/scripts.pory"
	special SetUnlockedPokedexFlags
# 282 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
# 283 "data/maps/EscapeRoom_Main/scripts.pory"
	special EnableNationalPokedex
# 284 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 288 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FLORGES, 22, item = ITEM_EXP_CANDY_S, abilityNum = 2, nature = 21, gender = 1, move1 = MOVE_NATURE_POWER, move2 = MOVE_GRASS_KNOT, move3 = MOVE_GRASSY_TERRAIN, move4 = MOVE_CAMOUFLAGE, hpEv = 252, spDefEv = 252, hpIv = 31, atkIv = 0, defIv = 0, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 311 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_FERROTHORN, 28, abilityNum = 2, nature = 4, gender = 0, move1 = MOVE_STEEL_ROLLER, move2 = MOVE_BLOCK, move3 = MOVE_INGRAIN, move4 = MOVE_GRAVITY, hpEv = 0, atkEv = 252, spDefEv = 0, defEv = 0, hpIv = 0, atkIv = 31, defIv = 0, speedIv = 31, spAtkIv = 31, spDefIv = 0
# 335 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 336 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 340 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 341 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE01_GET
# 342 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 343 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE02_GET
# 344 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 345 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE03_GET
# 346 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 347 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE04_GET
# 348 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 349 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE05_GET
# 350 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 351 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE06_GET
# 352 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 353 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE07_GET
# 354 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 355 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_BADGE08_GET
	return


EscapeRoom_MapScripts_SetRespawn::
# 359 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
	return


EscapeRoom_MapScripts_GetItems::
# 363 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_FLUFFY_TAIL
# 364 "data/maps/EscapeRoom_Main/scripts.pory"
	additem ITEM_ETHER
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 368 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_1
	return

EscapeRoom_MapScripts_TurnOfBagUse_1:
# 369 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_EventScript_MainInfoSign::
# 380 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 381 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 382 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MainInfoSign_2
EscapeRoom_EventScript_MainInfoSign_1:
# 387 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MainInfoSign_2:
# 384 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SignMessage1
# 385 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_MainInfoSign_1


EscapeRoom_EventScript_MoveDeleterSign::
# 391 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 392 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterSignMessage, MSGBOX_DEFAULT
# 393 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 394 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_EndSign::
# 398 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 399 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndSign_2
# 406 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 407 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndSign_1:
# 411 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 414 "data/maps/EscapeRoom_Main/scripts.pory"
	bufferplaytimeandhints
# 415 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 416 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 417 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndSign_2:
# 400 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 401 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 402 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 403 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndSign_1


EscapeRoom_EventScript_AnnihilapeStatue::
# 421 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 422 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeStatueMessage, MSGBOX_AUTOCLOSE
# 423 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 424 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallSign::
# 428 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 429 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallSign, MSGBOX_AUTOCLOSE
# 430 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 431 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AncientWallBackroomSign::
# 435 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 436 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MysteriousWallBackroomSign, MSGBOX_AUTOCLOSE
# 437 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 438 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_Nurse_Heal_Pokemon::
# 445 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 446 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 447 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Ask_heal, MSGBOX_YESNO
# 448 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_Nurse_Heal_Pokemon_2
EscapeRoom_Nurse_Heal_Pokemon_1:
# 455 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_Nurse_Heal_Pokemon_2:
# 449 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
# 450 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_USE_ITEM
# 451 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 452 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Nurse_Heal_End, MSGBOX_AUTOCLOSE
# 453 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_Nurse_Heal_Pokemon_1


EscapeRoom_EventScript_HintsNPC::
# 459 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 460 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 462 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 467 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 469 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 463 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_AntiSoftlockGuy::
# 473 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 474 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 477 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockIntroMessage, MSGBOX_DEFAULT
# 478 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AntiSoftlockNoActionMessage, MSGBOX_DEFAULT
# 479 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_LiepardNPC::
# 485 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 486 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 489 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_NORMAL
# 490 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardNPCmainMessage, MSGBOX_AUTOCLOSE
# 491 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 492 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 495 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_POWER_LENS
# 496 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_2
EscapeRoom_EventScript_LiepardNPC_1:
# 563 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_LiepardNPC_2:
# 499 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_LiepardNPC_5
# 509 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 510 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 511 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardCollorFoundMessage, MSGBOX_AUTOCLOSE
# 512 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 513 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 514 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 517 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 518 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, Common_Movement_ExclamationMark
# 519 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 520 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 521 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 524 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement1
# 525 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 526 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement2
# 527 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 528 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 530 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_TRAPINCH, CRY_MODE_NORMAL
# 531 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement3
# 532 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 533 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 534 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement4
# 535 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 536 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 537 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement5
# 538 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 539 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 2
# 540 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 18, LiepardMovement6
# 541 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 18
# 542 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 543 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 546 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_TO_BLACK
# 547 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_LIEPARD_NPC
# 548 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 18
# 549 "data/maps/EscapeRoom_Main/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 552 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_ObtainLiepard
# 553 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 554 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_POWER_LENS
# 557 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 558 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_RelocateNurseNPC
# 561 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_CUSTAP_SOLD_OUT
	goto EscapeRoom_EventScript_LiepardNPC_1

EscapeRoom_EventScript_LiepardNPC_5:
# 502 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 503 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 504 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 505 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 567 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement1:
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
# 568 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_left
	step_end

# 570 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement2:
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
# 571 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_right
	step_end

# 573 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement3:
# 574 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 576 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement4:
# 577 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

# 579 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement5:
# 580 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 582 "data/maps/EscapeRoom_Main/scripts.pory"
LiepardMovement6:
# 583 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_ObtainLiepard::
# 587 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 588 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_LIEPARD, 40, ball = ITEM_FRIEND_BALL, abilityNum = 2, nature = 17, gender = MON_FEMALE, move1 = MOVE_ASSIST, move2 = MOVE_TRICK, move3 = MOVE_ROCK_SMASH, move4 = MOVE_COPYCAT, atkEv = 252, spAtkEv = 252, speedEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 611 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 612 "data/maps/EscapeRoom_Main/scripts.pory"
	message LiepardObtainMessage
# 613 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 614 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 616 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NicknameThisPokemonMessage, MSGBOX_YESNO
# 617 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_ObtainLiepard_2
EscapeRoom_EventScript_ObtainLiepard_1:
# 628 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
	return

EscapeRoom_EventScript_ObtainLiepard_2:
# 618 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 623 "data/maps/EscapeRoom_Main/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto EscapeRoom_EventScript_ObtainLiepard_1


EscapeRoom_EventScript_RelocateNurseNPC::
# 636 "data/maps/EscapeRoom_Main/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE2
# 639 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 640 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 641 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 642 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 645 "data/maps/EscapeRoom_Main/scripts.pory"
	addobject 29
# 646 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement1_Nurse1NPC
# 647 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 650 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerFaceRight
# 651 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 652 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RunningNurseMessage, MSGBOX_NPC
# 653 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 654 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAway
# 655 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 658 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 29, EscapeRoom_Movement2_Nurse1NPC
# 659 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 29
# 660 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 661 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 29
# 664 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 3
# 665 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_NURSE1_NPC
	return


# 668 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerFaceRight:
# 669 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 672 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement1_Nurse1NPC:
# 673 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_fast_down
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 674 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 675 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_up
# 676 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

# 679 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAway:
# 680 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 681 "data/maps/EscapeRoom_Main/scripts.pory"
	face_down
	step_end

# 684 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement2_Nurse1NPC:
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
# 685 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_faster_left
	step_end

EscapeRoom_EventScript_Shop1NPC::
# 691 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 692 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 693 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 694 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 695 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop1_items
# 696 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 697 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 698 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Shop2NPC::
# 702 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 703 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_AskToShop, MSGBOX_DEFAULT
# 705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 706 "data/maps/EscapeRoom_Main/scripts.pory"
	pokemart EscapeRoom_Shop2_items
# 707 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MartNPC_SayGoodbye, MSGBOX_AUTOCLOSE
# 708 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 709 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


	.align 2
# 712 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop1_items:
# 713 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 714 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_FLOAT_STONE
# 715 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_RING_TARGET
# 716 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_NONE

	.align 2
# 719 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Shop2_items:
# 720 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_CUSTAP_BERRY
# 721 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_MENTAL_HERB
# 722 "data/maps/EscapeRoom_Main/scripts.pory"
	.2byte ITEM_TM27
	.2byte ITEM_NONE

EscapeRoom_MoveDeleterNPC::
# 729 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 730 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 731 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDeleteMove, MSGBOX_DEFAULT
# 734 "data/maps/EscapeRoom_Main/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_MoveDeleterNPC_Text_0, EscapeRoom_MoveDeleterNPC_Text_1
# 739 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_MoveDeleterNPC_2
# 743 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_MoveDeleterNPC_3
# 748 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
EscapeRoom_MoveDeleterNPC_1:
# 750 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_MoveDeleterNPC_2:
# 740 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_ChooseMoveToDelete
	goto EscapeRoom_MoveDeleterNPC_1

EscapeRoom_MoveDeleterNPC_3:
# 744 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_RestoreMoveset
	goto EscapeRoom_MoveDeleterNPC_1


EscapeRoom_ChooseMoveToDelete::
# 755 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETE_MONSLOT_BACKUP, 6
# 758 "data/maps/EscapeRoom_Main/scripts.pory"
	special ChoosePartyMon
# 759 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 762 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8004, VAR_MOVE_DELETE_MONSLOT_BACKUP
# 765 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq EscapeRoom_ChooseMoveToDelete_2
# 772 "data/maps/EscapeRoom_Main/scripts.pory"
	special GetNumMovesSelectedMonHas
# 773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_ChooseMoveToDelete_5
# 780 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
	goto_if_eq EscapeRoom_ChooseMoveToDelete_8
# 787 "data/maps/EscapeRoom_Main/scripts.pory"
	backupmonmoveset VAR_0x8004
# 790 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8005, VAR_MOVE_DELETER_CHOSEN_SLOT
# 791 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MOVE_DELETER_CHOSEN_SLOT, MAX_MON_MOVES
# 792 "data/maps/EscapeRoom_Main/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 795 "data/maps/EscapeRoom_Main/scripts.pory"
	special MoveDeleterForgetMove
# 796 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_SUCCESS
# 798 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 799 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterMoveDeleted, MSGBOX_AUTOCLOSE
	end

EscapeRoom_ChooseMoveToDelete_2:
# 766 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 767 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_5:
# 774 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterOnlyOneMove, MSGBOX_AUTOCLOSE
# 775 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_ChooseMoveToDelete_8:
# 781 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MoveDeleterComeAgain, MSGBOX_AUTOCLOSE
# 782 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_RestoreMoveset::
# 805 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TEMP_5
# 808 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_LIEPARD
# 809 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_2
EscapeRoom_RestoreMoveset_1:
# 818 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_AIPOM
# 819 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_5
EscapeRoom_RestoreMoveset_4:
# 828 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_DUNSPARCE
# 829 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_8
EscapeRoom_RestoreMoveset_7:
# 838 "data/maps/EscapeRoom_Main/scripts.pory"
	restoremonmoveset SPECIES_SMEARGLE
# 839 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_RestoreMoveset_11
EscapeRoom_RestoreMoveset_10:
# 848 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TEMP_5, EscapeRoom_RestoreMoveset_13
	return

EscapeRoom_RestoreMoveset_2:
# 810 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 811 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 812 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_LIEPARD_MOVE_DELETED
# 813 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox LiepardMovesRestoredMessage, MSGBOX_DEFAULT
# 814 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_1

EscapeRoom_RestoreMoveset_5:
# 820 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 821 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 822 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_AIPOM_MOVE_DELETED
# 823 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomMovesRestoredMessage, MSGBOX_DEFAULT
# 824 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_4

EscapeRoom_RestoreMoveset_8:
# 830 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 831 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 832 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DUNSPARCE_MOVE_DELETED
# 833 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceMovesRestoredMessage, MSGBOX_DEFAULT
# 834 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_7

EscapeRoom_RestoreMoveset_11:
# 840 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_MoveRestoredSound
# 841 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
# 842 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_SMEARGLE_MOVE_DELETED
# 843 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SmeargleMovesRestoredMessage, MSGBOX_DEFAULT
# 844 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_RestoreMoveset_10

EscapeRoom_RestoreMoveset_13:
# 850 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox NoMovesRestoredMessage, MSGBOX_AUTOCLOSE
# 851 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TEMP_5
	return


EscapeRoom_MoveRestoredSound::
# 857 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 858 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_E
# 859 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 860 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_G
# 861 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 7
# 862 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_NOTE_C_HIGH
# 863 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
	return


EscapeRoom_UltraBallNPC::
# 869 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 870 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_POKE_BALL_OBTAINED, EscapeRoom_UltraBallNPC_2
# 883 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltaBallQuizPostScript, MSGBOX_DEFAULT
EscapeRoom_UltraBallNPC_1:
# 886 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_UltraBallNPC_2:
# 873 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox UltraBallQuizStart, MSGBOX_DEFAULT
# 878 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_ULTRA_BALL
# 879 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_POKE_BALL_OBTAINED
	goto EscapeRoom_UltraBallNPC_1


EscapeRoom_RockSmashNPC::
# 893 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 894 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCstuck, MSGBOX_NPC
# 895 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 896 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, face_npc_up
# 897 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 898 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_MoveRockSmashNPC::
# 905 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 906 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, Common_Movement_ExclamationMark
# 907 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 908 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 911 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesUp
# 912 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 915 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RockSmashNPCFarewellMsg, MSGBOX_AUTOCLOSE
# 916 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 919 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, EscapeRoom_Movement_PlayerMoveAwayFromRock
# 920 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 923 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 25, RockSmashNPCMovesAway
# 924 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 25
# 927 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_EXIT
# 928 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 5
# 929 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 25
# 930 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_HIDE_ROCKSMASH_NPC
# 931 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 933 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ROCKSMASH_TUNNEL_NPC
# 934 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ROCK_SMASH_GUY_MOVED
	return


# 938 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_PlayerMoveAwayFromRock:
# 939 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 940 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_down
# 941 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

# 944 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesUp:
# 945 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_up
# 946 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
	step_end

# 949 "data/maps/EscapeRoom_Main/scripts.pory"
RockSmashNPCMovesAway:
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 950 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 951 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_TryBuySpaceItemNPC::
# 957 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 960 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_SPACE_ITEM_SOLD, EscapeRoom_TryBuySpaceItemNPC_2
# 1003 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SpaceItemNPCPostSellMessage, MSGBOX_NPC
# 1004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_TryBuySpaceItemNPC_1:
# 1006 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TryBuySpaceItemNPC_2:
# 963 "data/maps/EscapeRoom_Main/scripts.pory"
	checkitem ITEM_COMET_SHARD
# 966 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_TryBuySpaceItemNPC_5
# 974 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 975 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SpaceItemNPCInitialMessage_has_item, MSGBOX_YESNO
# 978 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_TryBuySpaceItemNPC_8
# 996 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SpaceItemNPCSellDeclinedMessage, MSGBOX_NPC
# 997 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuySpaceItemNPC_1

EscapeRoom_TryBuySpaceItemNPC_5:
# 968 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SpaceItemNPCInitialMessage_no_item, MSGBOX_NPC
# 969 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuySpaceItemNPC_1

EscapeRoom_TryBuySpaceItemNPC_8:
# 979 "data/maps/EscapeRoom_Main/scripts.pory"
	removeitem ITEM_COMET_SHARD
# 980 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_SPACE_ITEM_SOLD
# 983 "data/maps/EscapeRoom_Main/scripts.pory"
	addmoney 2000
# 984 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 985 "data/maps/EscapeRoom_Main/scripts.pory"
	message MoneyReceived2000
# 986 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 987 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 988 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 991 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SpaceItemNPCSellAcceptedMessage, MSGBOX_NPC
# 992 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_TryBuySpaceItemNPC_1


EscapeRoom_AnnihilapeHintNPC::
# 1013 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1016 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ANNIHILAPE_HINT_RECEIVED, EscapeRoom_AnnihilapeHintNPC_2
# 1044 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1045 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
EscapeRoom_AnnihilapeHintNPC_1:
# 1047 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_AnnihilapeHintNPC_2:
# 1018 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_HIDE_ANNIHILAPE, EscapeRoom_AnnihilapeHintNPC_5
# 1030 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1033 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 1034 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, Common_Movement_ExclamationMark
# 1035 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
# 1036 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 30
# 1038 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintMessage, MSGBOX_NPC
# 1039 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ANNIHILAPE_HINT_RECEIVED
	goto EscapeRoom_AnnihilapeHintNPC_1

EscapeRoom_AnnihilapeHintNPC_5:
# 1019 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage1, MSGBOX_AUTOCLOSE
# 1020 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1021 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 20
# 1022 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1023 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AnnihilapeHintNoMessage2, MSGBOX_AUTOCLOSE
# 1024 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1025 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 31, face_npc_up
# 1026 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 31
	goto EscapeRoom_AnnihilapeHintNPC_1


# 1050 "data/maps/EscapeRoom_Main/scripts.pory"
face_npc_up:
# 1051 "data/maps/EscapeRoom_Main/scripts.pory"
	face_up
	step_end

EscapeRoom_ZeraoraHintNPC::
# 1055 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1056 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1057 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERAORA_CAUGHT, EscapeRoom_ZeraoraHintNPC_2
# 1061 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_WHITE_HERB_OBTAINED, EscapeRoom_ZeraoraHintNPC_5
# 1070 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage3, MSGBOX_DEFAULT
# 1071 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_ZeraoraHintNPC_1:
# 1074 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_ZeraoraHintNPC_2:
# 1058 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintMessage, MSGBOX_DEFAULT
	goto EscapeRoom_ZeraoraHintNPC_1

EscapeRoom_ZeraoraHintNPC_5:
# 1062 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage1, MSGBOX_DEFAULT
# 1063 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1064 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_WHITE_HERB
# 1065 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_WHITE_HERB_OBTAINED
# 1066 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraoraHintPostCatchMessage2, MSGBOX_DEFAULT
# 1067 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_ZeraoraHintNPC_1


EscapeRoom_TabletsHintNPC::
# 1078 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1079 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_TabletsHintNPC_2
# 1082 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_TabletsHintNPC_3
# 1086 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage3, MSGBOX_NPC
EscapeRoom_TabletsHintNPC_1:
# 1088 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_TabletsHintNPC_2:
# 1080 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage1, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1

EscapeRoom_TabletsHintNPC_3:
# 1083 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FourTabletsHintMessage2, MSGBOX_NPC
	goto EscapeRoom_TabletsHintNPC_1


EscapeRoom_DusknoirStoleMyMailNPC::
# 1092 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1093 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DusknoirStoleMyMailMsg, MSGBOX_NPC
# 1094 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Trainer1::
# 1101 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1102 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER1, Trainer1_Intro, Trainer1_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer1PostBattle
# 1111 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_ZERA_TRADED, EscapeRoom_EventScript_Trainer1_1
# 1115 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer1_PostBattle, MSGBOX_AUTOCLOSE
# 1116 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_Trainer1_1:
# 1112 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return


EscapeRoom_EventScript_Trainer2::
# 1121 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER2, Trainer2_Intro, Trainer2_Outro, event_script = EscapeRoom_EventScript_Trainer2PostBattle
# 1127 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer2_PostBattle, MSGBOX_AUTOCLOSE
# 1128 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer3::
# 1133 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1134 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER3, Trainer3_Intro, Trainer3_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer3PostBattle
# 1141 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3_PostBattle, MSGBOX_AUTOCLOSE
# 1142 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer4::
# 1147 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER4, Trainer4_Intro, Trainer4_Outro, event_script = EscapeRoom_EventScript_Trainer4PostBattle
# 1153 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer4_PostBattle, MSGBOX_AUTOCLOSE
# 1154 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer5::
# 1161 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_ASSIST
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5_3
EscapeRoom_EventScript_Trainer5_1:
# 1169 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER5, Trainer5_Intro, Trainer5_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer5PostBattle
# 1176 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_PostBattle, MSGBOX_AUTOCLOSE
# 1177 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end

EscapeRoom_EventScript_Trainer5_2:
# 1163 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1164 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer5_RemoveAssistMessage, MSGBOX_NPC
# 1165 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_Trainer5_3:
# 1162 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_TRAINER5_DEFEATED, EscapeRoom_EventScript_Trainer5_2
	goto EscapeRoom_EventScript_Trainer5_1


EscapeRoom_EventScript_Trainer6::
# 1182 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_single TRAINER_CUSTOM_TRAINER6, Trainer6_Intro, Trainer6_Outro, event_script = EscapeRoom_EventScript_Trainer6PostBattle
# 1189 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer6_PostBattle, MSGBOX_AUTOCLOSE
# 1190 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Trainer9::
# 1195 "data/maps/EscapeRoom_Main/scripts.pory"
	trainerbattle_double TRAINER_CUSTOM_TRAINER9, Trainer9_Intro, Trainer9_Outro, DoubleBattle_NotEnoughMons, event_script = EscapeRoom_EventScript_Trainer9PostBattle
# 1202 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer9_PostBattle, MSGBOX_AUTOCLOSE
# 1203 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_PostMatchHeal::
# 1211 "data/maps/EscapeRoom_Main/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_Trainer1PostBattle::
# 1216 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1219 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_WHITE_HERB
# 1220 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1221 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1222 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer1PostBattle_2
EscapeRoom_EventScript_Trainer1PostBattle_1:
# 1229 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER1_DEFEATED
# 1230 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1231 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_TradeZeraForHMCut
	return

EscapeRoom_EventScript_Trainer1PostBattle_2:
# 1223 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1224 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_WHITE_HERB
	goto_if_eq EscapeRoom_EventScript_Trainer1PostBattle_4
	goto EscapeRoom_EventScript_Trainer1PostBattle_1

EscapeRoom_EventScript_Trainer1PostBattle_4:
# 1225 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer1PostBattle_1


EscapeRoom_EventScript_Trainer2PostBattle::
# 1236 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1239 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_MARANGA
# 1240 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1241 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1242 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer2PostBattle_2
EscapeRoom_EventScript_Trainer2PostBattle_1:
# 1248 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER2_DEFEATED
# 1249 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer2PostBattle_2:
# 1243 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1244 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_MARANGA_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer2PostBattle_4
	goto EscapeRoom_EventScript_Trainer2PostBattle_1

EscapeRoom_EventScript_Trainer2PostBattle_4:
# 1245 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer2PostBattle_1


EscapeRoom_EventScript_Trainer3PostBattle::
# 1254 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1255 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Trainer3FinalWords, MSGBOX_AUTOCLOSE
# 1256 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1257 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement 5, EscapeRoom_Movement_Trainer3End
# 1258 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement 5
# 1259 "data/maps/EscapeRoom_Main/scripts.pory"
	copyobjectxytoperm 5
# 1262 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER3_DEFEATED
# 1265 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_CUSTAP_SOLD_OUT
# 1268 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 1270 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


# 1274 "data/maps/EscapeRoom_Main/scripts.pory"
EscapeRoom_Movement_Trainer3End:
# 1275 "data/maps/EscapeRoom_Main/scripts.pory"
	face_right
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1276 "data/maps/EscapeRoom_Main/scripts.pory"
	walk_right
# 1277 "data/maps/EscapeRoom_Main/scripts.pory"
	face_left
	step_end

EscapeRoom_EventScript_Trainer4PostBattle::
# 1281 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER4_DEFEATED
# 1282 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ETHER_SOLD_OUT
# 1283 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Trainer5PostBattle::
# 1288 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1289 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
# 1292 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_BERRY_JUICE
# 1293 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1294 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1295 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer5PostBattle_2
EscapeRoom_EventScript_Trainer5PostBattle_1:
# 1302 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER5_DEFEATED
# 1303 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer5PostBattle_2:
# 1296 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1297 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_BERRY_JUICE
	goto_if_eq EscapeRoom_EventScript_Trainer5PostBattle_4
	goto EscapeRoom_EventScript_Trainer5PostBattle_1

EscapeRoom_EventScript_Trainer5PostBattle_4:
# 1298 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer5PostBattle_1


EscapeRoom_EventScript_Trainer6PostBattle::
# 1308 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_DO_RECOVERED_ITEM_MESSAGE
# 1309 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_FLUNG_ITEM
# 1312 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_CUSTAP
# 1313 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1314 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1315 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_2
EscapeRoom_EventScript_Trainer6PostBattle_1:
# 1325 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_RECOVERED_GOGGLES
# 1326 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_LIEPARD
# 1327 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1328 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_TEMP_0, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_Trainer6PostBattle_5
EscapeRoom_EventScript_Trainer6PostBattle_4:
# 1335 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER6_DEFEATED
# 1336 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return

EscapeRoom_EventScript_Trainer6PostBattle_2:
# 1316 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1317 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_CUSTAP_BERRY
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_7
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_5:
# 1329 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartyitem VAR_TEMP_0
# 1330 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8005, ITEM_SAFETY_GOGGLES
	goto_if_eq EscapeRoom_EventScript_Trainer6PostBattle_9
	goto EscapeRoom_EventScript_Trainer6PostBattle_4

EscapeRoom_EventScript_Trainer6PostBattle_7:
# 1318 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_1

EscapeRoom_EventScript_Trainer6PostBattle_9:
# 1331 "data/maps/EscapeRoom_Main/scripts.pory"
	removepartyitem VAR_TEMP_0
	goto EscapeRoom_EventScript_Trainer6PostBattle_4


EscapeRoom_EventScript_Trainer9PostBattle::
# 1340 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_TRAINER9_DEFEATED
# 1341 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_TradeZeraForHMCut::
# 1348 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1349 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskZeraCutTradeMessage, MSGBOX_YESNO
# 1350 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_2
# 1370 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeDeclined, MSGBOX_AUTOCLOSE
EscapeRoom_EventScript_TradeZeraForHMCut_1:
# 1372 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeZeraForHMCut_2:
# 1353 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 1354 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeZeraForHMCut_6
# 1363 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_ZERA_TRADED
# 1364 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_ZERAORA
# 1365 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_HM01
# 1366 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox ZeraCutTradeAccepted, MSGBOX_AUTOCLOSE
# 1367 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeZeraForHMCut_1

EscapeRoom_EventScript_TradeZeraForHMCut_6:
# 1356 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1357 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1358 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFerroVsDunsparce::
# 1376 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1377 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1380 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FERRO_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFerroVsDunsparce_2
# 1386 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFerroDunsparceTrade, MSGBOX_YESNO
# 1387 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_5
# 1435 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeDeclined, MSGBOX_AUTOCLOSE
# 1436 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFerroVsDunsparce_1:
# 1439 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_TradeFerroVsDunsparce_2:
# 1381 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradePostTrade, MSGBOX_NPC
# 1382 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_5:
# 1390 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FERROTHORN
# 1391 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFerroVsDunsparce_9
# 1400 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FERROTHORN
# 1401 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_DUNSPARCE, 48, abilityNum = 2, nature = 8, gender = 1, move1 = MOVE_TRUMP_CARD, move2 = MOVE_HEX, move3 = MOVE_ICE_BEAM, move4 = MOVE_NONE, hpEv = 0, defEv = 252, speedEv = 252, hpIv = 0, atkIv = 0, defIv = 31, speedIv = 31, spAtkIv = 0, spDefIv = 31
# 1423 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FERRO_TRADE_ACCEPTED
# 1425 "data/maps/EscapeRoom_Main/scripts.pory"
	message DunsparceReceivedMessage
# 1426 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1427 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1429 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1430 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FerroTradeAccepted, MSGBOX_AUTOCLOSE
# 1431 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFerroVsDunsparce_1

EscapeRoom_EventScript_TradeFerroVsDunsparce_9:
# 1393 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1394 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1395 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeFlorgesForEgg::
# 1444 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1445 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1448 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_FLORGES_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeFlorgesForEgg_2
# 1454 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskFlorgesEggTrade, MSGBOX_YESNO
# 1455 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_5
# 1481 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeDeclined, MSGBOX_AUTOCLOSE
# 1482 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeFlorgesForEgg_1:
# 1485 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeFlorgesForEgg_2:
# 1449 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradePostTrade, MSGBOX_NPC
# 1450 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_5:
# 1458 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_FLORGES
# 1459 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeFlorgesForEgg_9
# 1468 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_FLORGES
# 1469 "data/maps/EscapeRoom_Main/scripts.pory"
	giveaipomegg
# 1470 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_FLORGES_TRADE_ACCEPTED
# 1472 "data/maps/EscapeRoom_Main/scripts.pory"
	message EggReceivedMessage
# 1473 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1474 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1475 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1476 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox FlorgesTradeAccepted, MSGBOX_AUTOCLOSE
# 1477 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeFlorgesForEgg_1

EscapeRoom_EventScript_TradeFlorgesForEgg_9:
# 1461 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1462 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1463 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_SellDunsparce::
# 1489 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1490 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1493 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_DUNSPARCE_TRADE_ACCEPTED, EscapeRoom_EventScript_SellDunsparce_2
# 1499 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceMoneyTrade, MSGBOX_YESNO
# 1500 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_5
# 1522 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradeDeclined, MSGBOX_AUTOCLOSE
# 1523 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SellDunsparce_1:
# 1526 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SellDunsparce_2:
# 1494 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox DunsparceTradePostTrade, MSGBOX_DEFAULT
# 1495 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_5:
# 1503 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_DUNSPARCE
# 1504 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_SellDunsparce_9
# 1513 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_DUNSPARCE
# 1514 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_DUNSPARCE_TRADE_ACCEPTED
# 1516 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskDunsparceReturnAcceptedMessage, MSGBOX_DEFAULT
# 1517 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1518 "data/maps/EscapeRoom_Main/scripts.pory"
	giveitem ITEM_TM12
	goto EscapeRoom_EventScript_SellDunsparce_1

EscapeRoom_EventScript_SellDunsparce_9:
# 1506 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1507 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1508 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_TradeAipomForSmeargle::
# 1530 "data/maps/EscapeRoom_Main/scripts.pory"
	lock
# 1531 "data/maps/EscapeRoom_Main/scripts.pory"
	faceplayer
# 1534 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_AIPOM_TRADE_ACCEPTED, EscapeRoom_EventScript_TradeAipomForSmeargle_2
# 1540 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AskAipomSmeargleTrade, MSGBOX_YESNO
# 1541 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TradeAipomForSmeargle_5
# 1589 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradeDeclined, MSGBOX_AUTOCLOSE
# 1590 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TradeAipomForSmeargle_1:
# 1593 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TradeAipomForSmeargle_2:
# 1535 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradePostTrade, MSGBOX_NPC
# 1536 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomForSmeargle_1

EscapeRoom_EventScript_TradeAipomForSmeargle_5:
# 1544 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_AIPOM
# 1545 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_TradeAipomForSmeargle_9
# 1554 "data/maps/EscapeRoom_Main/scripts.pory"
	removemon SPECIES_AIPOM
# 1555 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1556 "data/maps/EscapeRoom_Main/scripts.pory"
	givemon SPECIES_SMEARGLE, 5, abilityNum = 0, nature = 18, gender = 0, move1 = MOVE_SURF, move2 = MOVE_NONE, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 0, spAtkEv = 0, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1577 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1578 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_AIPOM_TRADE_ACCEPTED
# 1580 "data/maps/EscapeRoom_Main/scripts.pory"
	message SmeargleReceivedMessage
# 1581 "data/maps/EscapeRoom_Main/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 1582 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1583 "data/maps/EscapeRoom_Main/scripts.pory"
	waitfanfare
# 1584 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox AipomTradeAccepted, MSGBOX_AUTOCLOSE
# 1585 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TradeAipomForSmeargle_1

EscapeRoom_EventScript_TradeAipomForSmeargle_9:
# 1547 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox SomethingsGoneWrongMessage, MSGBOX_AUTOCLOSE
# 1548 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1549 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_FindLiepardCollar::
# 1602 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1603 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_POWER_LENS
# 1604 "data/maps/EscapeRoom_Main/scripts.pory"
	removeobject 22
# 1605 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_LIEPARD_COLLAR_OBTAINED
# 1606 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_MapSwitch1::
# 1613 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1616 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch1_2
# 1624 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_5
EscapeRoom_EventScript_MapSwitch1_4:
# 1627 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_8
EscapeRoom_EventScript_MapSwitch1_7:
# 1630 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_11
EscapeRoom_EventScript_MapSwitch1_10:
# 1633 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_14
EscapeRoom_EventScript_MapSwitch1_13:
# 1638 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch1_17
EscapeRoom_EventScript_MapSwitch1_16:
# 1653 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch1_2:
# 1617 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1618 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1619 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch1_5:
# 1625 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_4

EscapeRoom_EventScript_MapSwitch1_8:
# 1628 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_7

EscapeRoom_EventScript_MapSwitch1_11:
# 1631 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_10

EscapeRoom_EventScript_MapSwitch1_14:
# 1634 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet1, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch1_13

EscapeRoom_EventScript_MapSwitch1_17:
# 1639 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1640 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_1, 1
# 1641 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1642 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1645 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch1_20
EscapeRoom_EventScript_MapSwitch1_19:
# 1650 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch1_16

EscapeRoom_EventScript_MapSwitch1_20:
# 1646 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_1, 0
	goto EscapeRoom_EventScript_MapSwitch1_19


EscapeRoom_EventScript_MapSwitch2::
# 1657 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1660 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch2_2
# 1668 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_5
EscapeRoom_EventScript_MapSwitch2_4:
# 1671 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_8
EscapeRoom_EventScript_MapSwitch2_7:
# 1674 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_11
EscapeRoom_EventScript_MapSwitch2_10:
# 1677 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_14
EscapeRoom_EventScript_MapSwitch2_13:
# 1682 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch2_17
EscapeRoom_EventScript_MapSwitch2_16:
# 1696 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch2_2:
# 1661 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1662 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1663 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch2_5:
# 1669 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_4

EscapeRoom_EventScript_MapSwitch2_8:
# 1672 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_7

EscapeRoom_EventScript_MapSwitch2_11:
# 1675 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_10

EscapeRoom_EventScript_MapSwitch2_14:
# 1678 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet2, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch2_13

EscapeRoom_EventScript_MapSwitch2_17:
# 1683 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1684 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_2, 1
# 1685 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1686 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1689 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch2_20
EscapeRoom_EventScript_MapSwitch2_19:
# 1694 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch2_16

EscapeRoom_EventScript_MapSwitch2_20:
# 1690 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_2, 0
	goto EscapeRoom_EventScript_MapSwitch2_19


EscapeRoom_EventScript_MapSwitch3::
# 1700 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1703 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch3_2
# 1711 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_5
EscapeRoom_EventScript_MapSwitch3_4:
# 1714 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_8
EscapeRoom_EventScript_MapSwitch3_7:
# 1717 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_11
EscapeRoom_EventScript_MapSwitch3_10:
# 1720 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_14
EscapeRoom_EventScript_MapSwitch3_13:
# 1725 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch3_17
EscapeRoom_EventScript_MapSwitch3_16:
# 1739 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch3_2:
# 1704 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1705 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1706 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch3_5:
# 1712 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_4

EscapeRoom_EventScript_MapSwitch3_8:
# 1715 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_7

EscapeRoom_EventScript_MapSwitch3_11:
# 1718 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_10

EscapeRoom_EventScript_MapSwitch3_14:
# 1721 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet3, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch3_13

EscapeRoom_EventScript_MapSwitch3_17:
# 1726 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1727 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_3, 1
# 1728 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1729 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1732 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch3_20
EscapeRoom_EventScript_MapSwitch3_19:
# 1737 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch3_16

EscapeRoom_EventScript_MapSwitch3_20:
# 1733 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_3, 0
	goto EscapeRoom_EventScript_MapSwitch3_19


EscapeRoom_EventScript_MapSwitch4::
# 1743 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1746 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_MAP_SWITCHES_SOLVED, EscapeRoom_EventScript_MapSwitch4_2
# 1754 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_MAP_SWITCH_4_FOUND, EscapeRoom_EventScript_MapSwitch4_5
EscapeRoom_EventScript_MapSwitch4_4:
# 1759 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 0
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_8
EscapeRoom_EventScript_MapSwitch4_7:
# 1762 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 1
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_11
EscapeRoom_EventScript_MapSwitch4_10:
# 1765 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 2
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_14
EscapeRoom_EventScript_MapSwitch4_13:
# 1768 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_17
EscapeRoom_EventScript_MapSwitch4_16:
# 1773 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_MapSwitch4_20
EscapeRoom_EventScript_MapSwitch4_19:
# 1787 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_MapSwitch4_2:
# 1747 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MApSwitchesAlreadySolved, MSGBOX_AUTOCLOSE
# 1748 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1749 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_MapSwitch4_5:
# 1755 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCH_4_FOUND
	goto EscapeRoom_EventScript_MapSwitch4_4

EscapeRoom_EventScript_MapSwitch4_8:
# 1760 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedNorthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_7

EscapeRoom_EventScript_MapSwitch4_11:
# 1763 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedEastTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_10

EscapeRoom_EventScript_MapSwitch4_14:
# 1766 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedSouthTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_13

EscapeRoom_EventScript_MapSwitch4_17:
# 1769 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchPointedWestTablet4, MSGBOX_YESNO
	goto EscapeRoom_EventScript_MapSwitch4_16

EscapeRoom_EventScript_MapSwitch4_20:
# 1774 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_CLICK
# 1775 "data/maps/EscapeRoom_Main/scripts.pory"
	addvar VAR_MAP_SWITCH_4, 1
# 1776 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox RotatedSwitchSoundMessage, MSGBOX_AUTOCLOSE
# 1777 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1780 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 4
	goto_if_ge EscapeRoom_EventScript_MapSwitch4_23
EscapeRoom_EventScript_MapSwitch4_22:
# 1785 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_CheckSwitchesCorrect
	goto EscapeRoom_EventScript_MapSwitch4_19

EscapeRoom_EventScript_MapSwitch4_23:
# 1781 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_MAP_SWITCH_4, 0
	goto EscapeRoom_EventScript_MapSwitch4_22


EscapeRoom_EventScript_CheckSwitchesCorrect::
# 1792 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_1, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_3
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_1:
# 1797 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SwitchesOpenDoorSequence
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_2:
# 1794 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_3, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_6
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_3:
# 1793 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_2, 2
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_2
	return

EscapeRoom_EventScript_CheckSwitchesCorrect_6:
# 1795 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_MAP_SWITCH_4, 3
	goto_if_eq EscapeRoom_EventScript_CheckSwitchesCorrect_1
	return


EscapeRoom_EventScript_SwitchesOpenDoorSequence::
# 1802 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 1803 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_TRUCK_MOVE
# 1804 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Long
# 1805 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1806 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1807 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 1808 "data/maps/EscapeRoom_Main/scripts.pory"
	waitstate
# 1809 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_DOOR
# 1810 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 1811 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox MapSwitchDoorOpened, MSGBOX_DEFAULT
# 1812 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 1813 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 1814 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_MAP_SWITCHES_SOLVED
	return


EscapeRoom_EventScript_AnnihilapeBattle::
# 1821 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1824 "data/maps/EscapeRoom_Main/scripts.pory"
	backupplayerparty
# 1827 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_TOGGLE_BAG_USE, EscapeRoom_EventScript_AnnihilapeBattle_2
EscapeRoom_EventScript_AnnihilapeBattle_1:
# 1832 "data/maps/EscapeRoom_Main/scripts.pory"
	createmon side = 1, slot = 0, species = SPECIES_ANNIHILAPE, level = 100, nature = 17, abilityNum = 2, gender = 2, move1 = MOVE_MIMIC hpEv = 12, defEv = 0, spAtkEv = 252, spDefEv = 244, hpIv = 31, atkIv = 31, defIv = 31, speedIv = 31, spAtkIv = 31, spDefIv = 31
# 1855 "data/maps/EscapeRoom_Main/scripts.pory"
	dowildbattle
# 1856 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AnnihilapeBattle_2:
# 1828 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_EventScript_AnnihilapeBattle_1


EscapeRoom_EventScript_GraveStone1::
# 1860 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1861 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1862 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1865 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone1_2
# 1869 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone1_8
EscapeRoom_EventScript_GraveStone1_6:
# 1879 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1880 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1881 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
EscapeRoom_EventScript_GraveStone1_4:
# 1885 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1886 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1889 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone1_2:
	end

EscapeRoom_EventScript_GraveStone1_5:
# 1872 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick1Message, MSGBOX_AUTOCLOSE
# 1873 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1875 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK1
	goto EscapeRoom_EventScript_GraveStone1_4

EscapeRoom_EventScript_GraveStone1_7:
# 1871 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone1_5
	goto EscapeRoom_EventScript_GraveStone1_6

EscapeRoom_EventScript_GraveStone1_8:
# 1870 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone1_7
	goto EscapeRoom_EventScript_GraveStone1_6


EscapeRoom_EventScript_GraveStone2::
# 1893 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1894 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1895 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1898 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone2_2
# 1901 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone2_3
# 1902 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone2_3
# 1903 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone2_3
EscapeRoom_EventScript_GraveStone2_1:
# 1910 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1911 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1912 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1914 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone2_2:
	end

EscapeRoom_EventScript_GraveStone2_3:
# 1905 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1906 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone2_1


EscapeRoom_EventScript_GraveStone3::
# 1918 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1919 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1920 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1923 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone3_2
# 1927 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone3_5
# 1934 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone3_6
# 1935 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone3_6
# 1942 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone3_4:
# 1945 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1946 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1948 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone3_2:
	end

EscapeRoom_EventScript_GraveStone3_5:
# 1929 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick3Message, MSGBOX_AUTOCLOSE
# 1930 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1932 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4

EscapeRoom_EventScript_GraveStone3_6:
# 1937 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1938 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1939 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone3_4


EscapeRoom_EventScript_GraveStone4::
# 1952 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1953 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1954 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1957 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone4_2
# 1960 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone4_3
# 1961 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone4_3
# 1962 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone4_3
EscapeRoom_EventScript_GraveStone4_1:
# 1969 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1970 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1971 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1973 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone4_2:
	end

EscapeRoom_EventScript_GraveStone4_3:
# 1964 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1965 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone4_1


EscapeRoom_EventScript_GraveStone5::
# 1977 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 1978 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 1979 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 1982 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone5_2
# 1985 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone5_3
# 1986 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone5_3
# 1987 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone5_3
EscapeRoom_EventScript_GraveStone5_1:
# 1994 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 1995 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 1996 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 1998 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone5_2:
	end

EscapeRoom_EventScript_GraveStone5_3:
# 1989 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 1990 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone5_1


EscapeRoom_EventScript_GraveStone6::
# 2002 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2003 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2004 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2007 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone6_2
# 2010 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone6_3
# 2011 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone6_3
# 2012 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone6_3
EscapeRoom_EventScript_GraveStone6_1:
# 2019 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2020 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2021 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2023 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone6_2:
	end

EscapeRoom_EventScript_GraveStone6_3:
# 2014 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2015 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone6_1


EscapeRoom_EventScript_GraveStone7::
# 2027 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2028 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2029 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2032 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone7_2
# 2036 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone7_5
# 2043 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone7_6
# 2044 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone7_6
# 2055 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2056 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2057 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
EscapeRoom_EventScript_GraveStone7_4:
# 2059 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone7_2:
	end

EscapeRoom_EventScript_GraveStone7_5:
# 2040 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK4
# 2041 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SpawnAnnihilape
	goto EscapeRoom_EventScript_GraveStone7_4

EscapeRoom_EventScript_GraveStone7_6:
# 2046 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2047 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2049 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2050 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2051 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
	goto EscapeRoom_EventScript_GraveStone7_4


EscapeRoom_EventScript_GraveStone8::
# 2063 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2064 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2065 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2068 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone8_2
# 2072 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone8_5
# 2079 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone8_6
# 2080 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone8_6
# 2087 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
EscapeRoom_EventScript_GraveStone8_4:
# 2090 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2091 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2093 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone8_2:
	end

EscapeRoom_EventScript_GraveStone8_5:
# 2074 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneClick2Message, MSGBOX_AUTOCLOSE
# 2075 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2077 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4

EscapeRoom_EventScript_GraveStone8_6:
# 2082 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2083 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2084 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
	goto EscapeRoom_EventScript_GraveStone8_4


EscapeRoom_EventScript_GraveStone9::
# 2097 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2098 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2099 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2102 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone9_2
# 2105 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone9_3
# 2106 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone9_3
# 2107 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone9_3
EscapeRoom_EventScript_GraveStone9_1:
# 2114 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2115 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2116 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2118 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone9_2:
	end

EscapeRoom_EventScript_GraveStone9_3:
# 2109 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2110 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone9_1


EscapeRoom_EventScript_GraveStone0::
# 2122 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2123 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneNoneMessage, MSGBOX_AUTOCLOSE
# 2124 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2127 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK4, EscapeRoom_EventScript_GraveStone0_2
# 2130 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK1, EscapeRoom_EventScript_GraveStone0_3
# 2131 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK2, EscapeRoom_EventScript_GraveStone0_3
# 2132 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_set FLAG_GRAVESTONE_CHECK3, EscapeRoom_EventScript_GraveStone0_3
EscapeRoom_EventScript_GraveStone0_1:
# 2139 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK1
# 2140 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK2
# 2141 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_GRAVESTONE_CHECK3
# 2143 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_GraveStone0_2:
	end

EscapeRoom_EventScript_GraveStone0_3:
# 2134 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneResetMessage, MSGBOX_AUTOCLOSE
# 2135 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_GraveStone0_1


EscapeRoom_EventScript_SpawnAnnihilape::
# 2147 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2148 "data/maps/EscapeRoom_Main/scripts.pory"
	clearflag FLAG_HIDE_ANNIHILAPE
# 2150 "data/maps/EscapeRoom_Main/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_NORMAL
# 2151 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2152 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2153 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2154 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2155 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2156 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2157 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2159 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GravestoneAnnihilapesRoar, MSGBOX_AUTOCLOSE
# 2160 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmoncry
# 2161 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2162 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
	return


EscapeRoom_EventScript_SafetyGogglesStatue::
# 2166 "data/maps/EscapeRoom_Main/scripts.pory"
	lockall
# 2169 "data/maps/EscapeRoom_Main/scripts.pory"
	goto_if_unset FLAG_GOGGLES_SNATCHED, EscapeRoom_EventScript_SafetyGogglesStatue_2
# 2189 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesAlreadySnatchedMessage, MSGBOX_AUTOCLOSE
# 2190 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
EscapeRoom_EventScript_SafetyGogglesStatue_1:
# 2193 "data/maps/EscapeRoom_Main/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_SafetyGogglesStatue_2:
# 2171 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymove MOVE_SNATCH
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_SafetyGogglesStatue_7
EscapeRoom_EventScript_SafetyGogglesStatue_6:
# 2183 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_Main, MSGBOX_AUTOCLOSE
# 2184 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_5:
# 2175 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox Goggles_Statue_AskSnatch, MSGBOX_YESNO
# 2176 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_10
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1

EscapeRoom_EventScript_SafetyGogglesStatue_7:
# 2172 "data/maps/EscapeRoom_Main/scripts.pory"
	compare VAR_0x8004, SPECIES_ZERAORA
	goto_if_eq EscapeRoom_EventScript_SafetyGogglesStatue_5
	goto EscapeRoom_EventScript_SafetyGogglesStatue_6

EscapeRoom_EventScript_SafetyGogglesStatue_10:
# 2177 "data/maps/EscapeRoom_Main/scripts.pory"
	setflag FLAG_GOGGLES_SNATCHED
# 2178 "data/maps/EscapeRoom_Main/scripts.pory"
	call EscapeRoom_EventScript_SnatchSafetyGoggles
	goto EscapeRoom_EventScript_SafetyGogglesStatue_1


EscapeRoom_EventScript_SnatchSafetyGoggles::
# 2198 "data/maps/EscapeRoom_Main/scripts.pory"
	closemessage
# 2199 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeoutbgm 0
# 2200 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2201 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesSnatchStart, MSGBOX_AUTOCLOSE
# 2202 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2203 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 40
# 2204 "data/maps/EscapeRoom_Main/scripts.pory"
	finditem ITEM_SAFETY_GOGGLES
# 2207 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_PIN
# 2208 "data/maps/EscapeRoom_Main/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 2209 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 2210 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 50
# 2211 "data/maps/EscapeRoom_Main/scripts.pory"
	playse SE_M_SWEET_SCENT
# 2212 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2213 "data/maps/EscapeRoom_Main/scripts.pory"
	delay 10
# 2214 "data/maps/EscapeRoom_Main/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 2215 "data/maps/EscapeRoom_Main/scripts.pory"
	waitse
# 2216 "data/maps/EscapeRoom_Main/scripts.pory"
	msgbox GogglesCurseHappens, MSGBOX_AUTOCLOSE
# 2217 "data/maps/EscapeRoom_Main/scripts.pory"
	waitmessage
# 2218 "data/maps/EscapeRoom_Main/scripts.pory"
	fadeinbgm 0
# 2221 "data/maps/EscapeRoom_Main/scripts.pory"
	checkpartymon SPECIES_ZERAORA
# 2222 "data/maps/EscapeRoom_Main/scripts.pory"
	copyvar VAR_0x8001, VAR_RESULT
# 2223 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8002, MOVE_SNATCH
# 2224 "data/maps/EscapeRoom_Main/scripts.pory"
	setvar VAR_0x8003, MOVE_CURSE
# 2225 "data/maps/EscapeRoom_Main/scripts.pory"
	replacemove VAR_0x8001, VAR_0x8002, VAR_0x8003
	return


EscapeRoom_MoveDeleterNPC_Text_0:
# 735 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Delete a move$"

EscapeRoom_MoveDeleterNPC_Text_1:
# 736 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Restore deleted moves$"

SomethingsGoneWrongMessage::
# 2232 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Something has gone wrong.\p"
	.string "You may have found an unintended\n"
	.string "solution that broke the game.\p"
	.string "Consider contacting Ketchupplant.$"

SignMessage1::
# 2240 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

SignMessageReadInfoAgain::
# 2244 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 2249 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Congratulations, you have\n"
	.string "completed the escape room!$"

EndEscapeRoomSignMessage::
# 2254 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

MysteriousWallSign::
# 2261 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What a weird looking wall.$"

MysteriousWallBackroomSign::
# 2267 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "bliep bloop (TBD)$"

MoveDeleterSignMessage::
# 2271 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "-- Temporary Move Deleter --\p"
	.string "Get rid of your moves and put them\n"
	.string "back whenever you want.\p"
	.string "However, the move deleter cannot be\n"
	.string "used to regain a move's PP.\p"
	.string "A restored move will get:\n"
	.string "a) the PP amount it had when deleted.\l"
	.string "b) 0 PP if all other moves have 0 PP.$"

AnnihilapeStatueMessage::
# 2287 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Primeape, 1837.\p"
	.string "May its restless spirit find peace\n"
	.string "among the shadows.$"

GravestoneNoneMessage::
# 2293 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

GravestoneClick1Message::
# 2297 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A strange energy lingers in the air.$"

GravestoneClick2Message::
# 2301 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The air grows cold.\n"
	.string "You feel a spirit nearby.$"

GravestoneClick3Message::
# 2306 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A deep rumble echoes from below.\n"
	.string "The spirit draws near.$"

GravestoneResetMessage::
# 2311 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The energy dissipates into the void... $"

GravestoneAnnihilapesRoar::
# 2315 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "GRAAAAAHHRGHHH!$"

Goggles_Statue_Main::
# 2319 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "I should probably avoid touching this.\p"
	.string "Perhaps there's a Pokémon who can\n"
	.string "snatch the goggles for me.$"

Goggles_Statue_AskSnatch::
# 2328 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's a pair of goggles attached to\n"
	.string "the gravestone, radiating a strange,\l"
	.string "ominous energy.\p"
	.string "Do you want Zeraora to try and snatch\n"
	.string "the goggles for you?$"

GogglesAlreadySnatchedMessage::
# 2336 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Let's stay away from this gravestone\n"
	.string "from now on...$"

GogglesSnatchStart::
# 2341 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Zeraora carefully detaches the goggles\n"
	.string "from the gravestone.$"

GogglesCurseHappens::
# 2346 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A curse was cast upon Zeraora!\p"
	.string "Something happened to Zeraora's moves.$"

RotatedSwitchSoundMessage::
# 2353 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Clunk.$"

MapSwitchDoorOpened::
# 2357 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What was that???$"

MApSwitchesAlreadySolved::
# 2361 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The tablet is locked in place.$"

MapSwitchPointedNorthTablet1::
# 2366 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet1::
# 2372 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet1::
# 2378 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet1::
# 2384 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 1.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet2::
# 2391 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet2::
# 2397 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet2::
# 2403 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet2::
# 2409 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 2.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet3::
# 2416 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet3::
# 2422 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet3::
# 2428 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet3::
# 2434 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 3.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedNorthTablet4::
# 2441 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed north.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedEastTablet4::
# 2447 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed east.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedSouthTablet4::
# 2453 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed south.\n"
	.string "Do you want to change its direction?$"

MapSwitchPointedWestTablet4::
# 2459 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TABLET 4.\p"
	.string "The tablet is pointed west.\n"
	.string "Do you want to change its direction?$"

Nurse_Ask_heal::
# 2467 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Should I heal your Pokémon?$"

Nurse_Heal_End::
# 2471 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "As good as new!$"

RunningNurseMessage::
# 2475 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've been relocated!$"

HintsIntroMessage::
# 2481 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoHintMessage::
# 2490 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2494 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

AntiSoftlockIntroMessage::
# 2501 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2509 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

UltraBallQuizStart::
# 2516 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "(This will be a quiz at some point)$"

UltaBallQuizPostScript::
# 2520 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Thanks for playing!$"

ZeraoraHintMessage::
# 2526 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Have you seen the Zeraora around here?\p"
	.string "I've seen people try to catch it but no\n"
	.string "one's been able to get its HP below 50%.\p"
	.string "Will you show me your Zeraora if you do\n"
	.string "manage to capture it?\p"
	.string "I've always wanted to see one up close.$"

ZeraoraHintPostCatchMessage1::
# 2535 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, you actually caught the Zeraora!\p"
	.string "I can't believe my eyes!\n"
	.string "You've made a dream come true...\p"
	.string "Here, take this!$"

ZeraoraHintPostCatchMessage2::
# 2543 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's the least I can do.$"

ZeraoraHintPostCatchMessage3::
# 2548 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'll never forget this day.$"

AnnihilapeHintNoMessage1::
# 2554 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "...$"

AnnihilapeHintNoMessage2::
# 2558 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "This place is haunted!$"

AnnihilapeHintMessage::
# 2562 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The Annihilape has returned!?\p"
	.string "Hmm...\p"
	.string "Don't waste your strength trying to\n"
	.string "defeat her.\p"
	.string "She'll always be back.$"

FourTabletsHintMessage1::
# 2572 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you see that strange tablet?\n"
	.string "I'm looking for more of them!\p"
	.string "I wonder what they do.$"

FourTabletsHintMessage2::
# 2584 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wait...\n"
	.string "You actually found all four!?\p"
	.string "I suppose now I can stop looking and\n"
	.string "get back to my regular job.\p"
	.string "Not sure what we're serving today.\n"
	.string "I'll have to go through the menus.$"

FourTabletsHintMessage3::
# 2593 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Was that an earthquake?$"

DusknoirStoleMyMailMsg::
# 2599 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "A Dusknoir stole my mail!\p"
	.string "To be honest, I don't really mind.\n"
	.string "It's just a bit strange.$"

SpaceItemNPCInitialMessage_no_item::
# 2608 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I like to collect rare materials from\n"
	.string "outer space.\p"
	.string "Please come to me if you ever happen\n"
	.string "to find any.$"

SpaceItemNPCInitialMessage_has_item::
# 2615 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I like to collect rare materials from\n"
	.string "outer space.\p"
	.string "Would you sell me your Comet Shard?\n"
	.string "I can offer you ¥2.000.$"

SpaceItemNPCSellAcceptedMessage::
# 2622 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wonderful!$"

SpaceItemNPCSellDeclinedMessage::
# 2626 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ah, maybe next time.$"

SpaceItemNPCPostSellMessage::
# 2630 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Where did you even get this?$"

MoneyReceived2000::
# 2634 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received ¥2.000!$"

LiepardObtainMessage::
# 2644 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Liepard!$"

LiepardNPCmainMessage::
# 2648 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ryaaowr!$"

LiepardCollorFoundMessage::
# 2652 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You give Liepard the collar.$"

NicknameThisPokemonMessage::
# 2656 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do you want to give a nickname to\n"
	.string "this Liepard?$"

RockSmashNPCstuck::
# 2663 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I'm stuck!$"

RockSmashNPCFarewellMsg::
# 2667 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "What took you so long?$"

MartNPC_AskToShop::
# 2672 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Welcome to my shop.\p"
	.string "Don't worry, all items can be sold for\n"
	.string "the same price.$"

MartNPC_SayGoodbye::
# 2678 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "See ya!$"

AskDeleteMove::
# 2684 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hi, what would you like to do?$"

MoveDeleterComeAgain::
# 2690 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Please come again!$"

MoveDeleterMoveDeleted::
# 2694 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{STR_VAR_1}'s {STR_VAR_2} was removed!$"

MoveDeleterOnlyOneMove::
# 2698 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That Pokémon has only one move left.$"

AipomMovesRestoredMessage::
# 2702 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Aipom's moves were restored!$"

LiepardMovesRestoredMessage::
# 2706 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Liepard's moves were restored!$"

DunsparceMovesRestoredMessage::
# 2710 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce's moves were restored!$"

SmeargleMovesRestoredMessage::
# 2714 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Smeargle's moves were restored!$"

NoMovesRestoredMessage::
# 2718 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "There were no moves to restore.$"

NewBallMessage::
# 2724 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You recover the ball.$"

HeldItemRecoveredMessage::
# 2728 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your held items were restored.$"

AskResetPredamageMessage::
# 2734 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to set your Pokémon's HP and move\n"
	.string "PP back to their pre-battle state?$"

PreDamagedStateRestoredMessage::
# 2739 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Your team's state was restored.$"

AskFerroDunsparceTrade::
# 2745 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I've found a Dunsparce on the beach.\p"
	.string "Wanna trade it for your Ferrothorn?$"

DunsparceReceivedMessage::
# 2750 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Dunsparce!$"

FerroTradeAccepted::
# 2754 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Ferrothorn.$"

FerroTradeDeclined::
# 2758 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Some other time perhaps.$"

FerroTradePostTrade::
# 2762 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I love this Ferrothorn!$"

AskFlorgesEggTrade::
# 2768 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's a nice Florges.\p"
	.string "Do you want to trade it for a mystery\n"
	.string "egg?$"

EggReceivedMessage::
# 2774 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received an EGG!$"

FlorgesTradeAccepted::
# 2778 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Florges.$"

FlorgesTradeDeclined::
# 2782 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Okay, come back anytime.$"

FlorgesTradePostTrade::
# 2786 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I sense regret?$"

AskDunsparceMoneyTrade::
# 2792 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Dunsparce and I were playing near the\n"
	.string "water when she went missing.\p"
	.string "Have you seen my Dunsparce?$"

AskDunsparceReturnAcceptedMessage::
# 2798 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Omg you found her!!\p"
	.string "Thank you so much!\n"
	.string "Here, have this.$"

DunsparceTradeDeclined::
# 2804 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Hmm...$"

DunsparceTradePostTrade::
# 2808 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "It's so good to be back together!$"

AskAipomSmeargleTrade::
# 2814 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (start trade)$"

SmeargleReceivedMessage::
# 2818 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "{PLAYER} received a Smeargle!$"

AipomTradeAccepted::
# 2822 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Aipom.$"

AipomTradeDeclined::
# 2826 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Ahh, that's too bad!$"

AipomTradePostTrade::
# 2830 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD (post trade)$"

DoubleBattle_NotEnoughMons::
# 2836 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Trainer1_Intro::
# 2843 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Sharing is caring.\n"
	.string "Can you see the appeal?\p"
	.string "Win the fight and we may have a deal.$"

Trainer1_Outro::
# 2849 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer1_PostBattle::
# 2853 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

AskZeraCutTradeMessage::
# 2857 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Wow, that Zeraora of yours is amazing.\n"
	.string "I wish I had a Pokémon like that!\p"
	.string "Would you be okay trading your Zeraora\n"
	.string "for my HM Cut?$"

ZeraCutTradeDeclined::
# 2864 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Come back if you change your mind.$"

ZeraCutTradeAccepted::
# 2868 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Bye-bye Zeraora.$"

Trainer2_Intro::
# 2874 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "The land may hide its fiercest face,\n"
	.string "beneath the calm of leafy grace.$"

Trainer2_Outro::
# 2881 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer2_PostBattle::
# 2885 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3_Intro::
# 2891 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Rage is nearly guaranteed.\n"
	.string "Try and realize getting entry takeswork.$"

Trainer3_Outro::
# 2896 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer3_PostBattle::
# 2900 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer3FinalWords::
# 2904 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Entry granted.$"

Trainer4_Intro::
# 2910 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "I feel exhausted already.$"

Trainer4_Outro::
# 2914 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer4_PostBattle::
# 2918 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_Intro::
# 2924 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "That's more like it.\n"
	.string "Let's see how much you're worth!$"

Trainer5_Outro::
# 2929 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Did you have enough?$"

Trainer5_PostBattle::
# 2933 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer5_RemoveAssistMessage::
# 2937 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Do I look like I need your assistance?\n"
	.string "Try again when that move is gone.$"

Trainer6_Intro::
# 2944 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "My carrier birds are amazing!\n"
	.string "They always find their way back.\p"
	.string "This one might've just come back from\n"
	.string "the moon though...$"

Trainer6_Outro::
# 2951 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer6_PostBattle::
# 2955 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"

Trainer9_Intro::
# 2961 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "TBD$"

Trainer9_Outro::
# 2965 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "You cheated.$"

Trainer9_PostBattle::
# 2969 "data/maps/EscapeRoom_Main/scripts.pory"
	.string "Fock off.$"
