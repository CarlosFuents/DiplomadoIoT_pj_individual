/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 */

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "K32L2B31A.h"
#include "fsl_debug_console.h"
#include "leds.h"

unsigned int test_global_var=100;
float dato_float=3.1416;

/*genera bloqueo de microcontrolador por tiempo fijo*/
void delay_block(void){
	uint32_t i;
	for(i=0;i<0xFFFFF;i++){
	}
}

int main(void) {
	/*force the counter tobe placed into memory.*/
	 int i = 0 ;
	 unsigned char cont_LR = 0;

    /* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif

    printf("Hello World\r\n");
    printf("test_global_var:%d\r\n",test_global_var);
    printf("dato_float:%g\r\n",dato_float);

    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        printf("i:%u\r\n",i);
        encender_led_verde();
        delay_block();
        apagar_led_verde();
        delay_block();
        if(i % 10 == 0){
            cont_LR++;
            if(cont_LR % 2 == 0){
        	    apagar_led_rojo();
            }else{
        	    encender_led_rojo();
            }
        }
    //PRINTF("i:%u\r\n",i);
           /* 'Dummy' NOP to allow source level single stepping of
               tight while() loop */
           __asm volatile ("nop");
    }
    return 0 ;
}
