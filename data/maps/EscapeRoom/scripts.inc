EscapeRoom_MapScripts::
# 5 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EscapeRoom_MapScript_OnTransitionScripts
# 6 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, EscapeRoom_MapScript_OnResumeScripts
# 8 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
# 12 "data/maps/EscapeRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
# 9 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_WARP_COUNTER, 0, EscapeRoom_MapScript_OnWarpIntoScripts
	.2byte 0

EscapeRoom_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
# 13 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 0, EscapeRoom_MapScripts_PlayStartMessage
# 14 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1, EscapeRoom_MapScripts_GetFirstPokemon
# 15 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2, EscapeRoom_MapScripts_GetBadges
# 16 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3, EscapeRoom_MapScripts_SetRespawn
# 17 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4, EscapeRoom_MapScripts_GetItems
# 18 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5, EscapeRoom_MapScripts_TurnOfBagUse
# 19 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6, EscapeRoom_MapScripts_FixCrackedGround
# 20 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
# 21 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1, EscapeRoom_MapScripts_FindGreatBallAferUse
# 22 "data/maps/EscapeRoom/scripts.pory"
	map_script_2 VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1, EscapeRoom_MapScripts_FindPechaBerryAferUse
	.2byte 0


EscapeRoom_MapScript_OnTransitionScripts::
# 28 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_KeepDouble1Moved
# 29 "data/maps/EscapeRoom/scripts.pory"
	call CaveHole_FixCrackedGround
	return


EscapeRoom_MapScript_OnResumeScripts::
# 34 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_SetHoleWarp
# 37 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckIfMonCaught
# 40 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TM_10_STOLEN, EscapeRoom_MapScript_OnResumeScripts_2
EscapeRoom_MapScript_OnResumeScripts_1:
# 44 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 47 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattlePecha
# 50 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleHeal
# 53 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_CheckHintFlags
# 56 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_4
	return

EscapeRoom_MapScript_OnResumeScripts_2:
# 41 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkTM10stolen
	goto EscapeRoom_MapScript_OnResumeScripts_1

EscapeRoom_MapScript_OnResumeScripts_4:
# 57 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
# 63 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_setNPCfacing
# 66 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkHMRockSmash
# 69 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	return


EscapeRoom_MapScript_CheckHintFlags::
# 74 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 75 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_2
EscapeRoom_MapScript_CheckHintFlags_1:
# 78 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 79 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_PECHA_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_5
EscapeRoom_MapScript_CheckHintFlags_4:
# 82 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 83 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_PECHA_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_8
EscapeRoom_MapScript_CheckHintFlags_7:
# 88 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_GREAT_BALL
# 89 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_11
EscapeRoom_MapScript_CheckHintFlags_10:
# 92 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 93 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_GREAT_BALL
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_14
EscapeRoom_MapScript_CheckHintFlags_13:
# 98 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY
# 99 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_17
EscapeRoom_MapScript_CheckHintFlags_16:
# 102 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 103 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_SITRUS_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_20
EscapeRoom_MapScript_CheckHintFlags_19:
# 106 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 107 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_SITRUS_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_22
	return

EscapeRoom_MapScript_CheckHintFlags_2:
# 76 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_1

EscapeRoom_MapScript_CheckHintFlags_5:
# 80 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_4

EscapeRoom_MapScript_CheckHintFlags_8:
# 84 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_7

EscapeRoom_MapScript_CheckHintFlags_11:
# 90 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GREAT_BALL_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_10

EscapeRoom_MapScript_CheckHintFlags_14:
# 94 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GREAT_BALL_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_13

EscapeRoom_MapScript_CheckHintFlags_17:
# 100 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	goto EscapeRoom_MapScript_CheckHintFlags_16

EscapeRoom_MapScript_CheckHintFlags_20:
# 104 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	goto EscapeRoom_MapScript_CheckHintFlags_19

EscapeRoom_MapScript_CheckHintFlags_22:
# 108 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	return


EscapeRoom_MapScript_checkTM10stolen::
# 113 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_TM10
# 114 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_checkTM10stolen_2
EscapeRoom_MapScript_checkTM10stolen_1:
# 117 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 118 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_TM10
	goto_if_eq EscapeRoom_MapScript_checkTM10stolen_4
	return

EscapeRoom_MapScript_checkTM10stolen_2:
# 115 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TM_10_STOLEN
	goto EscapeRoom_MapScript_checkTM10stolen_1

EscapeRoom_MapScript_checkTM10stolen_4:
# 119 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TM_10_STOLEN
	return


EscapeRoom_MapScript_checkHMRockSmash::
# 124 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HM_ROCK_SMASH_STOLEN, EscapeRoom_MapScript_checkHMRockSmash_1
	return

EscapeRoom_MapScript_checkHMRockSmash_1:
# 125 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HM06_STEAL_SUCCES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 131 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 132 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_2
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 133 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_2:
# 132 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, EscapeRoom_MapScripts_CheckAfterBattleHeal_1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 138 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 139 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 140 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 145 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1:
# 147 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2:
# 145 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 153 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_CheckAfterBattlePecha_2
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_1:
# 155 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 156 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattlePecha_5
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_2:
# 153 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattlePecha_1
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_5:
# 158 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 159 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_CheckAfterBattlePecha_7
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_7:
# 161 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 168 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 169 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 170 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 171 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 172 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 173 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 174 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 175 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 176 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 180 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 181 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 182 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 183 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 184 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 185 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 186 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 190 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 191 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 195 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 196 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 200 "data/maps/EscapeRoom/scripts.pory"
	turnobject 8, DIR_SOUTH
# 201 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_EAST
# 202 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 203 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_SOUTH
# 204 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 205 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 206 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_EAST
# 207 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 211 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 212 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 12
# 213 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 11
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 218 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 220 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 221 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 225 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, gender = 0, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_SUNNY_DAY, move4 = MOVE_NONE, hpEv = 8, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 0, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 248 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 249 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 253 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 254 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 255 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 256 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 257 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 258 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 259 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 260 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 261 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 262 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 263 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 264 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 265 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 266 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 267 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 268 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 270 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 275 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 276 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 280 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HM04
# 281 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 282 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 286 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 289 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 287 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 296 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 297 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 298 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TestSign_2
EscapeRoom_EventScript_TestSign_1:
# 303 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TestSign_2:
# 300 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 301 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TestSign_1


EscapeRoom_Nurse_Heal_Pokemon::
# 307 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 308 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 309 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 310 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 311 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 312 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 313 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 314 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 315 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 319 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 320 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 321 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 322 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 323 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 327 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 328 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 329 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 330 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 331 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 335 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 336 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 337 "data/maps/EscapeRoom/scripts.pory"
	removeobject 6
# 338 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 339 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 343 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 344 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 345 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 353 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 354 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 363 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 364 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 365 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 368 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 369 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 374 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 375 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 376 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 381 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 390 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 398 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 401 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 346 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 347 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 348 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 355 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 356 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 357 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 366 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 365 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 370 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 369 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 377 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 382 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 383 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 384 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 385 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 381 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 391 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 392 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 393 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 390 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 399 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 407 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 438 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 408 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 409 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 5, gender = 1, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 431 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 432 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 433 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 434 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 435 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GARDEVOIR_TRADE_SUCCESS
	return


