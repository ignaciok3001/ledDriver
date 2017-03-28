/*
 * test_ledDriver.c
 *
 *  Created on: Mar 27, 2017
 *      Author: igna
 */
#include "unity.h"
#include "ledDriver.h"

uint16_t address;

void setUp(){

}

void tearDown(){
	address = 0; //para tener en 0 el registro de los leds en cada test
}

void testDriverCreateDebeApagarTodosLosLeds(){

	address = 0xFFFF; //Prendo todos los leds para probar
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0,address); //lo esperado vs lo evaluado
	TEST_ASSERT_NOT_EQUAL(0,address);
}
