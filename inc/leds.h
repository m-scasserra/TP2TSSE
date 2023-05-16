#ifndef LEDS_H
#define LEDS_H

#include <stdint.h>
#include <stdbool.h>

void ledsInit(uint16_t *direccion);

void ledsTurnOnSingle(uint8_t led);

void ledsTurnOffSingle(uint8_t led);

void ledsTurnOnAll(void);

void ledsTurnOffAll(void);

bool ledsCheckTurnOn(uint8_t led);

bool ledsCheckTurnOff(uint8_t led);

bool ledsCheckTurnOnAll(void);

bool ledsCheckTurnOffAll(void);

#endif