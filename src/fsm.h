#ifndef FSM_H
#define FSM_H




typedef size_t FsmStateId_t;
typedef FsmState_t FsmFunc_t(void *);

typedef struct {
	bool isLockstep;
	size_t numInProcesses;
	size_t numOutProcesses;
	FsmState_t *outStates[];
} FsmTrans_t;


typedef struct {
	Fsm_t *subFsm;
	FsmFunc_t *func;
	
	FsmTrans_t *transitions[];
} FsmState_t;

typedef struct{
	FsmState_t start;
	FsmState_t end;
	size_t numStates;
	FsmState_t *states[];
} Fsm_t;




Fsm_t *fsm_newFsm(size_t numStates);


void fsm_assignFunc(Fsm_t *fsm, FsmState_t state, FsmFunc_t *func);


FsmState_t fsm_runState(Fsm_t *fsm, FsmState_t state, void *args);


#endif //FSM_H