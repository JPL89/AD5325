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
    
    
    
    while(1)
    {  
        
    }    
    
    return;
}
