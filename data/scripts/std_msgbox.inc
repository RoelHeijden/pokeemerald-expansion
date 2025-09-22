Std_MsgboxNPC:
	lock
	faceplayer
	message NULL
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign:
	lockall
	message NULL
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault:
	message NULL
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo:
	message NULL
	waitmessage
	yesnobox 20, 8
	return

Std_MsgboxSoftlockGuy:
	message NULL
	waitmessage
	softlockguymovebox 30, 6, FALSE
	return

Std_MsgboxMoveDeleter:
	message NULL
	waitmessage
	movedeleterbox 30, 8, FALSE
	return

Std_MsgboxGetPoints:
	message NULL
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	waitmessage
	return

Std_MsgboxHintnpc:
	message NULL
	waitmessage
	hintnpcoptionbox 30, 6, FALSE
	return

Std_MsgboxMainSign:
	message NULL
	waitmessage
	mainsignoptionbox 30, 8, FALSE
	return


EventScript_UnusedReturn:
	return

Common_EventScript_SaveGame::
	special SaveGame
	waitstate
	return
