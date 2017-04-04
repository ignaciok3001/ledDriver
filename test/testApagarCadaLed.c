/*
 * testApagarCadaLed.c
 *
 *  Created on: Apr 3, 2017
 *      Author: igna
 */
#include "unity.h"
#include "ledDriver.h"

void setUp() {

}

void tearDown() {
	address = 0;
}

void testDriverLeds() {

	address = 0xFFFF;
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0, address);
}

void testDriver_Apagar_Cada_LED() {
	//uint_16_t i;

	leds = !0x0001;
	//for ( uint16_t i = 1; i <= 16; i++) {
		//address = 0;
	ledDriver_Turn_Off_LEDS(&address,leds);
		TEST_ASSERT_EQUAL_HEX16(leds, address);
		//leds = leds << i;
	//}

	address = 0;
	leds = !0x0004;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	address = 0;
	leds = !0x0008;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	address = 0;
	leds = !0x0010;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	address = 0;
	leds = !0x8000;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

}
