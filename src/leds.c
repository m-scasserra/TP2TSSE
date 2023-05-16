#include "leds.h"

#define INDEX_OFFSET 1
#define FIRST_BIT 1
#define ALL_LEDS_OFF 0x0000
#define ALL_LEDS_ON 0xFFFF

static uint16_t *puerto_virtual;

uint16_t IndexToMask(uint8_t led){
    return (FIRST_BIT << (led - INDEX_OFFSET));
}

bool ValueIndex(uint8_t led){
    return (*puerto_virtual &= IndexToMask(led));
}

void ledsInit(uint16_t *direccion){
    puerto_virtual = direccion;
    *direccion = ALL_LEDS_OFF;
}

void ledsTurnOnSingle(uint8_t led){
    *puerto_virtual |= IndexToMask(led);
}

void ledsTurnOffSingle(uint8_t led){
    *puerto_virtual &= ~IndexToMask(led); 
}

void ledsTurnOnAll(void){
    *puerto_virtual = ALL_LEDS_ON;
}

void ledsTurnOffAll(void){
    *puerto_virtual = ALL_LEDS_OFF;
}

bool ledsCheckTurnOn(uint8_t led){
    return ValueIndex(led) & ALL_LEDS_ON;
}

bool ledsCheckTurnOff(uint8_t led){
    return !ValueIndex(led) | ALL_LEDS_OFF;
}

bool ledsCheckTurnOnAll(void){
    return !((~*puerto_virtual) & ALL_LEDS_ON);
}

bool ledsCheckTurnOffAll(void){
    return !*puerto_virtual | ALL_LEDS_OFF;
}