EscapeRoom_EventScript_SingleBattle1::
# 443 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_Single1PostMatch
# 449 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 450 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 455 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_Single2PostMatch
# 461 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 462 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 467 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 468 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_Single3PostMatch
# 474 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_SingleBattle4::
# 479 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 480 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE2_BYPASSED
# 481 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE4, Single4IntroMessage, Single4OutroMessage, event_script = EscapeRoom_EventScript_SetSingle4Rematch
	return


EscapeRoom_EventScript_Single1PostMatch::
# 490 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_ROEL_DEFEATED
# 491 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single2PostMatch::
# 495 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DS_ABEL_DEFEATED
# 496 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single3PostMatch::
# 500 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 501 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_Single3PostMatch_1
	return

EscapeRoom_EventScript_Single3PostMatch_1:
# 502 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_SetSingle4Rematch::
# 507 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE4
# 508 "data/maps/EscapeRoom/scripts.pory"
	msgbox single4PostMatchMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TeleportBackOverLedge::
# 512 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 513 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_YESNO
# 514 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_2
# 579 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 580 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 582 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 516 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 517 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 520 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 523 "data/maps/EscapeRoom/scripts.pory"
	removemoney 99999
# 526 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 529 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 530 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_6
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 537 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 538 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_9
EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 545 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_TeleportBackOverLedge_12
# 559 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HM06
# 560 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 573 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_HM_ROCK_SMASH_STOLEN
# 576 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 531 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 532 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 533 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 539 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 540 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 541 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_8

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 547 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 548 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_16
EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 551 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 552 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 555 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HM06
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 549 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_15

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 561 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 562 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_24
EscapeRoom_EventScript_TeleportBackOverLedge_23:
# 565 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 566 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 553 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20

EscapeRoom_EventScript_TeleportBackOverLedge_24:
# 563 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_23

EscapeRoom_EventScript_TeleportBackOverLedge_26:
# 567 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11


EscapeRoom_EventScript_DoubleBattle1::
# 586 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 594 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 595 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_DoubleBattle2::
# 600 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE2, Double2IntroMessage, Double2OutroMessage, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 607 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double2PostMatchMessage, MSGBOX_AUTOCLOSE
# 608 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 613 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 614 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 615 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 616 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 617 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 618 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 619 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 620 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 621 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 622 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 623 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 627 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 628 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 628 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 628 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 629 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 633 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 637 "data/maps/EscapeRoom/scripts.pory"
	lock
# 638 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 639 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 640 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 641 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 642 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 643 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 647 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 648 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 652 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 653 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 654 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 657 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 663 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 742 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 744 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 745 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 777 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 778 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 781 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 658 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 659 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 660 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 665 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 666 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 670 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 672 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 673 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 737 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 738 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 663 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 657 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 667 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 666 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 746 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 747 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 750 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 771 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 772 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 676 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 677 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 678 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 732 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 733 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 751 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 752 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 753 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 754 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 757 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 763 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 764 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 765 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 766 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 681 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 682 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 683 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 686 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 702 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 703 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 706 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 707 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 708 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 709 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 712 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 727 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 728 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 758 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 759 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 687 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 688 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 691 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 694 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 713 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 714 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 717 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 718 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 719 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 723 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 689 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 692 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 695 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 696 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 697 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_QuietTurnNPC::
# 786 "data/maps/EscapeRoom/scripts.pory"
	msgbox QuietTurnNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 790 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 794 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_GetUsOutNPC::
# 798 "data/maps/EscapeRoom/scripts.pory"
	msgbox GetUsOutNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 802 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_NUGGET3_OBTAINED, EscapeRoom_EventScript_NuggetNPC_1
# 806 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage2, MSGBOX_NPC
	return

EscapeRoom_EventScript_NuggetNPC_1:
# 803 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 811 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 815 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 819 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 823 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 827 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 828 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 835 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 836 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 838 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_CalcHintsUsed
# 839 "data/maps/EscapeRoom/scripts.pory"
	bufferplaytimeandhints
# 840 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 841 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 842 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 829 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 830 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 831 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 832 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_CalcHintsUsed::
# 846 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 847 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GREAT_BALL, EscapeRoom_EventScript_CalcHintsUsed_2
EscapeRoom_EventScript_CalcHintsUsed_1:
# 850 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_NUGGET, EscapeRoom_EventScript_CalcHintsUsed_5
EscapeRoom_EventScript_CalcHintsUsed_4:
# 853 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_8
EscapeRoom_EventScript_CalcHintsUsed_7:
# 856 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_11
EscapeRoom_EventScript_CalcHintsUsed_10:
# 859 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENTS_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_14
EscapeRoom_EventScript_CalcHintsUsed_13:
# 862 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_CATCHING_SMEARGLE, EscapeRoom_EventScript_CalcHintsUsed_17
EscapeRoom_EventScript_CalcHintsUsed_16:
# 865 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROSE_UN, EscapeRoom_EventScript_CalcHintsUsed_20
EscapeRoom_EventScript_CalcHintsUsed_19:
# 868 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_DS_ABEL, EscapeRoom_EventScript_CalcHintsUsed_23
EscapeRoom_EventScript_CalcHintsUsed_22:
# 871 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROEL, EscapeRoom_EventScript_CalcHintsUsed_26
EscapeRoom_EventScript_CalcHintsUsed_25:
# 874 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_C_TRISH, EscapeRoom_EventScript_CalcHintsUsed_29
EscapeRoom_EventScript_CalcHintsUsed_28:
# 877 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_PEE_SEA, EscapeRoom_EventScript_CalcHintsUsed_32
EscapeRoom_EventScript_CalcHintsUsed_31:
# 880 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_JAN_NAN, EscapeRoom_EventScript_CalcHintsUsed_35
EscapeRoom_EventScript_CalcHintsUsed_34:
# 884 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SALAZZLE, EscapeRoom_EventScript_CalcHintsUsed_38
EscapeRoom_EventScript_CalcHintsUsed_37:
# 887 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ROSE_UN, EscapeRoom_EventScript_CalcHintsUsed_41
EscapeRoom_EventScript_CalcHintsUsed_40:
# 890 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PC_CHECK, EscapeRoom_EventScript_CalcHintsUsed_44
EscapeRoom_EventScript_CalcHintsUsed_43:
# 893 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE2, EscapeRoom_EventScript_CalcHintsUsed_47
EscapeRoom_EventScript_CalcHintsUsed_46:
# 896 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE2, EscapeRoom_EventScript_CalcHintsUsed_50
EscapeRoom_EventScript_CalcHintsUsed_49:
# 899 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SMEARGLE_CATCH, EscapeRoom_EventScript_CalcHintsUsed_53
EscapeRoom_EventScript_CalcHintsUsed_52:
# 902 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_DS_ABEL, EscapeRoom_EventScript_CalcHintsUsed_56
EscapeRoom_EventScript_CalcHintsUsed_55:
# 905 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_CalcHintsUsed_59
EscapeRoom_EventScript_CalcHintsUsed_58:
# 908 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GET_HEART_SCALE, EscapeRoom_EventScript_CalcHintsUsed_62
EscapeRoom_EventScript_CalcHintsUsed_61:
# 911 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENT_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_65
EscapeRoom_EventScript_CalcHintsUsed_64:
# 914 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_ROEL, EscapeRoom_EventScript_CalcHintsUsed_68
EscapeRoom_EventScript_CalcHintsUsed_67:
# 917 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PEE_SEA, EscapeRoom_EventScript_CalcHintsUsed_71
EscapeRoom_EventScript_CalcHintsUsed_70:
# 920 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STEAL_SITRUS, EscapeRoom_EventScript_CalcHintsUsed_74
EscapeRoom_EventScript_CalcHintsUsed_73:
# 923 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_JAN_NAN, EscapeRoom_EventScript_CalcHintsUsed_76
	return

