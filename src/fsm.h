#ifndef FSM_H
#define FSM_H


typedef size_t FsmState_t;
typedef FsmState_t FsmFunc_t(void *);
typedef struct Fsm_s Fsm_t;

typedef struct {
	Fsm_t *subFsm;
	FsmFunc_t *func;
} FsmNode_t;

struct Fsm_s{
	size_t numStates;
	FsmNode_t states[];
};




Fsm_t *fsm_newFsm(size_t numStates);


void fsm_assignFunc(Fsm_t *fsm, FsmState_t state, FsmFunc_t *func);


FsmState_t fsm_runState(Fsm_t *fsm, FsmState_t state, void *args);


#endif //FSM_H