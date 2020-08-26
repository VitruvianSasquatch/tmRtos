#include <Arduino.h>

#include "common.h"

#include "fsm.h"




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