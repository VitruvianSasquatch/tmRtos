#ifndef FSM_H
#define FSM_H


#define FSM_MAX_NUM_PROCESSES 256

typedef struct Fsm_s Fsm_t;
typedef struct FsmState_s FsmState_t;
typedef FsmState_t (FsmFunc_t)(void *);

typedef struct {
	bool isLockstep;
	size_t numInProcesses;
	size_t numOutProcesses;
	FsmState_t *outStates[];
} FsmTrans_t;


struct FsmState_s{
	Fsm_t *subFsm;
	FsmFunc_t *func;
	
	FsmTrans_t *transitions[];
};




struct Fsm_s {
	Fsm_t *parent;
	FsmState_t end;
	size_t numStates;
	FsmState_t *states[];
};



void fsm_run(Fsm_t *fsm, FsmState_t *startState);



Fsm_t *fsm_newFsm(size_t numStates);


void fsm_assignFunc(Fsm_t *fsm, FsmState_t state, FsmFunc_t *func);


FsmState_t fsm_runState(Fsm_t *fsm, FsmState_t state, void *args);


#endif //FSM_H