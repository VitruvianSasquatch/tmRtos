#ifndef FSM_H
#define FSM_H

#include "process.h"


typedef struct Fsm_s Fsm_t;
typedef struct FsmState_s FsmState_t;
typedef int32_t FsmTransId_t;
typedef FsmTransId_t *(FsmFunc_t)(void);


typedef struct {
	bool isLockstep;
	size_t numProcesses; ///Number of processes currently at this transition. 

	size_t numInProcesses;
	Process_t **processes; //Of length numInProcesses. 
	size_t numOutProcesses;
	FsmState_t **outStates; //Requires one process to each outState. 
} FsmTrans_t;


struct FsmState_s{
	//One of the following must be NULL. 
	Fsm_t *subFsm;
	FsmFunc_t *func;
	
	size_t numTransitions;
	FsmTrans_t **transitions;
};


struct Fsm_s {
	Fsm_t *parent;
	FsmState_t *end;
	size_t numStates;
	FsmState_t *states[]; //Top-level structure can have a flexible member. 
};


/**
 * @brief Runs the top-level FSM. 
 * 
 * @param fsm The top-level FSM. 
 * @param startState The starting state. 
 */
void fsm_run(Fsm_t *fsm, FsmState_t *startState);



void fsm_stepProcess(Process_t *process);



Fsm_t *fsm_newFsm(size_t numStates);



void fsm_assignFunc(FsmState_t *state, FsmFunc_t *func);




#endif //FSM_H