EscapeRoom_EventScript_CalcHintsUsed_2:
# 848 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_1

EscapeRoom_EventScript_CalcHintsUsed_5:
# 851 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_4

EscapeRoom_EventScript_CalcHintsUsed_8:
# 854 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_7

EscapeRoom_EventScript_CalcHintsUsed_11:
# 857 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_10

EscapeRoom_EventScript_CalcHintsUsed_14:
# 860 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_13

EscapeRoom_EventScript_CalcHintsUsed_17:
# 863 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_16

EscapeRoom_EventScript_CalcHintsUsed_20:
# 866 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_19

EscapeRoom_EventScript_CalcHintsUsed_23:
# 869 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_22

EscapeRoom_EventScript_CalcHintsUsed_26:
# 872 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_25

EscapeRoom_EventScript_CalcHintsUsed_29:
# 875 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_28

EscapeRoom_EventScript_CalcHintsUsed_32:
# 878 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_31

EscapeRoom_EventScript_CalcHintsUsed_35:
# 881 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_34

EscapeRoom_EventScript_CalcHintsUsed_38:
# 885 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_37

EscapeRoom_EventScript_CalcHintsUsed_41:
# 888 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_40

EscapeRoom_EventScript_CalcHintsUsed_44:
# 891 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_43

EscapeRoom_EventScript_CalcHintsUsed_47:
# 894 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_46

EscapeRoom_EventScript_CalcHintsUsed_50:
# 897 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_49

EscapeRoom_EventScript_CalcHintsUsed_53:
# 900 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_52

EscapeRoom_EventScript_CalcHintsUsed_56:
# 903 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_55

EscapeRoom_EventScript_CalcHintsUsed_59:
# 906 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_58

EscapeRoom_EventScript_CalcHintsUsed_62:
# 909 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_61

EscapeRoom_EventScript_CalcHintsUsed_65:
# 912 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_64

EscapeRoom_EventScript_CalcHintsUsed_68:
# 915 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_67

EscapeRoom_EventScript_CalcHintsUsed_71:
# 918 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_70

EscapeRoom_EventScript_CalcHintsUsed_74:
# 921 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_73

EscapeRoom_EventScript_CalcHintsUsed_76:
# 924 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	return


EscapeRoom_EventScript_FindIronBall::
# 929 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 930 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 931 "data/maps/EscapeRoom/scripts.pory"
	removeobject 15
# 932 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 933 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 937 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 938 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 939 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 940 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 941 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_PressStartSign::
# 945 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 946 "data/maps/EscapeRoom/scripts.pory"
	msgbox PressStartSignMessage
# 947 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 948 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_ExitCloseNPC::
# 952 "data/maps/EscapeRoom/scripts.pory"
	msgbox ExitCloseNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PainSplitHintNPC::
# 956 "data/maps/EscapeRoom/scripts.pory"
	msgbox PainSplitHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_BerryTreeHintNPC::
# 960 "data/maps/EscapeRoom/scripts.pory"
	msgbox BerryTreeHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TormentHintNPC::
# 964 "data/maps/EscapeRoom/scripts.pory"
	msgbox TormentHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_SketchHintNPC::
# 968 "data/maps/EscapeRoom/scripts.pory"
	msgbox SketchHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_Question1Sign::
# 972 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 973 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question1Message
# 974 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 975 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question2Sign::
# 979 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 980 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question2Message
# 981 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 982 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question3Sign::
# 986 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 987 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question3Message
# 988 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 989 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question4Sign::
# 993 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 994 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question4Message
# 995 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 996 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTFSign::
# 1000 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1001 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTFSign_Text_0
# 1002 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1003 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTFSign::
# 1007 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1008 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTFSign_Text_0
# 1009 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1010 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFFSign::
# 1014 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1015 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFFSign_Text_0
# 1016 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1017 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTFSign::
# 1021 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1022 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTFSign_Text_0
# 1023 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1024 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFFFSign::
# 1028 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1029 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFFFSign_Text_0
# 1030 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1031 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFFSign::
# 1035 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1036 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFFSign_Text_0
# 1037 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1038 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTTSign::
# 1042 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1043 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTTSign_Text_0
# 1044 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1045 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTTSign::
# 1049 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1050 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTTSign_Text_0
# 1051 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1052 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFTTSign::
# 1056 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1057 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFTTSign_Text_0
# 1058 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1059 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFTSign::
# 1063 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1064 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFTSign_Text_0
# 1065 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1066 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTTSign::
# 1070 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1071 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTTSign_Text_0
# 1072 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1073 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFTSign::
# 1077 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1078 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFTSign_Text_0
# 1079 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1080 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1084 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 1085 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1089 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_POKEMON_CAUGHT, EscapeRoom_EventScript_AntiSoftlockGuy_2
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1100 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_RARE_CANDY_USED, EscapeRoom_EventScript_AntiSoftlockGuy_5
EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1123 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1124 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_11
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1156 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 1157 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 1158 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1091 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_7
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_5:
# 1101 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1104 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 1105 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_15
EscapeRoom_EventScript_AntiSoftlockGuy_14:
# 1109 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonlevel 31
# 1110 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_20
EscapeRoom_EventScript_AntiSoftlockGuy_19:
# 1114 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
# 1114 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
	goto EscapeRoom_EventScript_AntiSoftlockGuy_4

EscapeRoom_EventScript_AntiSoftlockGuy_7:
# 1092 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSmeargleCatch
# 1093 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1125 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1128 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 1129 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_17
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_11:
# 1124 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_10
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_15:
# 1106 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_AntiSoftlockGuy_14

EscapeRoom_EventScript_AntiSoftlockGuy_17:
# 1132 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonmoves VAR_TEMP_0
# 1133 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_22
# 1143 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_23
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_20:
# 1111 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto EscapeRoom_EventScript_AntiSoftlockGuy_19

