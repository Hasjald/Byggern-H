/*
 * UART.h
 *
 * Created: 08.09.2021 12:59:43
 *  Author: harasa
 */ 


#ifndef UART_H_
#define UART_H_

void UART_init(unsigned long extclock);
uint8_t UART_Recieve(void);
uint8_t UART_Transmit(unsigned char data);



#endif /* UART_H_ */