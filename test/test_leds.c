#include "unity.h"
#include "leds.h"
#include <stdint.h>
#include <stdbool.h>

static uint16_t puerto_virtual;

void setUp(void){
    ledsInit(&puerto_virtual);
}


// Al iniciar la biblioteca todos los LEDS quedan apagados.
void test_todos_los_leds_inician_apagados(void){
    uint16_t puerto_virtual = 0xFFFF;
    ledsInit(&puerto_virtual);

    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

// Con todos los LEDS apagados, prendo el LED 2, verifico que el bit 1 vale 1.
void test_prender_un_led(void){
    ledsTurnOnSingle(2);

    TEST_ASSERT_EQUAL(0x0002, puerto_virtual);
}

// Con el LED 2 prendido, apago el LED 2, verifico que se enciende el bit 1 y vale 0.
void test_prender_y_apagar_un_led(void){
    ledsTurnOnSingle(2);
    ledsTurnOffSingle(2);

    TEST_ASSERT_EQUAL(0x0000, puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, prendo el 5, apago el 3 y apago el 7, deberian quedar el bit 4 en 1 y el resto en 0
void test_prender_y_apagar_varios_leds(void){
    ledsTurnOnSingle(3);
    ledsTurnOnSingle(5);
    ledsTurnOffSingle(3);
    ledsTurnOffSingle(7);

    TEST_ASSERT_EQUAL(0x0010, puerto_virtual);
}

// Prendo un LED, consulto el estado y tiene que estar prendido.
void test_prender_y_consultar_un_led(void){
    ledsTurnOnSingle(2);

    TEST_ASSERT_TRUE(ledsCheckTurnOn(2));
}


// Apago un LED, consulto el estado y tiene que estar apagado.
void test_apagar_y_consultar_un_led(void){
    TEST_ASSERT_TRUE(ledsCheckTurnOff(2));
}

// Con todos los LEDS apagados, prendo todos los LEDS y verifico que se encienden.
void test_prender_todos_y_verificar(void){
    ledsTurnOnAll();

    TEST_ASSERT_TRUE(ledsCheckTurnOnAll());
}

// Con todos los LEDS prendidos, apago todos los LEDS y verifico que se apagan.
void test_apagar_todos_y_verificar(void){
    TEST_ASSERT_TRUE(ledsCheckTurnOffAll());
}