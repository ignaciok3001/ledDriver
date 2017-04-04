#include "ledDriver.h"
#include "unity.h"




uint16_t address,leds;



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

), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_HEX16);

}



void testDriver_Prender_Cada_LED() {

 uint16_t i;



 tearDown();



 leds = 0x0001;

 for ( i = 1; i <= 16; i++) {

  tearDown();

  ledDriver_Turn_On_LEDS(&address,leds);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_HEX16);

  leds = leds << 1;

 }





}



void testDriver_Apagar_Cada_LED() {

 uint16_t i;



 tearDown();

 leds = 0x0001;

 for ( i = 1; i <= 16; i++) {

  tearDown();

  leds = !leds;

     ledDriver_Turn_Off_LEDS(&address,leds);

  UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

 ((void *)0)

 ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_HEX16);

  leds = !leds;

  leds = leds << 1;

 }





}



void testDriver_OnOff_Multiple(){

 leds = 0x1111;

 tearDown();

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(60), UNITY_DISPLAY_STYLE_HEX16);

 leds = 0x0000;

 ledDriver_Turn_Off_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_HEX16);



 leds = 0x2222;

 tearDown();

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_HEX16);

 leds = 0x0000;

 ledDriver_Turn_Off_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(71), UNITY_DISPLAY_STYLE_HEX16);



 leds = 0x4444;

 tearDown();

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_HEX16);

 leds = 0x0000;

 ledDriver_Turn_Off_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(79), UNITY_DISPLAY_STYLE_HEX16);



 leds = 0x8888;

 tearDown();

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX16);

 leds = 0x0000;

 ledDriver_Turn_Off_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(87), UNITY_DISPLAY_STYLE_HEX16);



}



void testDriver_Off_All(){



 tearDown();

 leds = 0x0000;

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_HEX16);



}



void testDriver_On_All(){



 tearDown();

 leds = 0xFFFF;

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_HEX16);



}



void testDriver_Status_LED(){



 tearDown();





}



void testDriver_Verif_Inside_Limit(){



 tearDown();

 leds = 0xFFFF;

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(121), UNITY_DISPLAY_STYLE_HEX16);



 tearDown();

 leds = 0xFFFF;

 ledDriver_Turn_On_LEDS(&address,leds);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((leds)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(126), UNITY_DISPLAY_STYLE_HEX16);



}



void testDriver_Verif_Outside_Limit(){



 uint32_t nroFueraDeRango = 0x000FFFFF;

 tearDown();



 ledDriver_Turn_On_LEDS(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_HEX16);



 tearDown();

 nroFueraDeRango = 0xF0000000;



 ledDriver_Turn_On_LEDS(&address,nroFueraDeRango);

 UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((address)), (

((void *)0)

), (UNITY_UINT)(142), UNITY_DISPLAY_STYLE_HEX16);

}
