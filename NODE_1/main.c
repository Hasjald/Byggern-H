/*
 * byggerntermproject.c
 *
 * Created: 25/08/2021 12:53:57
 * Author : haral
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "UART_U/UART_U.h"
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

void Uart_test_ex1(void){
	char data[14];
	scanf("%s", data);
	printf("Current data: %s\n",data);
}