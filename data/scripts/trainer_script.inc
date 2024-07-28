Std_RegisteredInMatchCall::
	buffertrainerclassname STR_VAR_1, VAR_0x8000
	buffertrainername STR_VAR_2, VAR_0x8000
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox gText_RegisteredTrainerinPokeNav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	return

EventScript_TryGetTrainerScript::
	goto_if_set FLAG_RAN_FROM_TRAINER, EventScript_TryGetTrainerScript_Cont
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, TRUE, EventScript_GotoTrainerScript
EventScript_TryGetTrainerScript_Cont:
	releaseall
	end

EventScript_GotoTrainerScript::
	gotobeatenscript
	releaseall
	end