EscapeRoom_EventScript_AntiSoftlockGuy_22:
# 1136 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_30
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_23:
# 1146 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_32
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_26:
# 1115 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
# 1116 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_30:
# 1137 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch1
# 1138 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_32:
# 1147 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch2
# 1148 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_UndoSmeargleCatch::
# 1162 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskReleaseSmeargleMessage, MSGBOX_YESNO
# 1165 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_1
# 1220 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1221 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_1:
# 1168 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1169 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_5
# 1177 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 1178 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_8
EscapeRoom_EventScript_UndoSmeargleCatch_7:
# 1183 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 1184 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_UndoSmeargleCatch_10
# 1190 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 1191 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 1192 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 1195 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1196 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 1197 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_14
EscapeRoom_EventScript_UndoSmeargleCatch_13:
# 1201 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 1202 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8005, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_17
EscapeRoom_EventScript_UndoSmeargleCatch_16:
# 1208 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_20
EscapeRoom_EventScript_UndoSmeargleCatch_19:
# 1213 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 1214 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 1215 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_5:
# 1170 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseBringSmeargleMessage, MSGBOX_AUTOCLOSE
# 1171 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1172 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_UndoSmeargleCatch_8:
# 1179 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 1180 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_7

EscapeRoom_EventScript_UndoSmeargleCatch_10:
# 1185 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 1186 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_14:
# 1198 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1199 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_UndoSmeargleCatch_13

EscapeRoom_EventScript_UndoSmeargleCatch_17:
# 1203 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1204 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoSmeargleCatch_16

EscapeRoom_EventScript_UndoSmeargleCatch_20:
# 1209 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 1210 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_19


EscapeRoom_EventScript_UndoRareCandy::
# 1226 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoRareCandyMessage, MSGBOX_YESNO
# 1229 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_1
# 1241 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1242 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1230 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_5
# 1233 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_6
EscapeRoom_EventScript_UndoRareCandy_4:
# 1236 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_RARE_CANDY_USED
# 1237 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
	return

EscapeRoom_EventScript_UndoRareCandy_5:
# 1231 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_SMEARGLE
	goto EscapeRoom_EventScript_UndoRareCandy_4

EscapeRoom_EventScript_UndoRareCandy_6:
# 1234 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_GARDEVOIR
	goto EscapeRoom_EventScript_UndoRareCandy_4


EscapeRoom_EventScript_UndoSketch1::
# 1247 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1250 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch1_1
# 1265 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1266 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch1_1:
# 1251 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1252 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1254 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1255 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1259 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1260 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1261 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return


EscapeRoom_EventScript_UndoSketch2::
# 1271 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1274 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_1
# 1296 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1297 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch2_1:
# 1276 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1277 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1280 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_PROTECT
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_5
EscapeRoom_EventScript_UndoSketch2_4:
# 1285 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1286 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1290 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1291 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1292 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return

EscapeRoom_EventScript_UndoSketch2_5:
# 1281 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 1282 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_UndoSketch2_4


EscapeRoom_EventScript_HintsNPC::
# 1302 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 1303 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1304 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 1305 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 1310 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 1312 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1306 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
# 1307 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_HintsNPC_part2::
# 1316 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_EventScript_HintsNPC_part2_Text_0, EscapeRoom_EventScript_HintsNPC_part2_Text_1
# 1320 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_1
# 1323 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_2
# 1327 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
	return

EscapeRoom_EventScript_HintsNPC_part2_1:
# 1321 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_WhereToLookHint
	return

EscapeRoom_EventScript_HintsNPC_part2_2:
# 1324 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_SpecificStepHint
	return


EscapeRoom_EventScript_SpecificStepHint::
# 1332 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 2, FALSE, 5, 0, 0, EscapeRoom_EventScript_SpecificStepHint_Text_0, EscapeRoom_EventScript_SpecificStepHint_Text_1, EscapeRoom_EventScript_SpecificStepHint_Text_2, EscapeRoom_EventScript_SpecificStepHint_Text_3, EscapeRoom_EventScript_SpecificStepHint_Text_4, EscapeRoom_EventScript_SpecificStepHint_Text_5, EscapeRoom_EventScript_SpecificStepHint_Text_6, EscapeRoom_EventScript_SpecificStepHint_Text_7, EscapeRoom_EventScript_SpecificStepHint_Text_8, EscapeRoom_EventScript_SpecificStepHint_Text_9, EscapeRoom_EventScript_SpecificStepHint_Text_10, EscapeRoom_EventScript_SpecificStepHint_Text_11
# 1347 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1349 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_2
# 1356 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_3
# 1363 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_4
# 1370 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_5
# 1377 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_6
# 1384 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_7
# 1391 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_8
# 1398 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_9
# 1405 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_10
# 1412 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_11
# 1419 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_12
# 1426 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_13
# 1434 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
# 1435 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
EscapeRoom_EventScript_SpecificStepHint_1:
# 1439 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_28
# 1443 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_29
EscapeRoom_EventScript_SpecificStepHint_27:
# 1449 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
	return

EscapeRoom_EventScript_SpecificStepHint_2:
# 1350 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_GreatBall
# 1351 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GREAT_BALL, EscapeRoom_EventScript_SpecificStepHint_33
EscapeRoom_EventScript_SpecificStepHint_32:
# 1354 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_GREAT_BALL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_3:
# 1357 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_Nugget
# 1358 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_NUGGET, EscapeRoom_EventScript_SpecificStepHint_36
EscapeRoom_EventScript_SpecificStepHint_35:
# 1361 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_NUGGET
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_4:
# 1364 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_IcePuzzle
# 1365 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_39
EscapeRoom_EventScript_SpecificStepHint_38:
# 1368 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ICE_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_5:
# 1371 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StrengthPuzzle
# 1372 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_42
EscapeRoom_EventScript_SpecificStepHint_41:
# 1375 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STRENGTH_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_6:
# 1378 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StatementsPuzzle
# 1379 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENTS_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_45
EscapeRoom_EventScript_SpecificStepHint_44:
# 1382 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STATEMENTS_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_7:
# 1385 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_CatchingSmeargle
# 1386 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_CATCHING_SMEARGLE, EscapeRoom_EventScript_SpecificStepHint_48
EscapeRoom_EventScript_SpecificStepHint_47:
# 1389 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_CATCHING_SMEARGLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_8:
# 1392 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoseUn
# 1393 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROSE_UN, EscapeRoom_EventScript_SpecificStepHint_51
EscapeRoom_EventScript_SpecificStepHint_50:
# 1396 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROSE_UN
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_9:
# 1399 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerDSAbel
# 1400 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_DS_ABEL, EscapeRoom_EventScript_SpecificStepHint_54
EscapeRoom_EventScript_SpecificStepHint_53:
# 1403 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_DS_ABEL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_10:
# 1406 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoel
# 1407 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROEL, EscapeRoom_EventScript_SpecificStepHint_57
EscapeRoom_EventScript_SpecificStepHint_56:
# 1410 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROEL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_11:
# 1413 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerCTrish
# 1414 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_C_TRISH, EscapeRoom_EventScript_SpecificStepHint_60
EscapeRoom_EventScript_SpecificStepHint_59:
# 1417 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_C_TRISH
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_12:
# 1420 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersPeeSea
# 1421 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_PEE_SEA, EscapeRoom_EventScript_SpecificStepHint_63
EscapeRoom_EventScript_SpecificStepHint_62:
# 1424 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_PEE_SEA
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_13:
# 1427 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersJanNan
# 1428 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_JAN_NAN, EscapeRoom_EventScript_SpecificStepHint_66
EscapeRoom_EventScript_SpecificStepHint_65:
# 1431 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_JAN_NAN
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_28:
# 1440 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoTimeAddedMessage
# 1441 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SpecificStepHint_27

