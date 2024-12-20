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
	call EscapeRoom_MapScripts_CheckAfterBattleGreatBall
# 43 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattlePecha
# 46 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScripts_CheckAfterBattleHeal
# 49 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_CheckHintFlags
# 52 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScript_OnResumeScripts_1
	return

EscapeRoom_MapScript_OnResumeScripts_1:
# 53 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	return


EscapeRoom_MapScript_OnWarpIntoScripts::
# 59 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_setNPCfacing
# 62 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_MapScript_checkHMRockSmash
# 65 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_DONT_REMOVE_OFFSCREEN_OBJECT
	return


EscapeRoom_MapScript_CheckHintFlags::
# 70 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 71 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_2
EscapeRoom_MapScript_CheckHintFlags_1:
# 74 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 75 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_5
EscapeRoom_MapScript_CheckHintFlags_4:
# 78 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 79 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_8
EscapeRoom_MapScript_CheckHintFlags_7:
# 84 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_GREAT_BALL
# 85 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_11
EscapeRoom_MapScript_CheckHintFlags_10:
# 88 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 89 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_GREAT_BALL
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_14
EscapeRoom_MapScript_CheckHintFlags_13:
# 94 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_SITRUS_BERRY
# 95 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_17
EscapeRoom_MapScript_CheckHintFlags_16:
# 98 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 99 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_SITRUS_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_20
EscapeRoom_MapScript_CheckHintFlags_19:
# 102 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 103 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_SITRUS_BERRY
	goto_if_eq EscapeRoom_MapScript_CheckHintFlags_22
	return

EscapeRoom_MapScript_CheckHintFlags_2:
# 72 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_1

EscapeRoom_MapScript_CheckHintFlags_5:
# 76 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_4

EscapeRoom_MapScript_CheckHintFlags_8:
# 80 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_PECHA_BERRY_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_7

EscapeRoom_MapScript_CheckHintFlags_11:
# 86 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GREAT_BALL_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_10

EscapeRoom_MapScript_CheckHintFlags_14:
# 90 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GREAT_BALL_FOUND
	goto EscapeRoom_MapScript_CheckHintFlags_13

EscapeRoom_MapScript_CheckHintFlags_17:
# 96 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	goto EscapeRoom_MapScript_CheckHintFlags_16

EscapeRoom_MapScript_CheckHintFlags_20:
# 100 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	goto EscapeRoom_MapScript_CheckHintFlags_19

EscapeRoom_MapScript_CheckHintFlags_22:
# 104 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SITRUS_STOLEN
	return


EscapeRoom_MapScript_checkHMRockSmash::
# 109 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HM_ROCK_SMASH_STOLEN, EscapeRoom_MapScript_checkHMRockSmash_1
	return

EscapeRoom_MapScript_checkHMRockSmash_1:
# 110 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HM06_STEAL_SUCCES
	return


EscapeRoom_MapScripts_CheckAfterBattleHeal::
# 116 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 117 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattleHeal_2
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_1:
# 118 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_HEAL_IF_ALL_FAINTED, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleHeal_2:
# 117 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_SYS_POKEMON_GET, EscapeRoom_MapScripts_CheckAfterBattleHeal_1
	return


EscapeRoom_MapScripts_CheckIfMonCaught::
# 123 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 124 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_ge EscapeRoom_MapScripts_CheckIfMonCaught_1
	return

EscapeRoom_MapScripts_CheckIfMonCaught_1:
# 125 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_POKEMON_CAUGHT
	return


EscapeRoom_MapScripts_CheckAfterBattleGreatBall::
# 130 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GREAT_BALL_USED, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1:
# 132 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 1
	return

EscapeRoom_MapScripts_CheckAfterBattleGreatBall_2:
# 130 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattleGreatBall_1
	return


EscapeRoom_MapScripts_CheckAfterBattlePecha::
# 138 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_PECHA_BERRY_USED, EscapeRoom_MapScripts_CheckAfterBattlePecha_2
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_1:
# 140 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_PECHA_BERRY
# 141 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_MapScripts_CheckAfterBattlePecha_5
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_2:
# 138 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_POKEMON_CAUGHT, EscapeRoom_MapScripts_CheckAfterBattlePecha_1
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_5:
# 143 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 144 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_PECHA_BERRY
	goto_if_ne EscapeRoom_MapScripts_CheckAfterBattlePecha_7
	return

EscapeRoom_MapScripts_CheckAfterBattlePecha_7:
# 146 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 1
	return


EscapeRoom_MapScripts_FindPechaBerryAferUse::
# 153 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 154 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewPechaBerryMessage, MSGBOX_AUTOCLOSE
# 155 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 156 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_PECHA_BERRY
# 157 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_PECHA_BERRY_USED
# 158 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_PECHA, 0
# 159 "data/maps/EscapeRoom/scripts.pory"
	msgbox ThanksMomMessage, MSGBOX_AUTOCLOSE
# 160 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 161 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_FindGreatBallAferUse::
# 165 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 166 "data/maps/EscapeRoom/scripts.pory"
	msgbox NewGreatBallMessage, MSGBOX_AUTOCLOSE
# 167 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 168 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_GREAT_BALL
# 169 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 170 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_RETRIEVE_BALL, 0
# 171 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_SetHoleWarp::
# 175 "data/maps/EscapeRoom/scripts.pory"
	setstepcallback STEP_CB_CRACKED_FLOOR
# 176 "data/maps/EscapeRoom/scripts.pory"
	setholewarp MAP_ESCAPE_ROOM_ICE_PUZZLE
	return


EscapeRoom_MapScripts_FixCrackedGround::
# 180 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ICE_STEP_COUNT, 1
# 181 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 7
	return


EscapeRoom_MapScript_setNPCfacing::
# 185 "data/maps/EscapeRoom/scripts.pory"
	turnobject 8, DIR_SOUTH
# 186 "data/maps/EscapeRoom/scripts.pory"
	turnobject 9, DIR_EAST
# 187 "data/maps/EscapeRoom/scripts.pory"
	turnobject 10, DIR_NORTH
# 188 "data/maps/EscapeRoom/scripts.pory"
	turnobject 11, DIR_SOUTH
# 189 "data/maps/EscapeRoom/scripts.pory"
	turnobject 12, DIR_WEST
# 190 "data/maps/EscapeRoom/scripts.pory"
	turnobject 13, DIR_WEST
# 191 "data/maps/EscapeRoom/scripts.pory"
	turnobject 14, DIR_EAST
# 192 "data/maps/EscapeRoom/scripts.pory"
	turnobject 16, DIR_SOUTH
	return


EscapeRoom_MapScript_KeepDouble1Moved::
# 196 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_DOUBLE1_COMPLETED, EscapeRoom_MapScript_KeepDouble1Moved_1
	return

EscapeRoom_MapScript_KeepDouble1Moved_1:
# 197 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 1, 6, 12
# 198 "data/maps/EscapeRoom/scripts.pory"
	setobjectxyperm 2, 6, 11
	return


EscapeRoom_MapScripts_PlayStartMessage::
# 203 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 205 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 1
# 206 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_MapScripts_GetFirstPokemon::
# 210 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_TOXICROAK, 53, item = ITEM_HEART_SCALE, abilityNum = 1, nature = 4, gender = 0, move1 = MOVE_THIEF, move2 = MOVE_ROLE_PLAY, move3 = MOVE_SUNNY_DAY, move4 = MOVE_NONE, hpEv = 8, atkEv = 252, spAtkEv = 160, hpIv = 31, atkIv = 31, defIv = 0, speedIv = 30, spAtkIv = 30, spDefIv = 0
# 233 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 234 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 2
	return


EscapeRoom_MapScripts_GetBadges::
# 238 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_RUSTBORO_GYM
# 239 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE01_GET
# 240 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 241 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE02_GET
# 242 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MAUVILLE_GYM
# 243 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE03_GET
# 244 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
# 245 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE04_GET
# 246 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_PETALBURG_GYM
# 247 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE05_GET
# 248 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_FORTREE_GYM
# 249 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE06_GET
# 250 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
# 251 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE07_GET
# 252 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
# 253 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_BADGE08_GET
# 255 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 3
	end


EscapeRoom_MapScripts_SetRespawn::
# 260 "data/maps/EscapeRoom/scripts.pory"
	setrespawn HEAL_LOCATION_ESCAPE_ROOM_NURSE
# 261 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 4
	return


EscapeRoom_MapScripts_GetItems::
# 265 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_HM04
# 266 "data/maps/EscapeRoom/scripts.pory"
	additem ITEM_NUGGET, 14
# 267 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 5
	return


EscapeRoom_MapScripts_TurnOfBagUse::
# 271 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOGGLE_BAG_USE, EscapeRoom_MapScripts_TurnOfBagUse_2
EscapeRoom_MapScripts_TurnOfBagUse_1:
# 274 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_ESCAPE_ROOM_MAPSCRIPT_COUNTER, 6
	return

EscapeRoom_MapScripts_TurnOfBagUse_2:
# 272 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOGGLE_BAG_USE
	goto EscapeRoom_MapScripts_TurnOfBagUse_1


EscapeRoom_EventScript_TestSign::
# 281 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 282 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessageReadInfoAgain, MSGBOX_YESNO
# 283 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TestSign_2
EscapeRoom_EventScript_TestSign_1:
# 288 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TestSign_2:
# 285 "data/maps/EscapeRoom/scripts.pory"
	msgbox SignMessage1
# 286 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_TestSign_1


EscapeRoom_Nurse_Heal_Pokemon::
# 292 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 293 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_TO_BLACK
# 294 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 295 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_HEAL
# 296 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 297 "data/maps/EscapeRoom/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 298 "data/maps/EscapeRoom/scripts.pory"
	msgbox Nurse_Heal_End
# 299 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 300 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindRareCandy::
# 304 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 305 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_RARE_CANDY
# 306 "data/maps/EscapeRoom/scripts.pory"
	removeobject 2
# 307 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_RARE_CANDY_OBTAINED
# 308 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindNugget3::
# 312 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 313 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_NUGGET
# 314 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 315 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_NUGGET3_OBTAINED
# 316 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindHeartScale::
# 320 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 321 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_HEART_SCALE
# 322 "data/maps/EscapeRoom/scripts.pory"
	removeobject 6
# 323 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HEART_SCALE2_OBTAINED
# 324 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_GoodSmeargle_NPC::
# 328 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 329 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 330 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_GoodSmeargle_NPC_2
# 338 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 339 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_4
# 348 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 349 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 0
# 350 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_9
EscapeRoom_EventScript_GoodSmeargle_NPC_7:
# 353 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_PROTECT
# 354 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_GoodSmeargle_NPC_14
EscapeRoom_EventScript_GoodSmeargle_NPC_12:
# 359 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 360 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 0
# 361 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_GoodSmeargle_NPC_18
EscapeRoom_EventScript_GoodSmeargle_NPC_17:
# 366 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_22
EscapeRoom_EventScript_GoodSmeargle_NPC_20:
# 375 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_27
EscapeRoom_EventScript_GoodSmeargle_NPC_25:
# 383 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8001, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_31
EscapeRoom_EventScript_GoodSmeargle_NPC_30:
# 386 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_2:
# 331 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageCompleted
# 332 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 333 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_4:
# 340 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageInitial
# 341 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 342 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_8:
# 351 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_9:
# 350 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_8
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_7

