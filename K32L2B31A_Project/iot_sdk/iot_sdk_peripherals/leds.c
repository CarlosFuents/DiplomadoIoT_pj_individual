/*
 * leds.c
 *  CARLOS MARIO FUENTES
 *  Created on: 6/09/2021
 *      Author: CARLOS MARIO FUENTES
 *      driver para controlar LEDs de tarjeta FRDM-K32L2B3
 */

#include "leds.h"
#include "fsl_gpio.h"

void encender_led_verde(){
	//encender led verde
	GPIO_PinWrite(GPIOD,5,0);
}

void apagar_led_verde(){
	//apaga led verde
	GPIO_PinWrite(GPIOD,5,1);
}

void encender_led_rojo(){
	//encender led rojo
	GPIO_PinWrite(GPIOE,31,0);
}

void apagar_led_rojo(){
	//apaga led rojo
	GPIO_PinWrite(GPIOE,31,1);
}