EscapeRoom_EventScript_SpecificStepHint_29:
# 1444 "data/maps/EscapeRoom/scripts.pory"
	addgametime 20
# 1445 "data/maps/EscapeRoom/scripts.pory"
	playse SE_SHOP
# 1446 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC20minAddedMessage
# 1447 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SpecificStepHint_27

EscapeRoom_EventScript_SpecificStepHint_33:
# 1352 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_32

EscapeRoom_EventScript_SpecificStepHint_36:
# 1359 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_35

EscapeRoom_EventScript_SpecificStepHint_39:
# 1366 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_38

EscapeRoom_EventScript_SpecificStepHint_42:
# 1373 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_41

EscapeRoom_EventScript_SpecificStepHint_45:
# 1380 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_44

EscapeRoom_EventScript_SpecificStepHint_48:
# 1387 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_47

EscapeRoom_EventScript_SpecificStepHint_51:
# 1394 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_50

EscapeRoom_EventScript_SpecificStepHint_54:
# 1401 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_53

EscapeRoom_EventScript_SpecificStepHint_57:
# 1408 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_56

EscapeRoom_EventScript_SpecificStepHint_60:
# 1415 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_59

EscapeRoom_EventScript_SpecificStepHint_63:
# 1422 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_62

EscapeRoom_EventScript_SpecificStepHint_66:
# 1429 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_65


EscapeRoom_EventScript_WhereToLookHint::
# 1453 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1455 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TM_10_STOLEN, EscapeRoom_EventScript_WhereToLookHint_2
# 1462 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_WhereToLookHint_3
# 1469 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GREAT_BALL_FOUND, EscapeRoom_EventScript_WhereToLookHint_4
# 1476 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_PECHA_BERRY_FOUND, EscapeRoom_EventScript_WhereToLookHint_5
# 1483 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_6
# 1490 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_WhereToLookHint_7
# 1497 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_WhereToLookHint_8
# 1504 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_NUGGET3_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_9
# 1511 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HEART_SCALE2_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_10
# 1518 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_11
# 1525 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_WhereToLookHint_12
# 1532 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DOUBLE2_BYPASSED, EscapeRoom_EventScript_WhereToLookHint_13
# 1539 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_SITRUS_STOLEN, EscapeRoom_EventScript_WhereToLookHint_14
# 1546 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DOUBLE1_COMPLETED, EscapeRoom_EventScript_WhereToLookHint_15
# 1554 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoNothingUrDone
# 1555 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1556 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_WhereToLookHint_1:
# 1561 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_WhereToLookHint_32
# 1566 "data/maps/EscapeRoom/scripts.pory"
	addgametime 10
# 1567 "data/maps/EscapeRoom/scripts.pory"
	playse SE_SHOP
# 1568 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC10minAddedMessage
# 1569 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_WhereToLookHint_31:
# 1571 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
	return

EscapeRoom_EventScript_WhereToLookHint_2:
# 1456 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoSalazzleThief
# 1457 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SALAZZLE, EscapeRoom_EventScript_WhereToLookHint_36
EscapeRoom_EventScript_WhereToLookHint_35:
# 1460 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_SALAZZLE
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_3:
# 1463 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoRoseUn
# 1464 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ROSE_UN, EscapeRoom_EventScript_WhereToLookHint_39
EscapeRoom_EventScript_WhereToLookHint_38:
# 1467 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ROSE_UN
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_4:
# 1470 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoPCCheck
# 1471 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PC_CHECK, EscapeRoom_EventScript_WhereToLookHint_42
EscapeRoom_EventScript_WhereToLookHint_41:
# 1474 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PC_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_5:
# 1477 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoIcePuzzle
# 1478 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE2, EscapeRoom_EventScript_WhereToLookHint_45
EscapeRoom_EventScript_WhereToLookHint_44:
# 1481 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ICE_PUZZLE2
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_6:
# 1484 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStrengthPuzzle
# 1485 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE2, EscapeRoom_EventScript_WhereToLookHint_48
EscapeRoom_EventScript_WhereToLookHint_47:
# 1488 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STRENGTH_PUZZLE2
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_7:
# 1491 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoSmeargleCatch
# 1492 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SMEARGLE_CATCH, EscapeRoom_EventScript_WhereToLookHint_51
EscapeRoom_EventScript_WhereToLookHint_50:
# 1495 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_SMEARGLE_CATCH
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_8:
# 1498 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoDSAbel
# 1499 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_DS_ABEL, EscapeRoom_EventScript_WhereToLookHint_54
EscapeRoom_EventScript_WhereToLookHint_53:
# 1502 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_DS_ABEL
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_9:
# 1505 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoPlantCheck
# 1506 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_WhereToLookHint_57
EscapeRoom_EventScript_WhereToLookHint_56:
# 1509 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PLANT_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_10:
# 1512 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoGetHeartScale
# 1513 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_WhereToLookHint_60
EscapeRoom_EventScript_WhereToLookHint_59:
# 1516 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PLANT_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_11:
# 1519 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStatementPuzzle
# 1520 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENT_PUZZLE, EscapeRoom_EventScript_WhereToLookHint_63
EscapeRoom_EventScript_WhereToLookHint_62:
# 1523 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STATEMENT_PUZZLE
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_12:
# 1526 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoBeatRoel
# 1527 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_ROEL, EscapeRoom_EventScript_WhereToLookHint_66
EscapeRoom_EventScript_WhereToLookHint_65:
# 1530 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_BEAT_ROEL
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_13:
# 1533 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoGePastPeeSea
# 1534 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PEE_SEA, EscapeRoom_EventScript_WhereToLookHint_69
EscapeRoom_EventScript_WhereToLookHint_68:
# 1537 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PEE_SEA
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_14:
# 1540 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStealSitrus
# 1541 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STEAL_SITRUS, EscapeRoom_EventScript_WhereToLookHint_72
EscapeRoom_EventScript_WhereToLookHint_71:
# 1544 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STEAL_SITRUS
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_15:
# 1547 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoBeatJanNan
# 1548 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_JAN_NAN, EscapeRoom_EventScript_WhereToLookHint_75
EscapeRoom_EventScript_WhereToLookHint_74:
# 1551 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_BEAT_JAN_NAN
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_32:
# 1562 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoTimeAddedMessage
# 1563 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_WhereToLookHint_31

