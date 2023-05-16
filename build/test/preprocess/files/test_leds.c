#include "inc/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint16_t puerto_virtual;



void setUp(void){

    ledsInit(&puerto_virtual);

}







void test_todos_los_leds_inician_apagados(void){

    uint16_t puerto_virtual = 0xFFFF;

    ledsInit(&puerto_virtual);



    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(18), UNITY_DISPLAY_STYLE_INT);





}





void test_prender_un_led(void){

    ledsTurnOnSingle(2);



    UnityAssertEqualNumber((UNITY_INT)((0x0002)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_un_led(void){

    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);



    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_apagar_varios_leds(void){

    ledsTurnOnSingle(3);

    ledsTurnOnSingle(5);

    ledsTurnOffSingle(3);

    ledsTurnOffSingle(7);



    UnityAssertEqualNumber((UNITY_INT)((0x0010)), (UNITY_INT)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

}





void test_prender_y_consultar_un_led(void){

    

   _Bool 

        resultado;

    ledsTurnOnSingle(2);

    resultado = ledsCheckTurnOn(2);



    do {if ((resultado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(54)));}} while(0);

}







void test_apagar_y_consultar_un_led(void){

    

   _Bool 

        resultado;

    ledsTurnOnSingle(2);

    ledsTurnOffSingle(2);

    resultado = ledsCheckTurnOff(2);



    do {if ((resultado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(65)));}} while(0);

}





void test_prender_todos_y_verificar(void){

    

   _Bool 

        resultado;

    ledsTurnOnAll();



    resultado = ledsCheckTurnOnAll();



    do {if ((resultado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(75)));}} while(0);

}





void test_apagar_todos_y_verificar(void){

    

   _Bool 

        resultado;

    ledsTurnOnAll();

    ledsTurnOffAll();



    resultado = ledsCheckTurnOffAll();



    do {if ((resultado)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(86)));}} while(0);

}
