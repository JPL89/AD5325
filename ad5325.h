// @File		AD5325.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		15/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
#ifndef AD5325_H
#define AD5325_H

#define AD5325_SLA_W 0x18
#define AD5325_SLA_R 0x19

void AD5325_Write(unsigned char pd0, 
unsigned char pd1, unsigned char clr,
unsigned char ldac, unsigned char chan, unsigned int data)
{
    data |= (unsigned int)((pd0<<15)|(pd1<<14)|(clr<<13)|(ldac<<12));
    
    Wire_Start();
    Wire_Write(AD5325_SLA_W);
    Wire_Write(chan);
    Wire_Write((unsigned char)((data >> 8) & 0xFF));
    Wire_Write((unsigned char)(data & 0xFF));
    Wire_Stop();
}

unsigned int AD5325_Read(unsigned char chan)
{
    unsigned int data = 0;
    
    Wire_Start();
    Wire_Write(AD5325_SLA_W);
    Wire_Write(chan);
    Wire_Start();
    Wire_Write(AD5325_SLA_R);
    data = Wire_Ack();
    data <<= 8;
    data = Wire_Nack();
    Wire_Stop();
    
    return ((unsigned int)(data));
}

#endif 
