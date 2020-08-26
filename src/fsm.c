#include "common.h"
#include "fsm.h"


static FsmFunc_t *funcs[NUM_FSM_STATES] = {NULL};


void fsm_assignFunc(FsmState_t state, FsmFunc_t *func)
{
	funcs[state] = func;
}


FsmState_t fsm_runState(FsmState_t state, void *args)
{
	//TODO: put loop here instead?
	return (*(funcs[state]))(args);
}