// @File		MAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "utils.h"
#include "ks0066.h"
#include "wire.h"
#include "ad5325.h"

#define LTC2631_SLA_W 0xE6

// COMMAND:
// 0x00: Write to Input Register
// 0x01: Update (Power Up) DAC Register
// 0x03: Write to and Update (Power Up) DAC Register
// 0x04: Power Down
// 0x06: Select Internal Reference
// 0x07: Select External Reference
//
void LTC2631_Write(unsigned char command, unsigned int data)
{
    unsigned long code = 0;
    
    code = command;
    code = code << 20;
    code |= (data << 4);
        
    Wire_Start();
    Wire_Write(LTC2631_SLA_W);
    Wire_Write((unsigned char)((code >> 24) & 0xFF));
    Wire_Write((unsigned char)((code >> 16) & 0xFF));
    Wire_Write((unsigned char)((code >> 8) & 0xFF));
    Wire_Write((unsigned char)((code) & 0xFF));
    Wire_Stop();
}

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    Wire_Init();    
    
    AD5325_Write(   0,          // PD0 
                    0,          // PD1
                    1,          // CLR
                    0,          // LDAC
                    2,          // POINTER BYTE
                    4095);      // DATA
    
    
    KS0066_Init();
    KS0066_Clear(0);
    KS0066_Clear(1);  
    KS0066_Goto(0,0);               
            
    unsigned int r = AD5325_Read(0);
    
    KS0066_Char(48 + r / 1000 % 10);
    KS0066_Char(48 + r / 100 % 10);
    KS0066_Char(48 + r / 10 % 10);
    KS0066_Char(48 + r / 1 % 10);
    
    while(1)
    {  
        
    }    
    
    return;
}
