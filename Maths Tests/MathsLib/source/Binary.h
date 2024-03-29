#pragma once
#include <string>

namespace AMMaths
{
    bool IsLeftMostBitSet(unsigned int value);
    bool IsRightMostBitSet(unsigned int value);
    bool IsBitSet(unsigned int value, unsigned char bit_to_check);
    int GetRightMostSetBit(unsigned int value);
    void PrintBinary(unsigned int value);
    std::string toBinary(unsigned int value);
    bool IsPowerOf2(unsigned int value);
}