EscapeRoom_EventScript_GoodSmeargle_NPC_13:
# 355 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8001, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_14:
# 354 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_SMEARGLE
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_13
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_12

EscapeRoom_EventScript_GoodSmeargle_NPC_18:
# 362 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x8000, 1
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_17

EscapeRoom_EventScript_GoodSmeargle_NPC_21:
# 367 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfect, MSGBOX_YESNO
# 368 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 369 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_IniitializeGardevoirTrade
# 370 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_22:
# 366 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 0
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_21
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_20

EscapeRoom_EventScript_GoodSmeargle_NPC_26:
# 376 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessagePerfectButToxicroakInBox
# 377 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 378 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_GoodSmeargle_NPC_27:
# 375 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8000, 1
	goto_if_eq EscapeRoom_EventScript_GoodSmeargle_NPC_26
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_25

EscapeRoom_EventScript_GoodSmeargle_NPC_31:
# 384 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleMessageBad
	goto EscapeRoom_EventScript_GoodSmeargle_NPC_30


EscapeRoom_EventScript_IniitializeGardevoirTrade::
# 392 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_IniitializeGardevoirTrade_1
# 423 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeDeclinedMessage
	return

EscapeRoom_EventScript_IniitializeGardevoirTrade_1:
# 393 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_TOXICROAK
# 394 "data/maps/EscapeRoom/scripts.pory"
	givemon SPECIES_GARDEVOIR, 30, abilityNum = 0, nature = 5, gender = 1, move1 = MOVE_TRICK_ROOM, move2 = MOVE_SKILL_SWAP, move3 = MOVE_NONE, move4 = MOVE_NONE, hpEv = 132, defEv = 212, spDefEv = 24, hpIv = 31, atkIv = 0, defIv = 31, speedIv = 0, spAtkIv = 31, spDefIv = 31
# 416 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 417 "data/maps/EscapeRoom/scripts.pory"
	msgbox GardevoirObtainedMessage, MSGBOX_AUTOCLOSE
# 418 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
# 419 "data/maps/EscapeRoom/scripts.pory"
	msgbox TradeAcceptedMessage, MSGBOX_AUTOCLOSE
# 420 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_GARDEVOIR_TRADE_SUCCESS
	return


EscapeRoom_EventScript_SingleBattle1::
# 428 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE1, Single1Puzzle_Intro, Single1Puzzle_Outro, event_script = EscapeRoom_EventScript_Single1PostMatch
# 434 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 435 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle2::
# 440 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE2, Single2Puzzle_Intro, Single2Puzzle_Outro, event_script = EscapeRoom_EventScript_Single2PostMatch
# 446 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single2Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 447 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_SingleBattle3::
# 452 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 453 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE3, Single3Puzzle_Intro, Single3Puzzle_Outro, event_script = EscapeRoom_EventScript_Single3PostMatch
# 459 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_TeleportBackOverLedge
	end


EscapeRoom_EventScript_SingleBattle4::
# 464 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 465 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE2_BYPASSED
# 466 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_single TRAINER_MY_CUSTOM_SINGLE_BATTLE4, Single4IntroMessage, Single4OutroMessage, event_script = EscapeRoom_EventScript_SetSingle4Rematch
	return


EscapeRoom_EventScript_Single1PostMatch::
# 475 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_ROEL_DEFEATED
# 476 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single2PostMatch::
# 480 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DS_ABEL_DEFEATED
# 481 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_Single3PostMatch::
# 485 "data/maps/EscapeRoom/scripts.pory"
	checkentirepartyfainted
# 486 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_Single3PostMatch_1
	return

EscapeRoom_EventScript_Single3PostMatch_1:
# 487 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
	return


EscapeRoom_EventScript_SetSingle4Rematch::
# 492 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE4
# 493 "data/maps/EscapeRoom/scripts.pory"
	msgbox single4PostMatchMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TeleportBackOverLedge::
# 497 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 498 "data/maps/EscapeRoom/scripts.pory"
	msgbox Single3Puzzle_PostBattle, MSGBOX_YESNO
# 499 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_2
# 564 "data/maps/EscapeRoom/scripts.pory"
	msgbox NoTeleportPleaseMessage, MSGBOX_AUTOCLOSE
# 565 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_TeleportBackOverLedge_1:
# 567 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_TeleportBackOverLedge_2:
# 501 "data/maps/EscapeRoom/scripts.pory"
	msgbox YesTeleportOutMessage, MSGBOX_AUTOCLOSE
# 502 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 505 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
# 508 "data/maps/EscapeRoom/scripts.pory"
	removemoney 99999
# 511 "data/maps/EscapeRoom/scripts.pory"
	cleartrainerflag TRAINER_MY_CUSTOM_SINGLE_BATTLE3
# 514 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_FINAL_GAMBIT
# 515 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_6
EscapeRoom_EventScript_TeleportBackOverLedge_5:
# 522 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_MIMIC
# 523 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_TeleportBackOverLedge_9
EscapeRoom_EventScript_TeleportBackOverLedge_8:
# 530 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_TeleportBackOverLedge_12
# 544 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HM06
# 545 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_18
EscapeRoom_EventScript_TeleportBackOverLedge_11:
# 558 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_HM_ROCK_SMASH_STOLEN
# 561 "data/maps/EscapeRoom/scripts.pory"
	warpteleport MAP_ESCAPE_ROOM, 11, 26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_1

EscapeRoom_EventScript_TeleportBackOverLedge_6:
# 516 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_FINAL_GAMBIT
# 517 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 518 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_5

EscapeRoom_EventScript_TeleportBackOverLedge_9:
# 524 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, MOVE_MIMIC
# 525 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_SKETCH
# 526 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_RESULT, VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_8

EscapeRoom_EventScript_TeleportBackOverLedge_12:
# 532 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 533 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_16
EscapeRoom_EventScript_TeleportBackOverLedge_15:
# 536 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 537 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_21
EscapeRoom_EventScript_TeleportBackOverLedge_20:
# 540 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HM06
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_16:
# 534 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_15

EscapeRoom_EventScript_TeleportBackOverLedge_18:
# 546 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 547 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_24
EscapeRoom_EventScript_TeleportBackOverLedge_23:
# 550 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 1
# 551 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_HM06
	goto_if_eq EscapeRoom_EventScript_TeleportBackOverLedge_26
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11

EscapeRoom_EventScript_TeleportBackOverLedge_21:
# 538 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_20

EscapeRoom_EventScript_TeleportBackOverLedge_24:
# 548 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_TeleportBackOverLedge_23

EscapeRoom_EventScript_TeleportBackOverLedge_26:
# 552 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 1
	goto EscapeRoom_EventScript_TeleportBackOverLedge_11


EscapeRoom_EventScript_DoubleBattle1::
# 571 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE1, Double1Puzzle_Intro, Double1Puzzle_Outro, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_Double1WalkAwayAndHeal
# 579 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Puzzle_PostBattle, MSGBOX_AUTOCLOSE
# 580 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_DoubleBattle2::
# 585 "data/maps/EscapeRoom/scripts.pory"
	trainerbattle_double TRAINER_MY_CUSTOM_DOUBLE_BATTLE2, Double2IntroMessage, Double2OutroMessage, Double1Puzzle_NotEnoughMons, event_script = EscapeRoom_EventScript_PostMatchHeal
# 592 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double2PostMatchMessage, MSGBOX_AUTOCLOSE
# 593 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	end


EscapeRoom_EventScript_Double1WalkAwayAndHeal::
# 598 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 599 "data/maps/EscapeRoom/scripts.pory"
	msgbox Double1Finalwords
# 600 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 601 "data/maps/EscapeRoom/scripts.pory"
	applymovement 1, EscapeRoom_Movement_Double1End
# 602 "data/maps/EscapeRoom/scripts.pory"
	applymovement 2, EscapeRoom_Movement_Double1End
# 603 "data/maps/EscapeRoom/scripts.pory"
	waitmovement 0
# 604 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 1
# 605 "data/maps/EscapeRoom/scripts.pory"
	copyobjectxytoperm 2
# 606 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_PostMatchHeal
# 607 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_DOUBLE1_COMPLETED
# 608 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


# 612 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Movement_Double1End:
# 613 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 613 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 613 "data/maps/EscapeRoom/scripts.pory"
	walk_left
# 614 "data/maps/EscapeRoom/scripts.pory"
	face_right
	step_end

EscapeRoom_EventScript_PostMatchHeal::
# 618 "data/maps/EscapeRoom/scripts.pory"
	special HealPlayerParty
	return


EscapeRoom_EventScript_BikeShop::
# 622 "data/maps/EscapeRoom/scripts.pory"
	lock
# 623 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 624 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShopHelloMessage
# 625 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 626 "data/maps/EscapeRoom/scripts.pory"
	pokemart EscapeRoom_Mart_BikeShop
# 627 "data/maps/EscapeRoom/scripts.pory"
	msgbox BikeShoptGoodbyeMessage, MSGBOX_DEFAULT
# 628 "data/maps/EscapeRoom/scripts.pory"
	release
	end


	.align 2
# 632 "data/maps/EscapeRoom/scripts.pory"
EscapeRoom_Mart_BikeShop:
# 633 "data/maps/EscapeRoom/scripts.pory"
	.2byte ITEM_MACH_BIKE
	.2byte ITEM_NONE

EscapeRoom_EventScript_HeartscaleTutor::
# 637 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 638 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 639 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 642 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_8
EscapeRoom_EventScript_HeartscaleTutor_6:
# 648 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_5
EscapeRoom_EventScript_HeartscaleTutor_4:
# 721 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 723 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 724 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_17
# 756 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoSuitablePokemonMessage, MSGBOX_AUTOCLOSE
# 757 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_HeartscaleTutor_1:
# 760 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_HeartscaleTutor_2:
# 643 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorStartMessage
# 644 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorNoHeartScales, MSGBOX_AUTOCLOSE
# 645 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_3:
# 650 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 651 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, MOVE_NONE
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_14
EscapeRoom_EventScript_HeartscaleTutor_13:
# 655 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceMove, MSGBOX_YESNO
EscapeRoom_EventScript_HeartscaleTutor_11:
# 657 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 658 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_20
# 716 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 717 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_5:
# 648 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_3
	goto EscapeRoom_EventScript_HeartscaleTutor_4

EscapeRoom_EventScript_HeartscaleTutor_8:
# 642 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TUTOR_MOVE_LEARNED, EscapeRoom_EventScript_HeartscaleTutor_2
	goto EscapeRoom_EventScript_HeartscaleTutor_6

EscapeRoom_EventScript_HeartscaleTutor_12:
# 652 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorReplaceSingleMove, MSGBOX_YESNO
	goto EscapeRoom_EventScript_HeartscaleTutor_11

