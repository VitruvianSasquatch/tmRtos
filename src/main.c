#include <stdio.h>
#include "common.h"

#include "fsm.h"


FsmState_t TESTING, ARMED, LAUNCHED;


FsmState_t testingState(void *args)
{
	while (1) {
		if (digitalRead(PIN_A0)) {
			return ARMED;
		}
	}
}

FsmState_t armedState(void *args)
{
	while (1) {
		if (digitalRead(PIN_A0)) {
			return LAUNCHED;
		}
	}
}


int main(void)
{

	Fsm_t *mainFsm = fsm_newFsm(NUM_MAIN_STATES);
	fsm_assignFunc(mainFsm, TESTING, &testingState);
	fsm_assignFunc(mainFsm, ARMED, &testingState);
	fsm_assignSubFsm(mainFsm, LAUNCHED, &testingState);


	while (1) {
		
	}
}