EscapeRoom_EventScript_WhereToLookHint_36:
# 1458 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_35

EscapeRoom_EventScript_WhereToLookHint_39:
# 1465 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_38

EscapeRoom_EventScript_WhereToLookHint_42:
# 1472 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_41

EscapeRoom_EventScript_WhereToLookHint_45:
# 1479 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_44

EscapeRoom_EventScript_WhereToLookHint_48:
# 1486 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_47

EscapeRoom_EventScript_WhereToLookHint_51:
# 1493 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_50

EscapeRoom_EventScript_WhereToLookHint_54:
# 1500 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_53

EscapeRoom_EventScript_WhereToLookHint_57:
# 1507 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_56

EscapeRoom_EventScript_WhereToLookHint_60:
# 1514 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_59

EscapeRoom_EventScript_WhereToLookHint_63:
# 1521 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_62

EscapeRoom_EventScript_WhereToLookHint_66:
# 1528 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_65

EscapeRoom_EventScript_WhereToLookHint_69:
# 1535 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_68

EscapeRoom_EventScript_WhereToLookHint_72:
# 1542 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_71

EscapeRoom_EventScript_WhereToLookHint_75:
# 1549 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_74


EscapeRoom_EventScript_IceMapSign::
# 1575 "data/maps/EscapeRoom/scripts.pory"
	lock
# 1576 "data/maps/EscapeRoom/scripts.pory"
	showicemap
# 1577 "data/maps/EscapeRoom/scripts.pory"
	waitbuttonpress
# 1578 "data/maps/EscapeRoom/scripts.pory"
	hideicemap
# 1579 "data/maps/EscapeRoom/scripts.pory"
	release
	return


EscapeRoom_EventScript_FFTFSign_Text_0:
# 1001 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTF$"

EscapeRoom_EventScript_TTTFSign_Text_0:
# 1008 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTF$"

EscapeRoom_EventScript_TTFFSign_Text_0:
# 1015 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFF$"

EscapeRoom_EventScript_FTTFSign_Text_0:
# 1022 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTF$"

EscapeRoom_EventScript_TFFFSign_Text_0:
# 1029 "data/maps/EscapeRoom/scripts.pory"
	.string "TFFF$"

EscapeRoom_EventScript_FFFFSign_Text_0:
# 1036 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFF$"

EscapeRoom_EventScript_TTTTSign_Text_0:
# 1043 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTT$"

EscapeRoom_EventScript_FTTTSign_Text_0:
# 1050 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTT$"

EscapeRoom_EventScript_TFTTSign_Text_0:
# 1057 "data/maps/EscapeRoom/scripts.pory"
	.string "TFTT$"

EscapeRoom_EventScript_TTFTSign_Text_0:
# 1064 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFT$"

EscapeRoom_EventScript_FFTTSign_Text_0:
# 1071 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTT$"

EscapeRoom_EventScript_FFFTSign_Text_0:
# 1078 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFT$"

EscapeRoom_EventScript_HintsNPC_part2_Text_0:
# 1317 "data/maps/EscapeRoom/scripts.pory"
	.string "Where should I look now? (10 min.)$"

EscapeRoom_EventScript_HintsNPC_part2_Text_1:
# 1318 "data/maps/EscapeRoom/scripts.pory"
	.string "Hint for a specific step. (20 min.)$"

EscapeRoom_EventScript_SpecificStepHint_Text_0:
# 1333 "data/maps/EscapeRoom/scripts.pory"
	.string "Getting the Great Ball$"

EscapeRoom_EventScript_SpecificStepHint_Text_1:
# 1334 "data/maps/EscapeRoom/scripts.pory"
	.string "Getting the Nugget$"

EscapeRoom_EventScript_SpecificStepHint_Text_2:
# 1335 "data/maps/EscapeRoom/scripts.pory"
	.string "Ice Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_3:
# 1336 "data/maps/EscapeRoom/scripts.pory"
	.string "Strength Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_4:
# 1337 "data/maps/EscapeRoom/scripts.pory"
	.string "Statements Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_5:
# 1338 "data/maps/EscapeRoom/scripts.pory"
	.string "Catching the perfect Smeargle$"

EscapeRoom_EventScript_SpecificStepHint_Text_6:
# 1339 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Rose Un (Kecleon)$"

EscapeRoom_EventScript_SpecificStepHint_Text_7:
# 1340 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: DS. Abel (Slaking)$"

EscapeRoom_EventScript_SpecificStepHint_Text_8:
# 1341 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Roel (Togedemaru)$"

EscapeRoom_EventScript_SpecificStepHint_Text_9:
# 1342 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: C. Trish (Klefki)$"

EscapeRoom_EventScript_SpecificStepHint_Text_10:
# 1343 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Pee & Sea (Urshifu, Urshifu)$"

EscapeRoom_EventScript_SpecificStepHint_Text_11:
# 1344 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Jan & Nan (Smeargle, Scrafty)$"

StartMessage::
# 1585 "data/maps/EscapeRoom/scripts.pory"
	.string "$"

SignMessage1::
# 1589 "data/maps/EscapeRoom/scripts.pory"
	.string "1) The game's learnsets and battle\n"
	.string "mechanics are based on GEN 9.\p"
	.string "2) Match tiebreakers will follow\n"
	.string "competitive battling rules.\l"
	.string "This means you could potentially win\l"
	.string "despite losing your final Pokémon.\p"
	.string "3) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "4) There is no need for grinding of any\n"
	.string "kind. You don't earn EXP from battles.\p"
	.string "5) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "6) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "7) You won't get softlocked unless you\n"
	.string "toss away items, release Pokémon, or\l"
	.string "REALLY mess up the Strength puzzle.\p"
	.string "8) Try to avoid using speed up.\n"
	.string "You might miss important details like\l"
	.string "NPC dialogue.$"

SignMessageReadInfoAgain::
# 1620 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 1625 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 1630 "data/maps/EscapeRoom/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 1637 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 1642 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "There's one path we cannot stop.\n"
	.string "Can you figure it out?$"

Double1Puzzle_Outro::
# 1651 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 1656 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 1660 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 1664 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 1668 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one???\p"
	.string "Just seeing one would make me so happy\n"
	.string "I might give you my GARDEVOIR.$"

SmeargleMessageBad::
# 1677 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that moveset looks horrible.\n"
	.string "I asked for the perfect SMEARGLE!\p"
	.string "You should probably have a chat with\n"
	.string "the anti-softlock guy.$"

TakeFlameOrbMessage::
# 1684 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it anywhere)$"

SmeargleReleaseHealSecondMonMessage::
# 1689 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseBringSmeargleMessage::
# 1693 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back with the SMEARGLE in\n"
	.string "your party.$"

SmeargleReleaseGetSecondMonMessage::
# 1697 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 1701 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleMessagePerfect::
# 1705 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 1714 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 1723 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 1727 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 1731 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 1735 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 1740 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 1750 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 1757 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single2Puzzle_Intro::
# 1761 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1767 "data/maps/EscapeRoom/scripts.pory"
	.string "Shut up and take my money.$"

