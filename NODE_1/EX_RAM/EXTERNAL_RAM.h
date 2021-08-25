/*
 * EXTERNAL_RAM.h
 *
 * Created: 25/08/2021 13:31:17
 *  Author: haral
 */ 


#ifndef EXTERNAL_RAM_H_
#define EXTERNAL_RAM_H_


void ExRAM_Init(void);
void Ex_RAM_Write(uint16_t Adress, char Data);
char Ex_RAM_Read(char Adress);

int Ex_RAM_Check(uint16_t Adress)

#endif /* EXTERNAL_RAM_H_ */