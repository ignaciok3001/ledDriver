
#include "ledDriver.h"
#include <stdint.h>

uint16_t ledNro = 1, LedIsOn =0;

void ledDriver_create(uint16_t *address) {
	*address = 0;
}
void ledDriver_Turn_On_LED(uint16_t *address, uint16_t ledNro){

	if ( (ledNro > 0) && (ledNro <=16) ){
		*address |= 0x0001 << (ledNro-1); /*Desplazo el bit de 1 prender 1 y con OR los enciendo,
		*									 sin modificar los otros.*/



	}


}
void ledDriver_Turn_Off_LED(uint16_t *address, uint16_t ledNro){

	if ( (ledNro > 0) && (ledNro <=16) )
		*address &= !(0x0001 << (ledNro-1)); // Con 0 y AND los apago individualmente

}

void ledDriver_Turn_On_All(uint16_t *address){

	*address = 0xFFFF;
}

void ledDriver_Turn_Off_All(uint16_t *address){

	*address = 0x0000;
}


uint16_t ledDriver_Status(uint16_t *address, uint16_t ledNro){

	uint16_t ledIsOn = 0;

	ledIsOn = 0x0001 << (ledNro-1); // Levanta el bit a interrogar

	ledIsOn &= *address; // Pregunto por el bit de led

	if (ledIsOn > 0)
		ledIsOn = 1;
	else ledIsOn = 0;

	return ledIsOn;

}
