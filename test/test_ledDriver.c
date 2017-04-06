
#include "unity.h"
#include "ledDriver.h"

uint16_t address, led; //address es la direcion de la memoria para manejar los leds
								//led es el numero de led
uint16_t estadoDeledsEnBit = 0; //cada estado de led en un nro hexa, como en la memoria al escribirlos

void setUp() {

}

void tearDown() {
	address = 0;
}

/* test 1*/

void testDriverCreateDebeApagarTodosLosLeds() {

	address = 0xFFFF;
	ledDriver_create(&address);

	TEST_ASSERT_EQUAL_HEX16(0, address);
}
/*   test 2*/

void testDriver_Prender_Cada_LED() {
	uint16_t i;

	tearDown();

	estadoDeledsEnBit = 1;
	for ( i = 1; i <= 16; i++) {
		tearDown();
		ledDriver_Turn_On_LED(&address,led);
		TEST_ASSERT_EQUAL_HEX16(led, address);
		estadoDeledsEnBit = estadoDeledsEnBit << 1;
	}


}

/*  test 3*/

void testDriver_Apagar_Cada_LED() {
	uint16_t i, led;

	tearDown();
	estadoDeledsEnBit = 1;
	for ( i = 1; i <= 16; i++) {
		tearDown();
		estadoDeledsEnBit = !estadoDeledsEnBit;
	    ledDriver_Turn_Off_LED(&address,i);
		TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);
		estadoDeledsEnBit = !estadoDeledsEnBit;
		estadoDeledsEnBit = estadoDeledsEnBit << 1;

	}


}

/* test 4*/

void testDriver_OnOff_Multiple(){
	estadoDeledsEnBit = 0x1111;
	tearDown();
	ledDriver_Turn_On_LED(&address,1);
	ledDriver_Turn_On_LED(&address,5);
	ledDriver_Turn_On_LED(&address,9);
	ledDriver_Turn_On_LED(&address,13);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);
	estadoDeledsEnBit = 0x0000;
	ledDriver_Turn_Off_LED(&address,1);
	ledDriver_Turn_Off_LED(&address,5);
	ledDriver_Turn_Off_LED(&address,9);
	ledDriver_Turn_Off_LED(&address,13);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

	estadoDeledsEnBit = 0x2222;
	tearDown();
	ledDriver_Turn_On_LED(&address,2);
	ledDriver_Turn_On_LED(&address,6);
	ledDriver_Turn_On_LED(&address,10);
	ledDriver_Turn_On_LED(&address,14);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);
	estadoDeledsEnBit = 0x0000;
	ledDriver_Turn_Off_LED(&address,2);
	ledDriver_Turn_Off_LED(&address,6);
	ledDriver_Turn_Off_LED(&address,10);
	ledDriver_Turn_Off_LED(&address,14);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

	estadoDeledsEnBit = 0x4444;
	tearDown();
	ledDriver_Turn_On_LED(&address,3);
	ledDriver_Turn_On_LED(&address,7);
	ledDriver_Turn_On_LED(&address,11);
	ledDriver_Turn_On_LED(&address,15);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);
	estadoDeledsEnBit = 0x0000;
	ledDriver_Turn_Off_LED(&address,3);
	ledDriver_Turn_Off_LED(&address,7);
	ledDriver_Turn_Off_LED(&address,11);
	ledDriver_Turn_Off_LED(&address,15);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

	estadoDeledsEnBit = 0x8888;
	tearDown();
	ledDriver_Turn_On_LED(&address,4);
	ledDriver_Turn_On_LED(&address,8);
	ledDriver_Turn_On_LED(&address,12);
	ledDriver_Turn_On_LED(&address,16);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);
	estadoDeledsEnBit = 0x0000;
	ledDriver_Turn_Off_LED(&address,4);
	ledDriver_Turn_Off_LED(&address,8);
	ledDriver_Turn_Off_LED(&address,12);
	ledDriver_Turn_Off_LED(&address,16);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

}

/* test 5 */

void testDriver_Off_All(){

	tearDown();
	estadoDeledsEnBit = 0x0000;
	ledDriver_Turn_Off_All(&address);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

}

/* test 6 */

void testDriver_On_All(){

	tearDown();
	estadoDeledsEnBit = 0xFFFF;
	ledDriver_Turn_On_All(&address);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

}

/* test 7 */

void testDriver_Status_LED(){
	uint16_t bitPrendido;

	tearDown();

	ledDriver_Turn_On_LED(&address,4);		// Prendo 4 leds y pregunto como estan
	bitPrendido=ledDriver_Status(&address,4);
	TEST_ASSERT_EQUAL_HEX16(1, bitPrendido);

	ledDriver_Turn_On_LED(&address,8);
	bitPrendido=ledDriver_Status(&address,8);
	TEST_ASSERT_EQUAL_HEX16(1, bitPrendido);

	ledDriver_Turn_On_LED(&address,12);
	bitPrendido=ledDriver_Status(&address,12);
	TEST_ASSERT_EQUAL_HEX16(1, bitPrendido);

	ledDriver_Turn_On_LED(&address,16);
	bitPrendido=ledDriver_Status(&address,16);
	TEST_ASSERT_EQUAL_HEX16(1, bitPrendido);

	ledDriver_Turn_Off_LED(&address,4);		// Apago 4 leds y pregunto como estan
	bitPrendido=ledDriver_Status(&address,4);
	TEST_ASSERT_EQUAL_HEX16(0, bitPrendido);

	ledDriver_Turn_Off_LED(&address,8);
	bitPrendido=ledDriver_Status(&address,8);
	TEST_ASSERT_EQUAL_HEX16(0, bitPrendido);

	ledDriver_Turn_Off_LED(&address,12);
	bitPrendido=ledDriver_Status(&address,12);
	TEST_ASSERT_EQUAL_HEX16(0, bitPrendido);

	ledDriver_Turn_Off_LED(&address,16);
	bitPrendido=ledDriver_Status(&address,16);
	TEST_ASSERT_EQUAL_HEX16(0, bitPrendido);


}

/* test 8 */

void testDriver_Verif_Inside_Limit(){

	tearDown();
	address = 0x8000;
	estadoDeledsEnBit = address;
	ledDriver_Turn_On_LED(&address,16);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

	tearDown();
	address = 0x0001;
	estadoDeledsEnBit = address;
	ledDriver_Turn_On_LED(&address,1);
	TEST_ASSERT_EQUAL_HEX16(estadoDeledsEnBit, address);

}

/* test 9 */

void testDriver_Verif_Outside_Limit(){

	uint32_t nroFueraDeRango = 0x000FFFFF; // Nro >  16
	tearDown();

	ledDriver_Turn_On_LED(&address,nroFueraDeRango); //No los prende
	TEST_ASSERT_EQUAL_HEX16(0, address);

	ledDriver_Turn_On_All(&address);
	ledDriver_Turn_Off_LED(&address,nroFueraDeRango); // No los apaga
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, address);

	nroFueraDeRango = 0x0000;			//Nro <  1
	tearDown();
	ledDriver_Turn_On_LED(&address,nroFueraDeRango);
	TEST_ASSERT_EQUAL_HEX16(0, address);

	ledDriver_Turn_On_All(&address);
	ledDriver_Turn_Off_LED(&address,nroFueraDeRango);
	TEST_ASSERT_EQUAL_HEX16(0xFFFF, address);
}
