
#include "unity.h"
#include "ledDriver.h"

uint16_t address,leds; //leds conviene que sea signado para rotar los bits con signo desde la izq

void setUp() {

}

void tearDown() {
	address = 0;
}

void testDriverCreateDebeApagarTodosLosLeds() {

	address = 0xFFFF;
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0, address);
}

void testDriver_Prender_Cada_LED() {
	uint16_t i;

	tearDown();

	leds = 0x0001;
	for ( uint16_t i = 1; i <= 16; i++) {
		tearDown();
		ledDriver_Turn_On_LEDS(&address,leds);
		TEST_ASSERT_EQUAL_HEX16(leds, address);
		leds = leds << 1;
	}


}

void testDriver_Apagar_Cada_LED() {
	uint16_t i;

	tearDown();
	leds = 0x0001;
	for ( uint16_t i = 1; i <= 16; i++) {
		tearDown();
		leds = !leds;
	    ledDriver_Turn_Off_LEDS(&address,leds);
		TEST_ASSERT_EQUAL_HEX16(leds, address);
		leds = !leds;
		leds = leds << 1;
	}


}

void testDriver_OnOff_Multiple(){
	leds = 0x1111;
	tearDown();
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);
	leds = 0x0000;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	leds = 0x2222;
	tearDown();
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);
	leds = 0x0000;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	leds = 0x4444;
	tearDown();
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);
	leds = 0x0000;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	leds = 0x8888;
	tearDown();
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);
	leds = 0x0000;
	ledDriver_Turn_Off_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

}

void testDriver_Off_All(){

	tearDown();
	leds = 0x0000;
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

}

void testDriver_On_All(){

	tearDown();
	leds = 0xFFFF;
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

}

void testDriver_Status_LED(){

	tearDown();




}

void testDriver_Verif_Inside_Limit(){

	tearDown();
	leds = 0xFFFF;
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

	tearDown();
	leds = 0xFFFF;
	ledDriver_Turn_On_LEDS(&address,leds);
	TEST_ASSERT_EQUAL_HEX16(leds, address);

}

void testDriver_Verif_Outside_Limit(){

	uint32_t nroFueraDeRango = 0x000FFFFF;
	tearDown();
	//leds = 0xFFFF;
	ledDriver_Turn_On_LEDS(&address,nroFueraDeRango);
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, address);

	tearDown();
	nroFueraDeRango = 0xF0000000;
	//leds = 0x0000 - 1;
	ledDriver_Turn_On_LEDS(&address,nroFueraDeRango);
	TEST_ASSERT_EQUAL_HEX16(0, address);
}
