#include <stdio.h>

uint16_t getManUART(uint8_t byte)
{
    uint16_t man = 0;

    for(int k = 0; k < 8; k++)
    {
        uint8_t bit = byte & (1 << k);
        if(bit)
            man = (man << 2) | 0x01;
        else
            man = (man << 2) | 0x02;
    }

    return man;
}

uint8_t getUARTMan(uint16_t man)
{
    uint8_t byte = 0;

    uint8_t bits = 0;
    for(int k = 0; k < 8; k++)
    {
        bits = (man & 0x03);
        if(bits == 0x01)  //transition from 0 -> 1 is one
        {
            byte = byte << 1;
            byte |= 0x01;

        }
        else if(bits == 0x02)
        {
            byte = byte << 1;
        }
        else
        {
            printf("Not manchester\n");
        }
        man = (man >> 2);
    }

    return byte;
}