EscapeRoom_EventScript_HeartscaleTutor_14:
# 651 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_12
	goto EscapeRoom_EventScript_HeartscaleTutor_13

EscapeRoom_EventScript_HeartscaleTutor_17:
# 725 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 726 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskTeachGardevoirDisable, MSGBOX_YESNO
# 729 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_23
# 750 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 751 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_20:
# 661 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_GARDEVOIR
# 662 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 663 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_26
# 711 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorBringReplaceMonMessage, MSGBOX_AUTOCLOSE
# 712 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_23:
# 730 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_0x800A, MOVE_NONE
# 731 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 732 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 733 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 736 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_29
# 742 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 743 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 744 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_HEART_SCALE, 1
# 745 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TUTOR_MOVE_LEARNED
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_26:
# 666 "data/maps/EscapeRoom/scripts.pory"
	checktutormoveslearned SPECIES_GARDEVOIR
# 667 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_RESULT
# 668 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800B, VAR_0x8004
# 671 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x800B, MOVE_NONE
	goto_if_ne EscapeRoom_EventScript_HeartscaleTutor_33
EscapeRoom_EventScript_HeartscaleTutor_32:
# 687 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, MOVE_NONE
# 688 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_0x800A, VAR_TEMP_1
# 691 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_TEMP_0
# 692 "data/maps/EscapeRoom/scripts.pory"
	special TeachMoveRelearnerMove
# 693 "data/maps/EscapeRoom/scripts.pory"
	waitstate
# 694 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 697 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_35
# 706 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTaughtMove, MSGBOX_AUTOCLOSE
# 707 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_29:
# 737 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 738 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_33:
# 672 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorWhichMoveReplaceMessage, MSGBOX_REPLACEMOVE
# 673 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_38
# 676 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_39
# 679 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 127
	goto_if_eq EscapeRoom_EventScript_HeartscaleTutor_40
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_35:
# 698 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 699 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 702 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_TEMP_1, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_1

EscapeRoom_EventScript_HeartscaleTutor_38:
# 674 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800A
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_39:
# 677 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_0x800A, VAR_0x800B
	goto EscapeRoom_EventScript_HeartscaleTutor_32

EscapeRoom_EventScript_HeartscaleTutor_40:
# 680 "data/maps/EscapeRoom/scripts.pory"
	msgbox MoveTutorTradeDeclined, MSGBOX_AUTOCLOSE
# 681 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 682 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_QuietTurnNPC::
# 765 "data/maps/EscapeRoom/scripts.pory"
	msgbox QuietTurnNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PerishExplain_NPC::
# 769 "data/maps/EscapeRoom/scripts.pory"
	msgbox PerishNPCexplain, MSGBOX_NPC
	return


EscapeRoom_EventScript_someoneLockedUsUpNPC::
# 773 "data/maps/EscapeRoom/scripts.pory"
	msgbox someoneLockedUsUpNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_GetUsOutNPC::
# 777 "data/maps/EscapeRoom/scripts.pory"
	msgbox GetUsOutNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_NuggetNPC::
# 781 "data/maps/EscapeRoom/scripts.pory"
	msgbox NuggetNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_perfectSmeargleHintNPC::
# 785 "data/maps/EscapeRoom/scripts.pory"
	msgbox perfectSmeargleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_icePuzzleHintNPC::
# 789 "data/maps/EscapeRoom/scripts.pory"
	msgbox icePuzzleHintNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_StopWinningNPC::
# 793 "data/maps/EscapeRoom/scripts.pory"
	msgbox StopWinningNPCmessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_catchSalazzleNPC::
# 797 "data/maps/EscapeRoom/scripts.pory"
	msgbox SalazzleCatchingHint, MSGBOX_NPC
	return


EscapeRoom_EventScript_EndEscapeRoomSign::
# 801 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 802 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_END_ESCAPE_ROOM, EscapeRoom_EventScript_EndEscapeRoomSign_2
# 809 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 810 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_EndEscapeRoomSign_1:
# 812 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_CalcHintsUsed
# 813 "data/maps/EscapeRoom/scripts.pory"
	bufferplaytimeandhints
# 814 "data/maps/EscapeRoom/scripts.pory"
	msgbox EndEscapeRoomSignMessage
# 815 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 816 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_EndEscapeRoomSign_2:
# 803 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_END_ESCAPE_ROOM
# 804 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 805 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoomEndCongratz
# 806 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	goto EscapeRoom_EventScript_EndEscapeRoomSign_1


EscapeRoom_EventScript_CalcHintsUsed::
# 820 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_HINTS_USED_COUNTER, 0
# 821 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GREAT_BALL, EscapeRoom_EventScript_CalcHintsUsed_2
EscapeRoom_EventScript_CalcHintsUsed_1:
# 824 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_NUGGET, EscapeRoom_EventScript_CalcHintsUsed_5
EscapeRoom_EventScript_CalcHintsUsed_4:
# 827 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_8
EscapeRoom_EventScript_CalcHintsUsed_7:
# 830 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_11
EscapeRoom_EventScript_CalcHintsUsed_10:
# 833 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENTS_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_14
EscapeRoom_EventScript_CalcHintsUsed_13:
# 836 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_CATCHING_SMEARGLE, EscapeRoom_EventScript_CalcHintsUsed_17
EscapeRoom_EventScript_CalcHintsUsed_16:
# 839 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROSE_UN, EscapeRoom_EventScript_CalcHintsUsed_20
EscapeRoom_EventScript_CalcHintsUsed_19:
# 842 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_DS_ABEL, EscapeRoom_EventScript_CalcHintsUsed_23
EscapeRoom_EventScript_CalcHintsUsed_22:
# 845 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROEL, EscapeRoom_EventScript_CalcHintsUsed_26
EscapeRoom_EventScript_CalcHintsUsed_25:
# 848 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_C_TRISH, EscapeRoom_EventScript_CalcHintsUsed_29
EscapeRoom_EventScript_CalcHintsUsed_28:
# 851 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_PEE_SEA, EscapeRoom_EventScript_CalcHintsUsed_32
EscapeRoom_EventScript_CalcHintsUsed_31:
# 854 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_JAN_NAN, EscapeRoom_EventScript_CalcHintsUsed_35
EscapeRoom_EventScript_CalcHintsUsed_34:
# 858 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SALAZZLE, EscapeRoom_EventScript_CalcHintsUsed_38
EscapeRoom_EventScript_CalcHintsUsed_37:
# 861 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ROSE_UN, EscapeRoom_EventScript_CalcHintsUsed_41
EscapeRoom_EventScript_CalcHintsUsed_40:
# 864 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PC_CHECK, EscapeRoom_EventScript_CalcHintsUsed_44
EscapeRoom_EventScript_CalcHintsUsed_43:
# 867 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE2, EscapeRoom_EventScript_CalcHintsUsed_47
EscapeRoom_EventScript_CalcHintsUsed_46:
# 870 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE2, EscapeRoom_EventScript_CalcHintsUsed_50
EscapeRoom_EventScript_CalcHintsUsed_49:
# 873 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SMEARGLE_CATCH, EscapeRoom_EventScript_CalcHintsUsed_53
EscapeRoom_EventScript_CalcHintsUsed_52:
# 876 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_DS_ABEL, EscapeRoom_EventScript_CalcHintsUsed_56
EscapeRoom_EventScript_CalcHintsUsed_55:
# 879 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_CalcHintsUsed_59
EscapeRoom_EventScript_CalcHintsUsed_58:
# 882 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GET_HEART_SCALE, EscapeRoom_EventScript_CalcHintsUsed_62
EscapeRoom_EventScript_CalcHintsUsed_61:
# 885 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENT_PUZZLE, EscapeRoom_EventScript_CalcHintsUsed_65
EscapeRoom_EventScript_CalcHintsUsed_64:
# 888 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_ROEL, EscapeRoom_EventScript_CalcHintsUsed_68
EscapeRoom_EventScript_CalcHintsUsed_67:
# 891 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PEE_SEA, EscapeRoom_EventScript_CalcHintsUsed_71
EscapeRoom_EventScript_CalcHintsUsed_70:
# 894 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STEAL_SITRUS, EscapeRoom_EventScript_CalcHintsUsed_74
EscapeRoom_EventScript_CalcHintsUsed_73:
# 897 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_JAN_NAN, EscapeRoom_EventScript_CalcHintsUsed_76
	return

EscapeRoom_EventScript_CalcHintsUsed_2:
# 822 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_1

EscapeRoom_EventScript_CalcHintsUsed_5:
# 825 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_4

EscapeRoom_EventScript_CalcHintsUsed_8:
# 828 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_7

EscapeRoom_EventScript_CalcHintsUsed_11:
# 831 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_10

EscapeRoom_EventScript_CalcHintsUsed_14:
# 834 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_13

EscapeRoom_EventScript_CalcHintsUsed_17:
# 837 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_16

EscapeRoom_EventScript_CalcHintsUsed_20:
# 840 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_19

EscapeRoom_EventScript_CalcHintsUsed_23:
# 843 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_22

EscapeRoom_EventScript_CalcHintsUsed_26:
# 846 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_25

EscapeRoom_EventScript_CalcHintsUsed_29:
# 849 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_28

EscapeRoom_EventScript_CalcHintsUsed_32:
# 852 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_31

EscapeRoom_EventScript_CalcHintsUsed_35:
# 855 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_34

EscapeRoom_EventScript_CalcHintsUsed_38:
# 859 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_37

EscapeRoom_EventScript_CalcHintsUsed_41:
# 862 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_40

EscapeRoom_EventScript_CalcHintsUsed_44:
# 865 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_43

EscapeRoom_EventScript_CalcHintsUsed_47:
# 868 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_46

EscapeRoom_EventScript_CalcHintsUsed_50:
# 871 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_49

EscapeRoom_EventScript_CalcHintsUsed_53:
# 874 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_52

EscapeRoom_EventScript_CalcHintsUsed_56:
# 877 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_55

EscapeRoom_EventScript_CalcHintsUsed_59:
# 880 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_58

EscapeRoom_EventScript_CalcHintsUsed_62:
# 883 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_61

EscapeRoom_EventScript_CalcHintsUsed_65:
# 886 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_64

EscapeRoom_EventScript_CalcHintsUsed_68:
# 889 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_67

EscapeRoom_EventScript_CalcHintsUsed_71:
# 892 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_70

EscapeRoom_EventScript_CalcHintsUsed_74:
# 895 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	goto EscapeRoom_EventScript_CalcHintsUsed_73

EscapeRoom_EventScript_CalcHintsUsed_76:
# 898 "data/maps/EscapeRoom/scripts.pory"
	addvar VAR_HINTS_USED_COUNTER, 1
	return


EscapeRoom_EventScript_FindIronBall::
# 903 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 904 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_IRON_BALL
# 905 "data/maps/EscapeRoom/scripts.pory"
	removeobject 15
