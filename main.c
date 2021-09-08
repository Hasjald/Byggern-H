/*
 * exercise1.c
 *
 * Created: 08.09.2021 11:55:04
 * Author : harasa
 */ 

#define F_CPU 4915200UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h"
#include "SRAM.h"

int main(void)
{	
	int a=10;
	UART_init(F_CPU);
    printf("init finished\n\r");
	printf("%d",a);
	SRAM_INIT();
	SRAM_Test();
	while (1)
    {
	//SRAM_WRITE(255,255);
	//_delay_ms(1000);
	
	}
}


