/*
 * SRAM.h
 *
 * Created: 08.09.2021 16:46:02
 *  Author: harasa
 */ 


#ifndef SRAM_H_
#define SRAM_H_



void SRAM_INIT(void);
void SRAM_WRITE (uint16_t adress, char data);
char SRAM_READ(char adress);
void SRAM_Test(void);



#endif /* SRAM_H_ */