Single3Puzzle_Intro::
# 1771 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to quit.$"

Single3Puzzle_Outro::
# 1776 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1780 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way\l"
	.string "they were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1789 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1795 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1799 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1805 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1809 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1816 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1820 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1824 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1829 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1835 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1841 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1846 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1850 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1855 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

QuietTurnNPCMessage::
# 1859 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "one quiet turn could set you free.$"

NuggetNPCmessage::
# 1864 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET???\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

NuggetNPCmessage2::
# 1870 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you've found my NUGGET!\p"
	.string "You can keep it.\n"
	.string "I didn't need it anyway.$"

GetUsOutNPCMessage::
# 1876 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

SalazzleCatchingHint::
# 1880 "data/maps/EscapeRoom/scripts.pory"
	.string "Every time I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "It's just mocking me at this point.$"

someoneLockedUsUpNPCmessage::
# 1887 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1893 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing, right?$"

icePuzzleHintNPCmessage::
# 1898 "data/maps/EscapeRoom/scripts.pory"
	.string "That ice puzzle looks tough!\n"
	.string "Don't expect to finish it right away.$"

StopWinningNPCmessage::
# 1903 "data/maps/EscapeRoom/scripts.pory"
	.string "Just give up!$"

NewGreatBallMessage::
# 1907 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1911 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1916 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1921 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"

PressStartSignMessage::
# 1925 "data/maps/EscapeRoom/scripts.pory"
	.string "Press START during a double battle to\n"
	.string "view your POKéMON's exact HP.$"

Single4IntroMessage::
# 1930 "data/maps/EscapeRoom/scripts.pory"
	.string "Oops, I picked the last berries.\n"
	.string "Why don't you come and take them?$"

Single4OutroMessage::
# 1935 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you really win?$"

single4PostMatchMessage::
# 1939 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm ready for a rematch whenever you\n"
	.string "want!$"

Single2Puzzle_PostBattle::
# 1944 "data/maps/EscapeRoom/scripts.pory"
	.string "CURSOLA is a great singer, don't you\n"
	.string "agree?\p"
	.string "Maybe SMEARGLE should follow her lead.$"

Single1Puzzle_PostBattle::
# 1950 "data/maps/EscapeRoom/scripts.pory"
	.string "...$"

ExitCloseNPCMessage::
# 1954 "data/maps/EscapeRoom/scripts.pory"
	.string "We're so close, the exit is right there!$"

PainSplitHintNPCMessage::
# 1958 "data/maps/EscapeRoom/scripts.pory"
	.string "Time is not for sale, but generosity can\n"
	.string "earn you a moment.\p"
	.string "Sharing is caring.$"

BerryTreeHintNPCMessage::
# 1964 "data/maps/EscapeRoom/scripts.pory"
	.string "What happened to that berry tree?\p"
	.string "Such a shame, it could have been so\n"
	.string "useful against the old timers.$"

TormentHintNPCMessage::
# 1970 "data/maps/EscapeRoom/scripts.pory"
	.string "I used to get tormented by my brothers.\p"
	.string "I tried to avoid it at first, but after a\n"
	.string "while you just accept it and play along.$"

SketchHintNPCMessage::
# 1976 "data/maps/EscapeRoom/scripts.pory"
	.string "You can learn so much by copying those\n"
	.string "with experience.$"

Question1Message::
# 1980 "data/maps/EscapeRoom/scripts.pory"
	.string "1. Exactly one of statement 2 and 4 is\n"
	.string "false.$"

Question2Message::
# 1984 "data/maps/EscapeRoom/scripts.pory"
	.string "2. Both statements 1 and 3 are true.$"

Question3Message::
# 1988 "data/maps/EscapeRoom/scripts.pory"
	.string "3. At least two statements are false.$"

Question4Message::
# 1992 "data/maps/EscapeRoom/scripts.pory"
	.string "4. GARDEVOIR must use DISABLE to beat\n"
	.string "Expert Roel.$"

AntiSoftlockIntroMessage::
# 1997 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2005 "data/maps/EscapeRoom/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

AntiSoftlockDeclinedMessage::
# 2010 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright.$"

AskReleaseSmeargleMessage::
# 2014 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Catching a 'wrong' SMEARGLE could leave\n"
	.string "you softlocked.\p"
	.string "Should I release this SMEARGLE and give\n"
	.string "back your GREAT BALL?$"

UndoRareCandyMessage::
# 2022 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Giving the RARE CANDY to the wrong\n"
	.string "POKéMON could leave you softlocked.\p"
	.string "Should I undo the level-up and give back\n"
	.string "your RARE CANDY?$"

UndoSketchMessage::
# 2030 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Sketching the wrong move with SMEARGLE\n"
	.string "could leave you softlocked.\p"
	.string "Should I revert your latest SKETCH?$"

SmeargleForgotMove::
# 2037 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle forgot its latest move...$"

SmeargleLearnedSketch::
# 2041 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle learned Sketch!$"

Double2IntroMessage::
# 2045 "data/maps/EscapeRoom/scripts.pory"
	.string "We really appreciate your out-of-the-\n"
	.string "box approach.$"

Double2OutroMessage::
# 2050 "data/maps/EscapeRoom/scripts.pory"
	.string "Ehhh... What.$"

Double2PostMatchMessage::
# 2054 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you were supposed to win\n"
	.string "this battle.$"

HintsIntroMessage::
# 2061 "data/maps/EscapeRoom/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoTimeAddedMessage::
# 2070 "data/maps/EscapeRoom/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPC20minAddedMessage::
# 2075 "data/maps/EscapeRoom/scripts.pory"
	.string "20 minutes were added to your clock.$"

HintsNPC10minAddedMessage::
# 2079 "data/maps/EscapeRoom/scripts.pory"
	.string "10 minutes were added to your clock.$"

HintsNPCNoHintMessage::
# 2086 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2090 "data/maps/EscapeRoom/scripts.pory"
	.string "What kind of hint would you like?$"

HintsNPC_GreatBall::
# 2094 "data/maps/EscapeRoom/scripts.pory"
	.string "This item is accessible from the start.\p"
	.string "You should further explore the room\n"
	.string "with the plants.$"

HintsNPC_Nugget::
# 2100 "data/maps/EscapeRoom/scripts.pory"
	.string "It's inside an item ball, but the ball\n"
	.string "itself may be hard to see.\p"
	.string "Did the NUGGET guy mention leafs?$"

HintsNPC_IcePuzzle::
# 2106 "data/maps/EscapeRoom/scripts.pory"
	.string "At the beginning, only the berry tree is\n"
	.string "accessible. The item ball is unreachable\l"
	.string "until the MACH BIKE is obtained.\p"
	.string "Have you checked your trainer card?$"

HintsNPC_StrengthPuzzle::
# 2113 "data/maps/EscapeRoom/scripts.pory"
	.string "The puzzle revolves around breaking the\n"
	.string "ROCK SMASH rocks in the correct order.\p"
	.string "1. Break the two center rocks.\p"
	.string "2. Break the two rocks south-west.\p"
	.string "3. Break the last rock on the east.\p"
	.string "Think about how you want to access this\n"
	.string "last smashable rock on the east.$"

