#include <Arduino.h>

#include "common.h"

#include "fsm.h"



//TODO: Replace body with actual code. 
FsmState_t rocketSetup(void *args)
{
	while (1) {
		//if jumper not in
		//scream
		//else
		//return TESTING;
		break;
	}

}


//TODO: Replace body with actual code. 
FsmState_t rocketTesting(void *args)
{
	while (1) {
		//if jumper in
			//respond to buttonPress to toggle airbrake position. 
		//else
			//return PAD;
		break;
	}

}



//TODO: Replace body with actual code. 
FsmState_t rocketToPad(void *args)
{
	while (1) {
		//if button pressed (short)
			//if vertical
				//Beep
		//else if button held (> 5 s)
			//Make some noise
			//return ARMED;
		break;
	}

}



//TODO: Replace body with actual code. 
FsmState_t rocketArmed(void *args)
{
	while (1) {
		//if button held (> 5 s)
			//Beep
			//return PAD;
		//else if IMU > 10 g
			//return LAUNCHED;
		break;
	}

}



//TODO: Replace body with actual code. 
FsmState_t rocketLaunched(void *args)
{
	while (1) {
		//Complex function. 
		break;
	}

}






void init(void)
{
	fsm_assignFunc(SETUP, &rocketSetup);
	fsm_assignFunc(TESTING, &rocketTesting);
	fsm_assignFunc(PAD, &rocketToPad);
	fsm_assignFunc(ARMED, &rocketArmed);
	fsm_assignFunc(LAUNCHED, &rocketLaunched);
}





int main(void)
{
	
	// initialize LED digital pin as an output.
	pinMode(LED_BUILTIN, OUTPUT);


	


	while (1) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(200);
		digitalWrite(LED_BUILTIN, LOW);
		delay(200);
	}
}