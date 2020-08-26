#include "common.h"
#include "fsm.h"


Fsm_t *fsm_newFsm(size_t numStates)
{
	Fsm_t *fsm = malloc(sizeof(size_t) + numStates*sizeof(FsmNode_t));
	fsm->numStates = numStates;
	return fsm;
}



void fsm_assignFunc(Fsm_t *fsm, FsmState_t state, FsmFunc_t *func)
{
	fsm->states[state].func = func;
}



FsmState_t fsm_runState(Fsm_t *fsm, FsmState_t state, void *args)
{
	//TODO: put loop here instead?
	return (*(fsm->states[state].func))(args);
}