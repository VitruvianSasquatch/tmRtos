#ifndef FSM_H
#define FSM_H


typedef struct {

} 





typedef enum {
	SETUP = 0, //Scream until jumper on. 
	TESTING, //Test as instructed until jumper off
	PAD, //Beep to confirm verticality when prompted. Transition to ARMED when button held for 5 s. 
	ARMED, //Duh. Transitions to LAUNCHED on g-spike, holds button to disarm. 
	LAUNCHED, //Complex.

	NUM_FSM_STATES
} FsmState_t;


typedef FsmState_t FsmFunc_t(void *);


void fsm_assignFunc(FsmState_t state, FsmFunc_t *func);


FsmState_t fsm_runState(FsmState_t state, void *args);


#endif //FSM_H