# 906 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_IRON_BALL_OBTAINED
# 907 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FindToxicOrb::
# 911 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 912 "data/maps/EscapeRoom/scripts.pory"
	finditem ITEM_TOXIC_ORB
# 913 "data/maps/EscapeRoom/scripts.pory"
	removeobject 1
# 914 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_TOXIC_ORB_OBTAINED
# 915 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_PressStartSign::
# 919 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 920 "data/maps/EscapeRoom/scripts.pory"
	msgbox PressStartSignMessage
# 921 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 922 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_ExitCloseNPC::
# 926 "data/maps/EscapeRoom/scripts.pory"
	msgbox ExitCloseNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_PainSplitHintNPC::
# 930 "data/maps/EscapeRoom/scripts.pory"
	msgbox PainSplitHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_BerryTreeHintNPC::
# 934 "data/maps/EscapeRoom/scripts.pory"
	msgbox BerryTreeHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_TormentHintNPC::
# 938 "data/maps/EscapeRoom/scripts.pory"
	msgbox TormentHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_SketchHintNPC::
# 942 "data/maps/EscapeRoom/scripts.pory"
	msgbox SketchHintNPCMessage, MSGBOX_NPC
	return


EscapeRoom_EventScript_Question1Sign::
# 946 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 947 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question1Message
# 948 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 949 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question2Sign::
# 953 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 954 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question2Message
# 955 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 956 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question3Sign::
# 960 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 961 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question3Message
# 962 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 963 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_Question4Sign::
# 967 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 968 "data/maps/EscapeRoom/scripts.pory"
	msgbox Question4Message
# 969 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 970 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTFSign::
# 974 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 975 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTFSign_Text_0
# 976 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 977 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTFSign::
# 981 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 982 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTFSign_Text_0
# 983 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 984 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFFSign::
# 988 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 989 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFFSign_Text_0
# 990 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 991 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTFSign::
# 995 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 996 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTFSign_Text_0
# 997 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 998 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFFFSign::
# 1002 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1003 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFFFSign_Text_0
# 1004 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1005 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFFSign::
# 1009 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1010 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFFSign_Text_0
# 1011 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1012 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTTTSign::
# 1016 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1017 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTTTSign_Text_0
# 1018 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1019 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FTTTSign::
# 1023 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1024 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FTTTSign_Text_0
# 1025 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1026 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TFTTSign::
# 1030 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1031 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TFTTSign_Text_0
# 1032 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1033 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_TTFTSign::
# 1037 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1038 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_TTFTSign_Text_0
# 1039 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1040 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFTTSign::
# 1044 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1045 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFTTSign_Text_0
# 1046 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1047 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_FFFTSign::
# 1051 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1052 "data/maps/EscapeRoom/scripts.pory"
	msgbox EscapeRoom_EventScript_FFFTSign_Text_0
# 1053 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1054 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return


EscapeRoom_EventScript_AntiSoftlockGuy::
# 1058 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 1059 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1063 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_POKEMON_CAUGHT, EscapeRoom_EventScript_AntiSoftlockGuy_2
EscapeRoom_EventScript_AntiSoftlockGuy_1:
# 1074 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_RARE_CANDY_USED, EscapeRoom_EventScript_AntiSoftlockGuy_5
EscapeRoom_EventScript_AntiSoftlockGuy_4:
# 1097 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1098 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_11
EscapeRoom_EventScript_AntiSoftlockGuy_9:
# 1130 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockIntroMessage
# 1131 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockNoActionMessage
# 1132 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_AntiSoftlockGuy_2:
# 1065 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_7
	goto EscapeRoom_EventScript_AntiSoftlockGuy_1

EscapeRoom_EventScript_AntiSoftlockGuy_5:
# 1075 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1078 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 1079 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_15
EscapeRoom_EventScript_AntiSoftlockGuy_14:
# 1083 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonlevel 31
# 1084 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_ne EscapeRoom_EventScript_AntiSoftlockGuy_20
EscapeRoom_EventScript_AntiSoftlockGuy_19:
# 1088 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
# 1088 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_26
	goto EscapeRoom_EventScript_AntiSoftlockGuy_4

EscapeRoom_EventScript_AntiSoftlockGuy_7:
# 1066 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSmeargleCatch
# 1067 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_10:
# 1099 "data/maps/EscapeRoom/scripts.pory"
	copyvar VAR_TEMP_0, VAR_RESULT
# 1102 "data/maps/EscapeRoom/scripts.pory"
	checkpartymove MOVE_SKETCH
# 1103 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_17
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_11:
# 1098 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_AntiSoftlockGuy_10
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_15:
# 1080 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_AntiSoftlockGuy_14

EscapeRoom_EventScript_AntiSoftlockGuy_17:
# 1106 "data/maps/EscapeRoom/scripts.pory"
	checkpartymonmoves VAR_TEMP_0
# 1107 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_22
# 1117 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_AntiSoftlockGuy_23
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_20:
# 1085 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
	goto EscapeRoom_EventScript_AntiSoftlockGuy_19

EscapeRoom_EventScript_AntiSoftlockGuy_22:
# 1110 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_30
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_23:
# 1120 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_AntiSoftlockGuy_32
	goto EscapeRoom_EventScript_AntiSoftlockGuy_9

EscapeRoom_EventScript_AntiSoftlockGuy_26:
# 1089 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoRareCandy
# 1090 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_30:
# 1111 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch1
# 1112 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_AntiSoftlockGuy_32:
# 1121 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_UndoSketch2
# 1122 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end


EscapeRoom_EventScript_UndoSmeargleCatch::
# 1136 "data/maps/EscapeRoom/scripts.pory"
	msgbox AskReleaseSmeargleMessage, MSGBOX_YESNO
# 1139 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_1
# 1194 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1195 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_1:
# 1142 "data/maps/EscapeRoom/scripts.pory"
	checkpartymon SPECIES_SMEARGLE
# 1143 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_5
# 1151 "data/maps/EscapeRoom/scripts.pory"
	partymonhasfainted
# 1152 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, SPECIES_TOXICROAK
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_8
EscapeRoom_EventScript_UndoSmeargleCatch_7:
# 1157 "data/maps/EscapeRoom/scripts.pory"
	getpartysize
# 1158 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_lt EscapeRoom_EventScript_UndoSmeargleCatch_10
# 1164 "data/maps/EscapeRoom/scripts.pory"
	removemon SPECIES_SMEARGLE
# 1165 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_POKEMON_CAUGHT
# 1166 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_GREAT_BALL_USED
# 1169 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1170 "data/maps/EscapeRoom/scripts.pory"
	checkitem ITEM_FLAME_ORB
# 1171 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_14
EscapeRoom_EventScript_UndoSmeargleCatch_13:
# 1175 "data/maps/EscapeRoom/scripts.pory"
	checkpartyitem 0
# 1176 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_0x8004, ITEM_FLAME_ORB
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_17
EscapeRoom_EventScript_UndoSmeargleCatch_16:
# 1182 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoSmeargleCatch_20
EscapeRoom_EventScript_UndoSmeargleCatch_19:
# 1187 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 1188 "data/maps/EscapeRoom/scripts.pory"
	msgbox ReleaseSmeargleMessage, MSGBOX_AUTOCLOSE
# 1189 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_5:
# 1144 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseBringSmeargleMessage, MSGBOX_AUTOCLOSE
# 1145 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1146 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_UndoSmeargleCatch_8:
# 1153 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseHealSecondMonMessage, MSGBOX_AUTOCLOSE
# 1154 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_7

EscapeRoom_EventScript_UndoSmeargleCatch_10:
# 1159 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleReleaseGetSecondMonMessage, MSGBOX_AUTOCLOSE
# 1160 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSmeargleCatch_14:
# 1172 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1173 "data/maps/EscapeRoom/scripts.pory"
	removeitem ITEM_FLAME_ORB
	goto EscapeRoom_EventScript_UndoSmeargleCatch_13

EscapeRoom_EventScript_UndoSmeargleCatch_17:
# 1177 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
# 1178 "data/maps/EscapeRoom/scripts.pory"
	removepartyitem 0
	goto EscapeRoom_EventScript_UndoSmeargleCatch_16

EscapeRoom_EventScript_UndoSmeargleCatch_20:
# 1183 "data/maps/EscapeRoom/scripts.pory"
	msgbox TakeFlameOrbMessage, MSGBOX_AUTOCLOSE
# 1184 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_UndoSmeargleCatch_19


EscapeRoom_EventScript_UndoRareCandy::
# 1200 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoRareCandyMessage, MSGBOX_YESNO
# 1203 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_1
# 1215 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1216 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoRareCandy_1:
# 1204 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_5
# 1207 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 2
	goto_if_eq EscapeRoom_EventScript_UndoRareCandy_6
EscapeRoom_EventScript_UndoRareCandy_4:
# 1210 "data/maps/EscapeRoom/scripts.pory"
	clearflag FLAG_RARE_CANDY_USED
# 1211 "data/maps/EscapeRoom/scripts.pory"
	giveitem ITEM_RARE_CANDY
	return

EscapeRoom_EventScript_UndoRareCandy_5:
# 1205 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_SMEARGLE
	goto EscapeRoom_EventScript_UndoRareCandy_4

EscapeRoom_EventScript_UndoRareCandy_6:
# 1208 "data/maps/EscapeRoom/scripts.pory"
	levelDownMon SPECIES_GARDEVOIR
	goto EscapeRoom_EventScript_UndoRareCandy_4


EscapeRoom_EventScript_UndoSketch1::
# 1221 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1224 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch1_1
# 1239 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1240 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch1_1:
# 1225 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1226 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1228 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1229 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1233 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1234 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1235 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return


EscapeRoom_EventScript_UndoSketch2::
# 1245 "data/maps/EscapeRoom/scripts.pory"
	msgbox UndoSketchMessage, MSGBOX_YESNO
# 1248 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_1
# 1270 "data/maps/EscapeRoom/scripts.pory"
	msgbox AntiSoftlockDeclinedMessage, MSGBOX_AUTOCLOSE
# 1271 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	return

EscapeRoom_EventScript_UndoSketch2_1:
# 1250 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 1251 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
# 1254 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, MOVE_PROTECT
	goto_if_eq EscapeRoom_EventScript_UndoSketch2_5
EscapeRoom_EventScript_UndoSketch2_4:
# 1259 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_2, MOVE_SKETCH
# 1260 "data/maps/EscapeRoom/scripts.pory"
	replacemove VAR_TEMP_0, VAR_RESULT, VAR_TEMP_2
# 1264 "data/maps/EscapeRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 1265 "data/maps/EscapeRoom/scripts.pory"
	msgbox SmeargleLearnedSketch
# 1266 "data/maps/EscapeRoom/scripts.pory"
	waitfanfare
	return

EscapeRoom_EventScript_UndoSketch2_5:
# 1255 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 1256 "data/maps/EscapeRoom/scripts.pory"
	getpartymonmove VAR_TEMP_0, VAR_TEMP_1
	goto EscapeRoom_EventScript_UndoSketch2_4


