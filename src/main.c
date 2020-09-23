#include <stdio.h>
#include "common.h"

#include "fsm.h"


typedef enum {
	TESTING = 0,
	ARMED, 
	LAUNCHED, 

	NUM_MAIN_STATES
} mainState;


mainState testingState(void *args)
{
	while (1) {
		if (digitalRead(PIN_A0)) {
			return ARMED;
		}
	}
}

mainState armedState(void *args)
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