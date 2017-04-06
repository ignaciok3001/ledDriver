
#include <stdint.h>

void ledDriver_create(uint16_t *);
void ledDriver_Turn_On_LED(uint16_t *, uint16_t);
void ledDriver_Turn_Off_LED(uint16_t *, uint16_t);
void ledDriver_Turn_On_All(uint16_t *);
void ledDriver_Turn_Off_All(uint16_t *);
uint16_t ledDriver_Status(uint16_t *, uint16_t);
