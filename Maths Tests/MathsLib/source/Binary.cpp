#include "Binary.h"
#include <limits>
#include <iostream>

bool IsLeftMostBitSet(unsigned int value)
{
    return ((UINT_MAX - (UINT_MAX >> 1) & value) > 0);
}

bool IsRightMostBitSet(unsigned int value)
{
    return ((1 & value) > 0);
}

bool IsBitSet(unsigned int value, unsigned char bit_to_check)
{
    // if the bit to check is more than the ammount of bits in an unsigned int return false
    if (bit_to_check >= sizeof(unsigned int) * CHAR_BIT)
    {
        return false;
    }
    else
    {
        return (((1 << bit_to_check) & value) > 0);
    }
}

int GetRightMostSetBit(unsigned int value)
{
    return 1;
}

// prints a number converted to binary
void PrintBinary(unsigned int value)
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