EscapeRoom_EventScript_HintsNPC::
# 1276 "data/maps/EscapeRoom/scripts.pory"
	faceplayer
# 1277 "data/maps/EscapeRoom/scripts.pory"
	lockall
# 1278 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsIntroMessage, MSGBOX_YESNO
# 1279 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EscapeRoom_EventScript_HintsNPC_2
# 1284 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
EscapeRoom_EventScript_HintsNPC_1:
# 1286 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	return

EscapeRoom_EventScript_HintsNPC_2:
# 1280 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCWhatKindOfHintMessage
# 1281 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
	goto EscapeRoom_EventScript_HintsNPC_1


EscapeRoom_EventScript_HintsNPC_part2::
# 1290 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 8, FALSE, 6, 0, 0, EscapeRoom_EventScript_HintsNPC_part2_Text_0, EscapeRoom_EventScript_HintsNPC_part2_Text_1
# 1294 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_1
# 1297 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_HintsNPC_part2_2
# 1301 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoHintMessage
	return

EscapeRoom_EventScript_HintsNPC_part2_1:
# 1295 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_WhereToLookHint
	return

EscapeRoom_EventScript_HintsNPC_part2_2:
# 1298 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_SpecificStepHint
	return


EscapeRoom_EventScript_SpecificStepHint::
# 1306 "data/maps/EscapeRoom/scripts.pory"
	dynmultichoice 20, 2, FALSE, 5, 0, 0, EscapeRoom_EventScript_SpecificStepHint_Text_0, EscapeRoom_EventScript_SpecificStepHint_Text_1, EscapeRoom_EventScript_SpecificStepHint_Text_2, EscapeRoom_EventScript_SpecificStepHint_Text_3, EscapeRoom_EventScript_SpecificStepHint_Text_4, EscapeRoom_EventScript_SpecificStepHint_Text_5, EscapeRoom_EventScript_SpecificStepHint_Text_6, EscapeRoom_EventScript_SpecificStepHint_Text_7, EscapeRoom_EventScript_SpecificStepHint_Text_8, EscapeRoom_EventScript_SpecificStepHint_Text_9, EscapeRoom_EventScript_SpecificStepHint_Text_10, EscapeRoom_EventScript_SpecificStepHint_Text_11
# 1321 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1323 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_2
# 1330 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 1
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_3
# 1337 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 2
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_4
# 1344 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 3
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_5
# 1351 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 4
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_6
# 1358 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 5
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_7
# 1365 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 6
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_8
# 1372 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 7
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_9
# 1379 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 8
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_10
# 1386 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 9
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_11
# 1393 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 10
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_12
# 1400 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_RESULT, 11
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_13
# 1408 "data/maps/EscapeRoom/scripts.pory"
	call EscapeRoom_EventScript_HintsNPC_part2
# 1409 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 2
EscapeRoom_EventScript_SpecificStepHint_1:
# 1413 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_28
# 1417 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 0
	goto_if_eq EscapeRoom_EventScript_SpecificStepHint_29
EscapeRoom_EventScript_SpecificStepHint_27:
# 1423 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
	return

EscapeRoom_EventScript_SpecificStepHint_2:
# 1324 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_GreatBall
# 1325 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_GREAT_BALL, EscapeRoom_EventScript_SpecificStepHint_33
EscapeRoom_EventScript_SpecificStepHint_32:
# 1328 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_GREAT_BALL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_3:
# 1331 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_Nugget
# 1332 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_NUGGET, EscapeRoom_EventScript_SpecificStepHint_36
EscapeRoom_EventScript_SpecificStepHint_35:
# 1335 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_NUGGET
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_4:
# 1338 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_IcePuzzle
# 1339 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_39
EscapeRoom_EventScript_SpecificStepHint_38:
# 1342 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ICE_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_5:
# 1345 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StrengthPuzzle
# 1346 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_42
EscapeRoom_EventScript_SpecificStepHint_41:
# 1349 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STRENGTH_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_6:
# 1352 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_StatementsPuzzle
# 1353 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENTS_PUZZLE, EscapeRoom_EventScript_SpecificStepHint_45
EscapeRoom_EventScript_SpecificStepHint_44:
# 1356 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STATEMENTS_PUZZLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_7:
# 1359 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_CatchingSmeargle
# 1360 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_CATCHING_SMEARGLE, EscapeRoom_EventScript_SpecificStepHint_48
EscapeRoom_EventScript_SpecificStepHint_47:
# 1363 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_CATCHING_SMEARGLE
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_8:
# 1366 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoseUn
# 1367 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROSE_UN, EscapeRoom_EventScript_SpecificStepHint_51
EscapeRoom_EventScript_SpecificStepHint_50:
# 1370 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROSE_UN
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_9:
# 1373 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerDSAbel
# 1374 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_DS_ABEL, EscapeRoom_EventScript_SpecificStepHint_54
EscapeRoom_EventScript_SpecificStepHint_53:
# 1377 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_DS_ABEL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_10:
# 1380 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerRoel
# 1381 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_ROEL, EscapeRoom_EventScript_SpecificStepHint_57
EscapeRoom_EventScript_SpecificStepHint_56:
# 1384 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_ROEL
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_11:
# 1387 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainerCTrish
# 1388 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINER_C_TRISH, EscapeRoom_EventScript_SpecificStepHint_60
EscapeRoom_EventScript_SpecificStepHint_59:
# 1391 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINER_C_TRISH
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_12:
# 1394 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersPeeSea
# 1395 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_PEE_SEA, EscapeRoom_EventScript_SpecificStepHint_63
EscapeRoom_EventScript_SpecificStepHint_62:
# 1398 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_PEE_SEA
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_13:
# 1401 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_TrainersJanNan
# 1402 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_TRAINERS_JAN_NAN, EscapeRoom_EventScript_SpecificStepHint_66
EscapeRoom_EventScript_SpecificStepHint_65:
# 1405 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_TRAINERS_JAN_NAN
	goto EscapeRoom_EventScript_SpecificStepHint_1

EscapeRoom_EventScript_SpecificStepHint_28:
# 1414 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoTimeAddedMessage
# 1415 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SpecificStepHint_27

EscapeRoom_EventScript_SpecificStepHint_29:
# 1418 "data/maps/EscapeRoom/scripts.pory"
	addgametime 20
# 1419 "data/maps/EscapeRoom/scripts.pory"
	playse SE_SHOP
# 1420 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC20minAddedMessage
# 1421 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_SpecificStepHint_27

EscapeRoom_EventScript_SpecificStepHint_33:
# 1326 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_32

EscapeRoom_EventScript_SpecificStepHint_36:
# 1333 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_35

EscapeRoom_EventScript_SpecificStepHint_39:
# 1340 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_38

EscapeRoom_EventScript_SpecificStepHint_42:
# 1347 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_41

EscapeRoom_EventScript_SpecificStepHint_45:
# 1354 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_44

EscapeRoom_EventScript_SpecificStepHint_48:
# 1361 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_47

EscapeRoom_EventScript_SpecificStepHint_51:
# 1368 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_50

EscapeRoom_EventScript_SpecificStepHint_54:
# 1375 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_53

EscapeRoom_EventScript_SpecificStepHint_57:
# 1382 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_56

EscapeRoom_EventScript_SpecificStepHint_60:
# 1389 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_59

EscapeRoom_EventScript_SpecificStepHint_63:
# 1396 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_62

EscapeRoom_EventScript_SpecificStepHint_66:
# 1403 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_SpecificStepHint_65


EscapeRoom_EventScript_WhereToLookHint::
# 1427 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
# 1429 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TM_10_STOLEN, EscapeRoom_EventScript_WhereToLookHint_2
# 1436 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HM06_STEAL_SUCCES, EscapeRoom_EventScript_WhereToLookHint_3
# 1443 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GREAT_BALL_FOUND, EscapeRoom_EventScript_WhereToLookHint_4
# 1450 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_PECHA_BERRY_FOUND, EscapeRoom_EventScript_WhereToLookHint_5
# 1457 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_TOXIC_ORB_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_6
# 1464 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_GARDEVOIR_TRADE_SUCCESS, EscapeRoom_EventScript_WhereToLookHint_7
# 1471 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DS_ABEL_DEFEATED, EscapeRoom_EventScript_WhereToLookHint_8
# 1478 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_NUGGET3_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_9
# 1485 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_HEART_SCALE2_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_10
# 1492 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_RARE_CANDY_OBTAINED, EscapeRoom_EventScript_WhereToLookHint_11
# 1499 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_ROEL_DEFEATED, EscapeRoom_EventScript_WhereToLookHint_12
# 1506 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DOUBLE2_BYPASSED, EscapeRoom_EventScript_WhereToLookHint_13
# 1513 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_SITRUS_STOLEN, EscapeRoom_EventScript_WhereToLookHint_14
# 1520 "data/maps/EscapeRoom/scripts.pory"
	goto_if_unset FLAG_DOUBLE1_COMPLETED, EscapeRoom_EventScript_WhereToLookHint_15
# 1528 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoNothingUrDone
# 1529 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
# 1530 "data/maps/EscapeRoom/scripts.pory"
	releaseall
	end

EscapeRoom_EventScript_WhereToLookHint_1:
# 1535 "data/maps/EscapeRoom/scripts.pory"
	compare VAR_TEMP_0, 1
	goto_if_eq EscapeRoom_EventScript_WhereToLookHint_32
# 1540 "data/maps/EscapeRoom/scripts.pory"
	addgametime 10
# 1541 "data/maps/EscapeRoom/scripts.pory"
	playse SE_SHOP
# 1542 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC10minAddedMessage
# 1543 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
EscapeRoom_EventScript_WhereToLookHint_31:
# 1545 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 0
	return

