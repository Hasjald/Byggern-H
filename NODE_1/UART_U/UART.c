/*
 * UART.c
 *
 * Created: 25/08/2021 12:59:44
 *  Author: haral
 */ 

#include "uart_driver.h"

int Init_Uart(uint16_t BAUD){
	
	uint16_t ubbr=F_CPU/16/BAUD-1;		//set baudrate
	UBRR0H = (unsigned char)(ubbr>>8);					//upper 
	UBRR0L = (unsigned char)(ubbr);						//LOWER
	
	UCSR0B= (1<<RXEN0) | (1<<TXEN0);	//EN RX and TX
	
	fdevopen(Transmit_Uart, Recieve_Uart);	//set functions
	UCSR0C = (1<<URSEL0) | (1<<USBS0) |(3<<UCSZ00); //formatting
	
	
}

int Transmit_Uart(unsigned char data){
	
	while(!(UCSR0A & (1 << UDRE0)));	//wait until buffer is empty
	UDR0 = data;						//send data
	return 0;
}

unsigned char Recieve_Uart(void){

	while(!(UCSR0A & (1 << RXC0)));		//wait until there is data
	return UDR0;						//return the data
}
