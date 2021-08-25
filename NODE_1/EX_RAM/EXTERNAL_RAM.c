/*
 * EXTERNAL_RAM.c
 *
 * Created: 25/08/2021 13:31:40
 *  Author: haral
 */ 
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include "EXTRERNAL_RAM.h"
#include "UART_U/UART_U.h"

#define	EX_RAM_SIZE 0x800

void ExRAM_Init(void){

	MCUCR |= (1<<SRE);
	SFIOR |= (1<<XMM2);

}

void Ex_RAM_Write(uint16_t Adress, char Data){
	
	volatile char* EX_RAM = (char *) 0x1800;
	EX_RAM[Adress] = Data;
	
}

char Ex_RAM_Read(uint16_t Adress){
	
	volatile char* EX_RAM = 0x1800;
	return EX_RAM[Adress];
	
}

int Ex_RAM_Check(uint16_t Adress){
	
	if((Adress<0)||(Adress>EX_RAM_SIZE){
		return -1;
	}
	else{
		return 0
	}
}

void SRAM_Test(void)
{
	volatile char *ext_ram = (char *) 0x1800; // Start address for the SRAM
	uint16_t ext_ram_size = 0x800;
	uint16_t write_errors = 0;
	uint16_t retrieval_errors = 0;
	printf("Starting SRAM test...\n");
	// rand() stores some internal state, so calling this function in a loop will
	// yield different seeds each time (unless srand() is called before this function)
	uint16_t seed = rand();
	// Write phase: Immediately check that the correct value was stored
	srand(seed);
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		ext_ram[i] = some_value;
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Write phase error: ext_ram[%4d] = %02X (should be %02X)\n\r", i, retreived_value, some_value);
			write_errors++;
		}
	}
	// Retrieval phase: Check that no values were changed during or after the write phase
	srand(seed);
	// reset the PRNG to the state it had before the write phase
	for (uint16_t i = 0; i < ext_ram_size; i++) {
		uint8_t some_value = rand();
		uint8_t retreived_value = ext_ram[i];
		if (retreived_value != some_value) {
			printf("Retrieval phase error: ext_ram[%4d] = %02X (should be %02X)\n\r", i, retreived_value, some_value);
			retrieval_errors++;
		}
	}
	printf("SRAM test completed with \n%4d errors in write phase and \n%4d errors in retrieval phase\n\n", write_errors, retrieval_errors);
}