EscapeRoom_EventScript_WhereToLookHint_2:
# 1430 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoSalazzleThief
# 1431 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SALAZZLE, EscapeRoom_EventScript_WhereToLookHint_36
EscapeRoom_EventScript_WhereToLookHint_35:
# 1434 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_SALAZZLE
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_3:
# 1437 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoRoseUn
# 1438 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ROSE_UN, EscapeRoom_EventScript_WhereToLookHint_39
EscapeRoom_EventScript_WhereToLookHint_38:
# 1441 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ROSE_UN
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_4:
# 1444 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoPCCheck
# 1445 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PC_CHECK, EscapeRoom_EventScript_WhereToLookHint_42
EscapeRoom_EventScript_WhereToLookHint_41:
# 1448 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PC_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_5:
# 1451 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoIcePuzzle
# 1452 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_ICE_PUZZLE2, EscapeRoom_EventScript_WhereToLookHint_45
EscapeRoom_EventScript_WhereToLookHint_44:
# 1455 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_ICE_PUZZLE2
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_6:
# 1458 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStrengthPuzzle
# 1459 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STRENGTH_PUZZLE2, EscapeRoom_EventScript_WhereToLookHint_48
EscapeRoom_EventScript_WhereToLookHint_47:
# 1462 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STRENGTH_PUZZLE2
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_7:
# 1465 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoSmeargleCatch
# 1466 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_SMEARGLE_CATCH, EscapeRoom_EventScript_WhereToLookHint_51
EscapeRoom_EventScript_WhereToLookHint_50:
# 1469 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_SMEARGLE_CATCH
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_8:
# 1472 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoDSAbel
# 1473 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_DS_ABEL, EscapeRoom_EventScript_WhereToLookHint_54
EscapeRoom_EventScript_WhereToLookHint_53:
# 1476 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_DS_ABEL
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_9:
# 1479 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoPlantCheck
# 1480 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_WhereToLookHint_57
EscapeRoom_EventScript_WhereToLookHint_56:
# 1483 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PLANT_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_10:
# 1486 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoGetHeartScale
# 1487 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PLANT_CHECK, EscapeRoom_EventScript_WhereToLookHint_60
EscapeRoom_EventScript_WhereToLookHint_59:
# 1490 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PLANT_CHECK
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_11:
# 1493 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStatementPuzzle
# 1494 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STATEMENT_PUZZLE, EscapeRoom_EventScript_WhereToLookHint_63
EscapeRoom_EventScript_WhereToLookHint_62:
# 1497 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STATEMENT_PUZZLE
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_12:
# 1500 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoBeatRoel
# 1501 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_ROEL, EscapeRoom_EventScript_WhereToLookHint_66
EscapeRoom_EventScript_WhereToLookHint_65:
# 1504 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_BEAT_ROEL
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_13:
# 1507 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoGePastPeeSea
# 1508 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_PEE_SEA, EscapeRoom_EventScript_WhereToLookHint_69
EscapeRoom_EventScript_WhereToLookHint_68:
# 1511 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_PEE_SEA
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_14:
# 1514 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoStealSitrus
# 1515 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_STEAL_SITRUS, EscapeRoom_EventScript_WhereToLookHint_72
EscapeRoom_EventScript_WhereToLookHint_71:
# 1518 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_STEAL_SITRUS
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_15:
# 1521 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPC_DoBeatJanNan
# 1522 "data/maps/EscapeRoom/scripts.pory"
	goto_if_set FLAG_HINT_BEAT_JAN_NAN, EscapeRoom_EventScript_WhereToLookHint_75
EscapeRoom_EventScript_WhereToLookHint_74:
# 1525 "data/maps/EscapeRoom/scripts.pory"
	setflag FLAG_HINT_BEAT_JAN_NAN
	goto EscapeRoom_EventScript_WhereToLookHint_1

EscapeRoom_EventScript_WhereToLookHint_32:
# 1536 "data/maps/EscapeRoom/scripts.pory"
	msgbox HintsNPCNoTimeAddedMessage
# 1537 "data/maps/EscapeRoom/scripts.pory"
	waitmessage
	goto EscapeRoom_EventScript_WhereToLookHint_31

EscapeRoom_EventScript_WhereToLookHint_36:
# 1432 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_35

EscapeRoom_EventScript_WhereToLookHint_39:
# 1439 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_38

EscapeRoom_EventScript_WhereToLookHint_42:
# 1446 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_41

EscapeRoom_EventScript_WhereToLookHint_45:
# 1453 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_44

EscapeRoom_EventScript_WhereToLookHint_48:
# 1460 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_47

EscapeRoom_EventScript_WhereToLookHint_51:
# 1467 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_50

EscapeRoom_EventScript_WhereToLookHint_54:
# 1474 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_53

EscapeRoom_EventScript_WhereToLookHint_57:
# 1481 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_56

EscapeRoom_EventScript_WhereToLookHint_60:
# 1488 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_59

EscapeRoom_EventScript_WhereToLookHint_63:
# 1495 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_62

EscapeRoom_EventScript_WhereToLookHint_66:
# 1502 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_65

EscapeRoom_EventScript_WhereToLookHint_69:
# 1509 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_68

EscapeRoom_EventScript_WhereToLookHint_72:
# 1516 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_71

EscapeRoom_EventScript_WhereToLookHint_75:
# 1523 "data/maps/EscapeRoom/scripts.pory"
	setvar VAR_TEMP_0, 1
	goto EscapeRoom_EventScript_WhereToLookHint_74


EscapeRoom_EventScript_FFTFSign_Text_0:
# 975 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTF$"

EscapeRoom_EventScript_TTTFSign_Text_0:
# 982 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTF$"

EscapeRoom_EventScript_TTFFSign_Text_0:
# 989 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFF$"

EscapeRoom_EventScript_FTTFSign_Text_0:
# 996 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTF$"

EscapeRoom_EventScript_TFFFSign_Text_0:
# 1003 "data/maps/EscapeRoom/scripts.pory"
	.string "TFFF$"

EscapeRoom_EventScript_FFFFSign_Text_0:
# 1010 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFF$"

EscapeRoom_EventScript_TTTTSign_Text_0:
# 1017 "data/maps/EscapeRoom/scripts.pory"
	.string "TTTT$"

EscapeRoom_EventScript_FTTTSign_Text_0:
# 1024 "data/maps/EscapeRoom/scripts.pory"
	.string "FTTT$"

EscapeRoom_EventScript_TFTTSign_Text_0:
# 1031 "data/maps/EscapeRoom/scripts.pory"
	.string "TFTT$"

EscapeRoom_EventScript_TTFTSign_Text_0:
# 1038 "data/maps/EscapeRoom/scripts.pory"
	.string "TTFT$"

EscapeRoom_EventScript_FFTTSign_Text_0:
# 1045 "data/maps/EscapeRoom/scripts.pory"
	.string "FFTT$"

EscapeRoom_EventScript_FFFTSign_Text_0:
# 1052 "data/maps/EscapeRoom/scripts.pory"
	.string "FFFT$"

EscapeRoom_EventScript_HintsNPC_part2_Text_0:
# 1291 "data/maps/EscapeRoom/scripts.pory"
	.string "Where should I look now? (10 min.)$"

EscapeRoom_EventScript_HintsNPC_part2_Text_1:
# 1292 "data/maps/EscapeRoom/scripts.pory"
	.string "Hint for a specific step. (20 min.)$"

EscapeRoom_EventScript_SpecificStepHint_Text_0:
# 1307 "data/maps/EscapeRoom/scripts.pory"
	.string "Getting the Great Ball$"

EscapeRoom_EventScript_SpecificStepHint_Text_1:
# 1308 "data/maps/EscapeRoom/scripts.pory"
	.string "Getting the Nugget$"

EscapeRoom_EventScript_SpecificStepHint_Text_2:
# 1309 "data/maps/EscapeRoom/scripts.pory"
	.string "Ice Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_3:
# 1310 "data/maps/EscapeRoom/scripts.pory"
	.string "Strength Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_4:
# 1311 "data/maps/EscapeRoom/scripts.pory"
	.string "Statements Puzzle$"

EscapeRoom_EventScript_SpecificStepHint_Text_5:
# 1312 "data/maps/EscapeRoom/scripts.pory"
	.string "Catching the perfect Smeargle$"

EscapeRoom_EventScript_SpecificStepHint_Text_6:
# 1313 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Rose Un (Kecleon)$"

EscapeRoom_EventScript_SpecificStepHint_Text_7:
# 1314 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: DS. Abel (Slaking)$"

EscapeRoom_EventScript_SpecificStepHint_Text_8:
# 1315 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: Roel (Togedemaru)$"

EscapeRoom_EventScript_SpecificStepHint_Text_9:
# 1316 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainer: C. Trish (Klefki)$"

EscapeRoom_EventScript_SpecificStepHint_Text_10:
# 1317 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Pee & Sea (Urshifu, Urshifu)$"

EscapeRoom_EventScript_SpecificStepHint_Text_11:
# 1318 "data/maps/EscapeRoom/scripts.pory"
	.string "Trainers: Jan & Nan (Smeargle, Scrafty)$"

StartMessage::
# 1551 "data/maps/EscapeRoom/scripts.pory"
	.string "Welcome to Pokémon Cave Escape!\p"
	.string "You'll have to navigate tough battles\n"
	.string "and find creative solutions in order to\l"
	.string "progress through the map, with the\l"
	.string "ultimate goal of escaping the cave.\p"
	.string "READ CAREFULLY\p"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind. You won't gain EXP from battling.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) You won't get softlocked unless you\n"
	.string "toss away items, release Pokémon, or\l"
	.string "REALLY mess up the strength puzzle.\p"
	.string "7) Try to avoid using speed up.\n"
	.string "There are many clues, like NPC dialogue,\l"
	.string "that you might otherwise miss.\p"
	.string "That's all.\n"
	.string "Good luck!$"

SignMessage1::
# 1591 "data/maps/EscapeRoom/scripts.pory"
	.string "1) The game's battle mechanics are\n"
	.string "based on GEN 9.\l"
	.string "However, match tiebreakers will follow\l"
	.string "competitive battling rules.\p"
	.string "2) Battle RNG has been disabled.\n"
	.string "Catch rates, move effects, accuracy,\l"
	.string "and damage are now deterministic.\p"
	.string "3) There is no need for grinding of any\n"
	.string "kind. You won't gain EXP from battling.\p"
	.string "4) Any item you can find on the map\n"
	.string "directly will be inside an item ball.\p"
	.string "5) Trainer battles have a forfeit option\n"
	.string "(Run), which counts as a regular loss.\p"
	.string "6) You won't get softlocked unless you\n"
	.string "toss away items, release Pokémon, or\l"
	.string "REALLY mess up the Strength puzzle.\p"
	.string "7) Try to avoid using speed up.\n"
	.string "There are many clues, like NPC dialogue,\l"
	.string "that you might otherwise miss.$"

SignMessageReadInfoAgain::
# 1619 "data/maps/EscapeRoom/scripts.pory"
	.string "Do you want to read the important\n"
	.string "information again?$"

EscapeRoomEndCongratz::
# 1624 "data/maps/EscapeRoom/scripts.pory"
	.string "Congratulations!\n"
	.string "You have beaten the escape room!$"

EndEscapeRoomSignMessage::
# 1629 "data/maps/EscapeRoom/scripts.pory"
	.string "Final time: {STR_VAR_1}.\n"
	.string "Hints used: {STR_VAR_2}.\p"
	.string "Thank you for playing.\n"
	.string " - Roel$"

Double1Puzzle_NotEnoughMons::
# 1636 "data/maps/EscapeRoom/scripts.pory"
	.string "Want to battle?\n"
	.string "You should bring a second POKéMON.$"

Double1Puzzle_Intro::
# 1641 "data/maps/EscapeRoom/scripts.pory"
	.string "We've seen it all before.\n"
	.string "We know exactly what you'll do.\p"
	.string "Some think it's cheating.\n"
	.string "We call it wisdom.\p"
	.string "There's one path that always wins.\n"
	.string "Can you figure it out?$"

Double1Puzzle_Outro::
# 1650 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh...\n"
	.string "How did you figure that out?$"

Double1Finalwords::
# 1655 "data/maps/EscapeRoom/scripts.pory"
	.string "You've done it!$"

