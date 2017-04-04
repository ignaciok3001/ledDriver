
#include "ledDriver.h"

void ledDriver_create(uint16_t *address) {
	*address = 0;
}
void ledDriver_Turn_On_LEDS(uint16_t *address, uint16_t ledsOn){

	if ( (ledsOn >= 0) && (ledsOn <=0xFFFF) ){
		*address |= ledsOn; //Con 1 y OR los enciendo
	}
	else if (ledsOn >= 0xFFFF) {
		*address = 0xFFFF;
	}
	else {
		*address = 0x0000;
	}


}
void ledDriver_Turn_Off_LEDS(uint16_t *address, uint16_t ledsOff){

	if ( (ledsOff >= 0) && (ledsOff <=0xFFFF) )
		*address &= ledsOff; // Con 0 y AND los apago individualmente
	else if (ledsOff >= 0xFFFF)
		*address = 0xFFFF;
	else
		*address = 0x0000;

}

void ledDriver_Status(uint16_t *address){

}
