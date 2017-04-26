#include "Binary.h"
#include <limits>
#include <iostream>

bool IsLeftMostBitSet(unsigned int value)
{
    return true;
}

bool IsRightMostBitSet(unsigned int value)
{
    return true;
}

bool IsBitSet(unsigned int value, unsigned char bit_to_check)
{
    return true;
}

int GetRightMostSetBit(unsigned int value)
{
    return 1;
}

// prints a number converted to binary
void PrintBinary(unsigned char value)
{
    std::cout << toBinary(value) << std::endl;
}

// returns a binary version of a number as a string
std::string toBinary(unsigned int value)
{
    unsigned int tempValue = value;
    std::string binaryString;
    while (tempValue != 0)
    {
        binaryString = (tempValue % 2 == 0 ? "0" : "1") + binaryString;
        tempValue /= 2;
    }
    return binaryString;
}

bool IsPowerOf2(unsigned int value)
{
    return true;
}