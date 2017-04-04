/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void testDriverCreateDebeApagarTodosLosLeds();
extern void testDriver_Prender_Cada_LED();
extern void testDriver_Apagar_Cada_LED();
extern void testDriver_OnOff_Multiple();
extern void testDriver_Off_All();
extern void testDriver_On_All();
extern void testDriver_Status_LED();
extern void testDriver_Verif_Inside_Limit();
extern void testDriver_Verif_Outside_Limit();


/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_ledDriver.c");
  RUN_TEST(testDriverCreateDebeApagarTodosLosLeds, 15);
  RUN_TEST(testDriver_Prender_Cada_LED, 23);
  RUN_TEST(testDriver_Apagar_Cada_LED, 39);
  RUN_TEST(testDriver_OnOff_Multiple, 56);
  RUN_TEST(testDriver_Off_All, 91);
  RUN_TEST(testDriver_On_All, 100);
  RUN_TEST(testDriver_Status_LED, 109);
  RUN_TEST(testDriver_Verif_Inside_Limit, 116);
  RUN_TEST(testDriver_Verif_Outside_Limit, 130);

  return (UnityEnd());
}