HintsNPC_StatementsPuzzle::
# 2123 "data/maps/EscapeRoom/scripts.pory"
	.string "When solving the four statements, you'll\n"
	.string "find that the 4th statement must be\l"
	.string "false in order to get a valid solution.\p"
	.string "First four moves after dropping:\n"
	.string "Left, down, right, down.$"

HintsNPC_CatchingSmeargle::
# 2131 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE will have the move\n"
	.string "SKETCH, which only has 1pp.\p"
	.string "If you stall a turn by not attacking,\n"
	.string "SMEARGLE will no longer be able to copy\l"
	.string "the wrong move.\p"
	.string "Consider visiting SALAZZLE first.\n"
	.string "Did you already use the TOXIC ORB?$"

HintsNPC_TrainerRoseUn::
# 2141 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to find a way to take the item\n"
	.string "without winning the battle.\p"
	.string "In other words: try to avoid taking the\n"
	.string "FINAL GAMBIT from ZANGOOSE.\p"
	.string "Keep in mind that HIDDEN POWER's typing\n"
	.string "may depend on the POKéMON using it.\p"
	.string "Just give up.$"

HintsNPC_TrainerDSAbel::
# 2151 "data/maps/EscapeRoom/scripts.pory"
	.string "PROTECT SMEARGLE and the right move on\n"
	.string "GARDEVOIR will get you past SLAKING.\p"
	.string "However, CURSOLA will need to be given a\n"
	.string "hindering ability to slow it down.\l"
	.string "Are you a skill trader?\p"
	.string "You may have to stall a turn to get the\n"
	.string "timing right.$"

HintsNPC_TrainerRoel::
# 2161 "data/maps/EscapeRoom/scripts.pory"
	.string "To beat Roel's last POKéMON, SMEARGLE\n"
	.string "must first SKETCH the correct move.\l"
	.string "Explore the old couple to see what\l"
	.string "moves their POKéMON are hiding.\p"
	.string "Also, there exists a clever way to\n"
	.string "control the TOGEDEMARU's HP, which will\l"
	.string "help align the TRICK ROOM turns.\p"
	.string "...\p"
	.string "Good luck!$"

HintsNPC_TrainerCTrish::
# 2173 "data/maps/EscapeRoom/scripts.pory"
	.string "Can you steal her SITRUS BERRY?\p"
	.string "SKILL SWAP is your friend, and perhaps\n"
	.string "there's a way to render DOUBLE-EDGE\l"
	.string "completely useless.\p"
	.string "Two ways actually.\p"
	.string "Does one involve DESTINY BOND?$"

HintsNPC_TrainersPeeSea::
# 2182 "data/maps/EscapeRoom/scripts.pory"
	.string "This battle looks impossible to win.\n"
	.string "Can you find a way to skip this battle?\p"
	.string "Try thinking inside the box.$"

HintsNPC_TrainersJanNan::
# 2188 "data/maps/EscapeRoom/scripts.pory"
	.string "PAIN SPLIT can be used against your own\n"
	.string "POKéMON, and SCRAFTY's ability can be\l"
	.string "turned against itself.\p"
	.string "Try to set TRICK ROOM at the start, and\n"
	.string "don't forget the PERISH tiebreaker.\p"
	.string "Is there an item you haven't used yet?$"

HintsNPC_DoSalazzleThief::
# 2197 "data/maps/EscapeRoom/scripts.pory"
	.string "Check out the SALAZZLE in the cave\n"
	.string "below!$"

HintsNPC_DoRoseUn::
# 2202 "data/maps/EscapeRoom/scripts.pory"
	.string "You should battle Rose Un, the KECLEON\n"
	.string "trainer.\p"
	.string "There may be something you can get from\n"
	.string "that fight.$"

HintsNPC_DoPCCheck::
# 2209 "data/maps/EscapeRoom/scripts.pory"
	.string "You should have a good look at the PC in\n"
	.string "the plants room!$"

HintsNPC_DoIcePuzzle::
# 2214 "data/maps/EscapeRoom/scripts.pory"
	.string "There's a berry tree in the ice puzzle.\n"
	.string "It might be a useful item when trying to\l"
	.string "catch the perfect SMEARGLE.$"

HintsNPC_DoStrengthPuzzle::
# 2220 "data/maps/EscapeRoom/scripts.pory"
	.string "The STRENGTH puzzle in the Tiny Cave\n"
	.string "down south is still unsolved.\p"
	.string "It could be worth trying.$"

HintsNPC_DoSmeargleCatch::
# 2226 "data/maps/EscapeRoom/scripts.pory"
	.string "You are ready to catch the perfect\n"
	.string "SMEARGLE.\p"
	.string "Talk to the person in the plants room to\n"
	.string "validate your catch.\p"
	.string "Think about which move your SMEARGLE\n"
	.string "should carry in the end.$"

HintsNPC_DoDSAbel::
# 2235 "data/maps/EscapeRoom/scripts.pory"
	.string "You should look to beat DS. Abel, the\n"
	.string "SLAKING trainer.\p"
	.string "Find the right movesets for SMEARGLE\n"
	.string "and GARDEVOIR to do so.$"

HintsNPC_DoPlantCheck::
# 2242 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you checked the plants room?\p"
	.string "There might be another item hidden\n"
	.string "somewhere around that room.$"

HintsNPC_DoGetHeartScale::
# 2248 "data/maps/EscapeRoom/scripts.pory"
	.string "There's a bike obstacle near DS. ABEL,\n"
	.string "the Slaking trainer you just defeated.\p"
	.string "Did you already get the bike?$"

HintsNPC_DoStatementPuzzle::
# 2254 "data/maps/EscapeRoom/scripts.pory"
	.string "You can solve the statements puzzle!\p"
	.string "It could help you reach the item ball in\n"
	.string "the cave below us.$"

HintsNPC_DoBeatRoel::
# 2260 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to get past trainer Roel.\n"
	.string "To do so, SMEARGLE must first SKETCH\l"
	.string "the right move.\p"
	.string "Did you find what the old couple's\n"
	.string "POKéMON are hiding?$"

HintsNPC_DoGePastPeeSea::
# 2268 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to find a way to get past the\n"
	.string "Pee & Sea double battle.$"

HintsNPC_DoStealSitrus::
# 2273 "data/maps/EscapeRoom/scripts.pory"
	.string "C. Trish's SCORBUNNY has a berry that'd\n"
	.string "be quite helpful in the final battle.\p"
	.string "Can you steal it?$"

HintsNPC_DoBeatJanNan::
# 2279 "data/maps/EscapeRoom/scripts.pory"
	.string "You are ready for the final battle!\p"
	.string "Can GARDEVOIR keep SMEARGLE alive for\n"
	.string "long enough?$"

HintsNPC_DoNothingUrDone::
# 2285 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you need any additional\n"
	.string "hints.$"