Double1Puzzle_PostBattle::
# 1659 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, go on now.$"

Nurse_Heal_End::
# 1663 "data/maps/EscapeRoom/scripts.pory"
	.string "As good as new!$"

SmeargleMessageInitial::
# 1667 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm looking for the perfect SMEARGLE.\n"
	.string "Have you got one??\p"
	.string "Come to me when you do and I might offer\n"
	.string "you my GARDEVOIR.$"

SmeargleMessageBad::
# 1674 "data/maps/EscapeRoom/scripts.pory"
	.string "Ew no, that SMEARGLE looks horrible.\n"
	.string "I asked for the perfect SMEARGLE.\p"
	.string "You should probably have a chat with\n"
	.string "the anti-softlock guy.$"

TakeFlameOrbMessage::
# 1681 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll take that FLAME ORB as well.\p"
	.string "(You don't need it anywhere)$"

SmeargleReleaseHealSecondMonMessage::
# 1686 "data/maps/EscapeRoom/scripts.pory"
	.string "You might want to heal your POKéMON\n"
	.string "first$"

SmeargleReleaseBringSmeargleMessage::
# 1690 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back with the SMEARGLE in\n"
	.string "your party.$"

SmeargleReleaseGetSecondMonMessage::
# 1694 "data/maps/EscapeRoom/scripts.pory"
	.string "That's your last POKéMON!$"

ReleaseSmeargleMessage::
# 1698 "data/maps/EscapeRoom/scripts.pory"
	.string "Bye-bye Smeargle.$"

SmeargleMessagePerfect::
# 1702 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That's the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Do you want to trade?$"

SmeargleMessagePerfectButToxicroakInBox::
# 1711 "data/maps/EscapeRoom/scripts.pory"
	.string "That is it! That is the perfect\n"
	.string "SMEARGLE!\p"
	.string "To show my gratitude, I'll let you trade\n"
	.string "your shitty TOXICROAK for my amazing\l"
	.string "GARDEVOIR.\p"
	.string "Oh, where did your TOXICROAK go?$"

TradeAcceptedMessage::
# 1720 "data/maps/EscapeRoom/scripts.pory"
	.string "There you go. Take care!$"

GardevoirObtainedMessage::
# 1724 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} received a Gardevoir!$"

TradeDeclinedMessage::
# 1728 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright, your loss.$"

SmeargleMessageCompleted::
# 1732 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think I like this TOXICROAK\n"
	.string "very much...$"

PerishNPCexplain::
# 1737 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you know?\p"
	.string "In competitive battles, if both players\n"
	.string "are at their final POKéMON when PERISH\l"
	.string "counts to zero, the POKéMON to faint\l"
	.string "last is declared the winner.\p"
	.string "It's based on the POKéMON's speed!\n"
	.string "Isn’t that fun?$"

Single1Puzzle_Intro::
# 1747 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you already battle against the\n"
	.string "elderly couple near the exit?\p"
	.string "I think one of their POKéMON is hiding\n"
	.string "something...$"

Single1Puzzle_Outro::
# 1754 "data/maps/EscapeRoom/scripts.pory"
	.string "Fuck.$"

Single2Puzzle_Intro::
# 1758 "data/maps/EscapeRoom/scripts.pory"
	.string "Are you a skill trader?\n"
	.string "You should probably invest more time\l"
	.string "into learning battle strategy!$"

Single2Puzzle_Outro::
# 1764 "data/maps/EscapeRoom/scripts.pory"
	.string "Shut up and take my money.$"

Single3Puzzle_Intro::
# 1768 "data/maps/EscapeRoom/scripts.pory"
	.string "It looks like you're stuck!\p"
	.string "A real thief would've known when to run.$"

Single3Puzzle_Outro::
# 1773 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm not sure I would've done that.$"

Single3Puzzle_PostBattle::
# 1777 "data/maps/EscapeRoom/scripts.pory"
	.string "Sooo...\n"
	.string "It looks like you're softlocked.\p"
	.string "I can throw you back down, but I'll have\n"
	.string "to set a few things back to the way\l"
	.string "they were before.\p"
	.string "Deal?$"

YesTeleportOutMessage::
# 1786 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come back whenever you want\n"
	.string "another battle.\p"
	.string "YEET!$"

NoTeleportPleaseMessage::
# 1792 "data/maps/EscapeRoom/scripts.pory"
	.string "Uhuh, you sure?$"

MoveTutorStartMessage::
# 1796 "data/maps/EscapeRoom/scripts.pory"
	.string "Can I have your HEART SCALES?\n"
	.string "I can teach your POKéMON a new move if\l"
	.string "you'd like.$"

MoveTutorNoHeartScales::
# 1802 "data/maps/EscapeRoom/scripts.pory"
	.string "Oh you don't have any.$"

AskTeachGardevoirDisable::
# 1806 "data/maps/EscapeRoom/scripts.pory"
	.string "Once learned, you can always come back\n"
	.string "to have it replaced, free of charge.\p"
	.string "Do you want your GARDEVOIR to learn a\n"
	.string "new move?$"

MoveTutorNoSuitablePokemonMessage::
# 1813 "data/maps/EscapeRoom/scripts.pory"
	.string "Sorry, I only teach moves a GARDEVOIR\n"
	.string "could learn.$"

MoveTutorTradeDeclined::
# 1817 "data/maps/EscapeRoom/scripts.pory"
	.string "Come back if you change your mind.$"

MoveTutorTaughtMove::
# 1821 "data/maps/EscapeRoom/scripts.pory"
	.string "Feel free to come back if you want it\n"
	.string "changed.$"

MoveTutorReplaceMove::
# 1826 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace one of the moves I\l"
	.string "taught previously?$"

MoveTutorReplaceSingleMove::
# 1832 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't have any HEART SCALES left.\n"
	.string "Should I replace the move I taught\l"
	.string "previously?$"

MoveTutorBringReplaceMonMessage::
# 1838 "data/maps/EscapeRoom/scripts.pory"
	.string "You don't seem to have the right\n"
	.string "POKéMON with you.$"

MoveTutorWhichMoveReplaceMessage::
# 1843 "data/maps/EscapeRoom/scripts.pory"
	.string "Which move would you like to replace?$"

BikeShopHelloMessage::
# 1847 "data/maps/EscapeRoom/scripts.pory"
	.string "Yes, I'm still working...\n"
	.string "How can I help you?$"

BikeShoptGoodbyeMessage::
# 1852 "data/maps/EscapeRoom/scripts.pory"
	.string "Please come again!$"

QuietTurnNPCMessage::
# 1856 "data/maps/EscapeRoom/scripts.pory"
	.string "Do not strike, do not flee,\n"
	.string "one quiet turn could set you free.$"

NuggetNPCmessage::
# 1861 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you seen my NUGGET???\p"
	.string "I guess not...\n"
	.string "I'll leaf it be.$"

GetUsOutNPCMessage::
# 1867 "data/maps/EscapeRoom/scripts.pory"
	.string "Please get us out of here...$"

SalazzleCatchingHint::
# 1871 "data/maps/EscapeRoom/scripts.pory"
	.string "Every time I've tried to catch SALAZZLE\n"
	.string "it managed to escape.\p"
	.string "It's just mocking me at this point.$"

someoneLockedUsUpNPCmessage::
# 1878 "data/maps/EscapeRoom/scripts.pory"
	.string "Someone locked us in this cave for some\n"
	.string "stupid puzzle or whatever.\p"
	.string "What an asshole.$"

perfectSmeargleHintNPCmessage::
# 1884 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE?\n"
	.string "That's gotta be a moveset thing, right?$"

icePuzzleHintNPCmessage::
# 1889 "data/maps/EscapeRoom/scripts.pory"
	.string "That ice puzzle looks tough!\n"
	.string "Don't expect to solve it right away.$"

StopWinningNPCmessage::
# 1896 "data/maps/EscapeRoom/scripts.pory"
	.string "Haha you suck. Just give up!$"

NewGreatBallMessage::
# 1900 "data/maps/EscapeRoom/scripts.pory"
	.string "You recover the Great Ball.$"

HandOverHeartScale::
# 1904 "data/maps/EscapeRoom/scripts.pory"
	.string "{PLAYER} handed over one HEART SCALE\n"
	.string "in exchange.$"

NewPechaBerryMessage::
# 1909 "data/maps/EscapeRoom/scripts.pory"
	.string "You suddenly find another berry in your\n"
	.string "pocket.$"

ThanksMomMessage::
# 1914 "data/maps/EscapeRoom/scripts.pory"
	.string "How did that get there?$"

PressStartSignMessage::
# 1918 "data/maps/EscapeRoom/scripts.pory"
	.string "Press START during a double battle to\n"
	.string "view your POKéMON's exact HP.$"

Single4IntroMessage::
# 1923 "data/maps/EscapeRoom/scripts.pory"
	.string "Oops, I picked the last berries.\n"
	.string "Why don't you come and take them?$"

Single4OutroMessage::
# 1928 "data/maps/EscapeRoom/scripts.pory"
	.string "Did you really win?$"

single4PostMatchMessage::
# 1932 "data/maps/EscapeRoom/scripts.pory"
	.string "I'm ready for a rematch whenever you\n"
	.string "want!$"

Single2Puzzle_PostBattle::
# 1937 "data/maps/EscapeRoom/scripts.pory"
	.string "CURSOLA is a great singer, don't you\n"
	.string "agree?\p"
	.string "Maybe SMEARGLE should follow her lead.$"

Single1Puzzle_PostBattle::
# 1943 "data/maps/EscapeRoom/scripts.pory"
	.string "Remember turning your POKéMON into a\n"
	.string "ghost type?\p"
	.string "That was fun.$"

ExitCloseNPCMessage::
# 1949 "data/maps/EscapeRoom/scripts.pory"
	.string "We're so close, the exit is right there!$"

PainSplitHintNPCMessage::
# 1953 "data/maps/EscapeRoom/scripts.pory"
	.string "Time is not for sale, but generosity can\n"
	.string "earn you a moment.\p"
	.string "Sharing is caring.$"

BerryTreeHintNPCMessage::
# 1959 "data/maps/EscapeRoom/scripts.pory"
	.string "What happened to that berry tree?\p"
	.string "Such a shame, it could have been so\n"
	.string "useful against the old timers.$"

TormentHintNPCMessage::
# 1965 "data/maps/EscapeRoom/scripts.pory"
	.string "I used to get tormented by my brothers.\p"
	.string "I tried to avoid it at first, but after a\n"
	.string "while you just accept it and play along.$"

SketchHintNPCMessage::
# 1971 "data/maps/EscapeRoom/scripts.pory"
	.string "You can learn so much by copying those\n"
	.string "with experience.$"

Question1Message::
# 1975 "data/maps/EscapeRoom/scripts.pory"
	.string "1. Exactly one of statement 2 and 4 is\n"
	.string "false.$"

Question2Message::
# 1979 "data/maps/EscapeRoom/scripts.pory"
	.string "2. Both statements 1 and 3 are true.$"

