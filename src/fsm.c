#include "common.h"
#include "fsm.h"


Fsm_t *fsm_newFsm(size_t numStates)
{
	Fsm_t *fsm = malloc(2*sizeof(FsmState_t) + sizeof(size_t) + numStates*sizeof(FsmNode_t));
	fsm->numStates = numStates;
	return fsm;
}



void fsm_assignFunc(Fsm_t *fsm, FsmState_t state, FsmFunc_t *func)
{
	fsm->states[state].func = func;
}



FsmState_t fsm_run(Fsm_t *fsm, FsmState_t start, void *args)
{
	FsmState_t state = start;
	if (fsm->states[state].func) {
		return (*(fsm->states[state].func))(args); //Can't have the loop here; must have it in the specific function. 
	} else if (fsm->states[state].subFsm)
		return fsm_run(fsm->states[state].subFsm, 0, args); //Nested funcs isn't great. Assume starting 
	}
}