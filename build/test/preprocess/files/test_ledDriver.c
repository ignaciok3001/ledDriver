#include "ledDriver.h"
#include "unity.h"




uint16_t address, led;



uint16_t estadoDeledsEnBit = 0;



void setUp() {



}



void tearDown() {

 address = 0;

}







void testDriverCreateDebeApagarTodosLosLeds() {



 address = 0xFFFF;

 ledDriver_create(&address);



 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_HEX16);

}





void testDriver_Prender_Cada_LED() {

 uint16_t i;



 tearDown();



 estadoDeledsEnBit = 1;

 for ( i = 1; i <= 16; i++) {

  tearDown();

  ledDriver_Turn_On_LED(&address,led);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((led)), (UNITY_INT)(UNITY_INT16)((address)), (

 ((void *)0)

 ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_HEX16);

  estadoDeledsEnBit = estadoDeledsEnBit << 1;

 }





}







void testDriver_Apagar_Cada_LED() {

 uint16_t i, led;



 tearDown();

 estadoDeledsEnBit = 1;

 for ( i = 1; i <= 16; i++) {

  tearDown();

  estadoDeledsEnBit = !estadoDeledsEnBit;

     ledDriver_Turn_Off_LED(&address,i);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

 ((void *)0)

 ), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_HEX16);

  estadoDeledsEnBit = !estadoDeledsEnBit;

  estadoDeledsEnBit = estadoDeledsEnBit << 1;



 }





}







void testDriver_OnOff_Multiple(){

 estadoDeledsEnBit = 0x1111;

 tearDown();

 ledDriver_Turn_On_LED(&address,1);

 ledDriver_Turn_On_LED(&address,5);

 ledDriver_Turn_On_LED(&address,9);

 ledDriver_Turn_On_LED(&address,13);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_HEX16);

 estadoDeledsEnBit = 0x0000;

 ledDriver_Turn_Off_LED(&address,1);

 ledDriver_Turn_Off_LED(&address,5);

 ledDriver_Turn_Off_LED(&address,9);

 ledDriver_Turn_Off_LED(&address,13);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);



 estadoDeledsEnBit = 0x2222;

 tearDown();

 ledDriver_Turn_On_LED(&address,2);

 ledDriver_Turn_On_LED(&address,6);

 ledDriver_Turn_On_LED(&address,10);

 ledDriver_Turn_On_LED(&address,14);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX16);

 estadoDeledsEnBit = 0x0000;

 ledDriver_Turn_Off_LED(&address,2);

 ledDriver_Turn_Off_LED(&address,6);

 ledDriver_Turn_Off_LED(&address,10);

 ledDriver_Turn_Off_LED(&address,14);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);



 estadoDeledsEnBit = 0x4444;

 tearDown();

 ledDriver_Turn_On_LED(&address,3);

 ledDriver_Turn_On_LED(&address,7);

 ledDriver_Turn_On_LED(&address,11);

 ledDriver_Turn_On_LED(&address,15);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(101), UNITY_DISPLAY_STYLE_HEX16);

 estadoDeledsEnBit = 0x0000;

 ledDriver_Turn_Off_LED(&address,3);

 ledDriver_Turn_Off_LED(&address,7);

 ledDriver_Turn_Off_LED(&address,11);

 ledDriver_Turn_Off_LED(&address,15);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(107), UNITY_DISPLAY_STYLE_HEX16);



 estadoDeledsEnBit = 0x8888;

 tearDown();

 ledDriver_Turn_On_LED(&address,4);

 ledDriver_Turn_On_LED(&address,8);

 ledDriver_Turn_On_LED(&address,12);

 ledDriver_Turn_On_LED(&address,16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_HEX16);

 estadoDeledsEnBit = 0x0000;

 ledDriver_Turn_Off_LED(&address,4);

 ledDriver_Turn_Off_LED(&address,8);

 ledDriver_Turn_Off_LED(&address,12);

 ledDriver_Turn_Off_LED(&address,16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_HEX16);



}







void testDriver_Off_All(){



 tearDown();

 estadoDeledsEnBit = 0x0000;

 ledDriver_Turn_Off_All(&address);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_HEX16);



}







void testDriver_On_All(){



 tearDown();

 estadoDeledsEnBit = 0xFFFF;

 ledDriver_Turn_On_All(&address);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_HEX16);



}







void testDriver_Status_LED(){

 uint16_t bitPrendido;



 tearDown();



 ledDriver_Turn_On_LED(&address,4);

 bitPrendido=ledDriver_Status(&address,4);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(156), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_On_LED(&address,8);

 bitPrendido=ledDriver_Status(&address,8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_On_LED(&address,12);

 bitPrendido=ledDriver_Status(&address,12);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(164), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_On_LED(&address,16);

 bitPrendido=ledDriver_Status(&address,16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(168), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_Off_LED(&address,4);

 bitPrendido=ledDriver_Status(&address,4);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_Off_LED(&address,8);

 bitPrendido=ledDriver_Status(&address,8);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(176), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_Off_LED(&address,12);

 bitPrendido=ledDriver_Status(&address,12);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(180), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_Off_LED(&address,16);

 bitPrendido=ledDriver_Status(&address,16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((bitPrendido)), (

((void *)0)

), (UNITY_UINT)(184), UNITY_DISPLAY_STYLE_HEX16);





}







void testDriver_Verif_Inside_Limit(){



 tearDown();

 address = 0x8000;

 estadoDeledsEnBit = address;

 ledDriver_Turn_On_LED(&address,16);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(197), UNITY_DISPLAY_STYLE_HEX16);



 tearDown();

 address = 0x0001;

 estadoDeledsEnBit = address;

 ledDriver_Turn_On_LED(&address,1);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((estadoDeledsEnBit)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(203), UNITY_DISPLAY_STYLE_HEX16);



}







void testDriver_Verif_Outside_Limit(){



 uint32_t nroFueraDeRango = 0x000FFFFF;

 tearDown();



 ledDriver_Turn_On_LED(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(215), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_On_All(&address);

 ledDriver_Turn_Off_LED(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(219), UNITY_DISPLAY_STYLE_HEX16);



 nroFueraDeRango = 0x0000;

 tearDown();

 ledDriver_Turn_On_LED(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(224), UNITY_DISPLAY_STYLE_HEX16);



 ledDriver_Turn_On_All(&address);

 ledDriver_Turn_Off_LED(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(228), UNITY_DISPLAY_STYLE_HEX16);

}