Question3Message::
# 1983 "data/maps/EscapeRoom/scripts.pory"
	.string "3. At least two statements are false.$"

Question4Message::
# 1987 "data/maps/EscapeRoom/scripts.pory"
	.string "4. GARDEVOIR must use DISABLE to beat\n"
	.string "Expert Roel.$"

AntiSoftlockIntroMessage::
# 1992 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "I can roll back actions that have the\n"
	.string "possibility to get you softlocked.\p"
	.string "However, I will NOT specify whether you\n"
	.string "are actually softlocked or not.$"

AntiSoftlockNoActionMessage::
# 2000 "data/maps/EscapeRoom/scripts.pory"
	.string "There's nothing I can do for you right\n"
	.string "now.$"

AntiSoftlockDeclinedMessage::
# 2005 "data/maps/EscapeRoom/scripts.pory"
	.string "Alright.$"

AskReleaseSmeargleMessage::
# 2009 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Catching a 'wrong' SMEARGLE could leave\n"
	.string "you softlocked.\p"
	.string "Should I release this SMEARGLE and give\n"
	.string "back your GREAT BALL?$"

UndoRareCandyMessage::
# 2017 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Giving the RARE CANDY to the wrong\n"
	.string "POKéMON could leave you softlocked.\p"
	.string "Should I undo the level-up and give back\n"
	.string "your RARE CANDY?$"

UndoSketchMessage::
# 2025 "data/maps/EscapeRoom/scripts.pory"
	.string "Hi, I'm the anti-softlock guy.\p"
	.string "Sketching the wrong move with SMEARGLE\n"
	.string "could leave you softlocked.\p"
	.string "Should I revert your latest SKETCH?$"

SmeargleForgotMove::
# 2032 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle forgot its latest move...$"

SmeargleLearnedSketch::
# 2036 "data/maps/EscapeRoom/scripts.pory"
	.string "Smeargle learned Sketch!$"

Double2IntroMessage::
# 2040 "data/maps/EscapeRoom/scripts.pory"
	.string "We really appreciate your out-of-the-\n"
	.string "box approach.$"

Double2OutroMessage::
# 2045 "data/maps/EscapeRoom/scripts.pory"
	.string "Ehhh... What.$"

Double2PostMatchMessage::
# 2049 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you were supposed to win\n"
	.string "this battle.$"

HintsIntroMessage::
# 2056 "data/maps/EscapeRoom/scripts.pory"
	.string "Need help? I can give you a hint at the\n"
	.string "cost of getting time added to your\l"
	.string "in-game clock.\p"
	.string "The amount will depend on the type of\n"
	.string "hint that you select.\p"
	.string "Do you want to get a hint right now?$"

HintsNPCNoTimeAddedMessage::
# 2065 "data/maps/EscapeRoom/scripts.pory"
	.string "You've already received this hint so\n"
	.string "no time was added to your clock.$"

HintsNPC20minAddedMessage::
# 2070 "data/maps/EscapeRoom/scripts.pory"
	.string "20 minutes were added to your clock.$"

HintsNPC10minAddedMessage::
# 2074 "data/maps/EscapeRoom/scripts.pory"
	.string "10 minutes were added to your clock.$"

HintsNPCNoHintMessage::
# 2081 "data/maps/EscapeRoom/scripts.pory"
	.string "I'll be here if you need me.$"

HintsNPCWhatKindOfHintMessage::
# 2085 "data/maps/EscapeRoom/scripts.pory"
	.string "What kind of hint would you like?$"

HintsNPC_GreatBall::
# 2089 "data/maps/EscapeRoom/scripts.pory"
	.string "This item is accessible from the start.\p"
	.string "You should further explore the room\n"
	.string "with the plants.$"

HintsNPC_Nugget::
# 2095 "data/maps/EscapeRoom/scripts.pory"
	.string "It's inside an item ball, but the ball\n"
	.string "itself may be hard to see.\p"
	.string "Did the NUGGET guy mention leafs?$"

HintsNPC_IcePuzzle::
# 2101 "data/maps/EscapeRoom/scripts.pory"
	.string "At the beginning, only the berry tree is\n"
	.string "accessible. The item ball is unreachable\l"
	.string "until the MACH BIKE is obtained.$"

HintsNPC_StrengthPuzzle::
# 2107 "data/maps/EscapeRoom/scripts.pory"
	.string "The puzzle revolves around breaking the\n"
	.string "ROCK SMASH rocks in the correct order.\p"
	.string "1. Break the two center rocks.\p"
	.string "2. Break the two rocks south-west.\p"
	.string "3. Break the last rock on the east.\p"
	.string "Think about how you want to access this\n"
	.string "last smashable rock on the east.$"

HintsNPC_StatementsPuzzle::
# 2117 "data/maps/EscapeRoom/scripts.pory"
	.string "Solve the puzzle in order to figure out\n"
	.string "if the 4th statement is true or false,\l"
	.string "not the other way around!\p"
	.string "You'll find that statement 4 will have\n"
	.string "only one possible answer.$"

HintsNPC_CatchingSmeargle::
# 2125 "data/maps/EscapeRoom/scripts.pory"
	.string "The perfect SMEARGLE will have the move\n"
	.string "SKETCH, which only has 1pp.\p"
	.string "If you stall a turn by not attacking,\n"
	.string "SMEARGLE will no longer be able to copy\l"
	.string "the wrong move.\p"
	.string "Consider visiting SALAZZLE first.$"

HintsNPC_TrainerRoseUn::
# 2134 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to find a way to take the item\n"
	.string "without winning the battle.\p"
	.string "In other words: try to avoid taking the\n"
	.string "FINAL GAMBIT from ZANGOOSE.\p"
	.string "Keep in mind that HIDDEN POWER's typing\n"
	.string "may depend on the POKéMON using it.\p"
	.string "It's okay to give up.$"

HintsNPC_TrainerDSAbel::
# 2144 "data/maps/EscapeRoom/scripts.pory"
	.string "The right moves on SMEARGLE and\n"
	.string "GARDEVOIR will help defeat the SLAKING.\p"
	.string "However, CURSOLA will need to be given a\n"
	.string "hindering ability to slow it down.\p"
	.string "Are you a skill trader?$"

HintsNPC_TrainerRoel::
# 2152 "data/maps/EscapeRoom/scripts.pory"
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
# 2164 "data/maps/EscapeRoom/scripts.pory"
	.string "Can you steal her SITRUS BERRY?\p"
	.string "SKILL SWAP is your friend, and perhaps\n"
	.string "there's a way to render DOUBLE EDGE\l"
	.string "completely useless.\p"
	.string "Two ways actually.$"

HintsNPC_TrainersPeeSea::
# 2172 "data/maps/EscapeRoom/scripts.pory"
	.string "This battle looks impossible to win.\n"
	.string "Can you find a way to skip this battle?\p"
	.string "Try thinking inside the box.$"

HintsNPC_TrainersJanNan::
# 2178 "data/maps/EscapeRoom/scripts.pory"
	.string "PAIN SPLIT can be used against your own\n"
	.string "POKéMON, and SCRAFTY's ability can be\l"
	.string "turned against itself.\p"
	.string "Don't forget the PERISH tiebreaker.\n"
	.string "Is there an item you haven't used yet?$"

HintsNPC_DoSalazzleThief::
# 2186 "data/maps/EscapeRoom/scripts.pory"
	.string "Check out the SALAZZLE in the cave\n"
	.string "below!$"

HintsNPC_DoRoseUn::
# 2191 "data/maps/EscapeRoom/scripts.pory"
	.string "You should battle Rose Un, the KECLEON\n"
	.string "trainer.\p"
	.string "There may be something you can get from\n"
	.string "that fight.$"

HintsNPC_DoPCCheck::
# 2198 "data/maps/EscapeRoom/scripts.pory"
	.string "You've missed an item located around the\n"
	.string "plant room!$"

HintsNPC_DoIcePuzzle::
# 2203 "data/maps/EscapeRoom/scripts.pory"
	.string "There's a berry tree in the ice puzzle.\n"
	.string "It might be a useful item when trying to\l"
	.string "catch the perfect SMEARGLE.$"

HintsNPC_DoStrengthPuzzle::
# 2209 "data/maps/EscapeRoom/scripts.pory"
	.string "The STRENGTH puzzle in the Tiny Cave\n"
	.string "down south is still unsolved.\p"
	.string "It could be worth trying.$"

HintsNPC_DoSmeargleCatch::
# 2215 "data/maps/EscapeRoom/scripts.pory"
	.string "You are ready to catch the perfect\n"
	.string "SMEARGLE.\p"
	.string "Talk to the person in the plants room to\n"
	.string "validate your catch.\p"
	.string "Think about which move your SMEARGLE\n"
	.string "should carry in the end.$"

HintsNPC_DoDSAbel::
# 2224 "data/maps/EscapeRoom/scripts.pory"
	.string "You should look to beat DS. Abel, the\n"
	.string "SLAKING trainer.\p"
	.string "Find the right movesets for SMEARGLE\n"
	.string "and GARDEVOIR to do so.$"

HintsNPC_DoPlantCheck::
# 2231 "data/maps/EscapeRoom/scripts.pory"
	.string "Have you checked the plant room?\p"
	.string "There might be another item hidden\n"
	.string "somewhere around that room.$"

HintsNPC_DoGetHeartScale::
# 2237 "data/maps/EscapeRoom/scripts.pory"
	.string "There's a bike obstacle near DS. ABEL,\n"
	.string "the Slaking trainer you just defeated.\p"
	.string "Did you already get the bike?$"

HintsNPC_DoStatementPuzzle::
# 2243 "data/maps/EscapeRoom/scripts.pory"
	.string "You can solve the statements puzzle!\p"
	.string "It could help you reach the item ball in\n"
	.string "the cave below us.$"

HintsNPC_DoBeatRoel::
# 2249 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to get past trainer Roel.\n"
	.string "To do so, SMEARGLE must first SKETCH\l"
	.string "the right move.\p"
	.string "Did you find what the old couple's\n"
	.string "POKéMON are hiding?$"

HintsNPC_DoGePastPeeSea::
# 2257 "data/maps/EscapeRoom/scripts.pory"
	.string "You have to find a way to get past the\n"
	.string "Pee & Sea double battle.$"

HintsNPC_DoStealSitrus::
# 2262 "data/maps/EscapeRoom/scripts.pory"
	.string "C. Trish's SCORBUNNY has a berry that'd\n"
	.string "be quite helpful in the final battle.\p"
	.string "Can you steal it?$"

HintsNPC_DoBeatJanNan::
# 2268 "data/maps/EscapeRoom/scripts.pory"
	.string "You are ready for the final battle!\p"
	.string "Can GARDEVOIR keep SMEARGLE alive for\n"
	.string "long enough?$"

HintsNPC_DoNothingUrDone::
# 2274 "data/maps/EscapeRoom/scripts.pory"
	.string "I don't think you need any additional\n"
	.string "hints.$"
