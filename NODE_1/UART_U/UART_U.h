/*
 * UART_U.h
 *
 * Created: 25/08/2021 13:18:30
 *  Author: haral
 */ 


#ifndef UART_U_H_
#define UART_U_H_


int Init_Uart(uint16_t BAUD);
int Transmit_Uart(unsigned char data);
unsigned char Recieve_Uart(void);

static FILE uart_out = FDEV_SETUP_STREAM(Transmit_Uart, NULL, _FDEV_SETUP_WRITE);
static FILE uart_in = FDEV_SETUP_STREAM(NULL, Recieve_Uart, _FDEV_SETUP_READ);

#define UART (&uart_out)

#endif /* UART_U_H_ */