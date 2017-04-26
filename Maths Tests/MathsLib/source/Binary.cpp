#include "Binary.h"
#include <limits>
#include <iostream>

namespace AFMaths
{
    // Returns true if the left most(the most significant) bit of value is set and false otherwise
    bool IsLeftMostBitSet(unsigned int value)
    {
        return ((UINT_MAX - (UINT_MAX >> 1) & value) > 0);
    }

    // Returns true if the right most (the least significant) bit of value is set and false otherwise
    bool IsRightMostBitSet(unsigned int value)
    {
        return ((1 & value) > 0);
    }

    // Returns true if the asked for bit is set, and false otherwise.
    // bit_to_check is zero indexed from the right most bit.
    // i.e 0 is the right most bit and 31 is the left most.
    bool IsBitSet(unsigned int value, unsigned char bit_to_check)
    {
        // if the bit to check is more than the number of bits in an unsigned int return false
        if (bit_to_check >= sizeof(unsigned int) * CHAR_BIT)
        {
            return false;
        }
        else
        {
            return (((1 << bit_to_check) & value) > 0);
        }
    }

    // This function returns the index of the right most bit set to 1 in value
    // If no bits are set, it returns - 1
    int GetRightMostSetBit(unsigned int value)
    {
        for (unsigned char i = 0; i < sizeof(unsigned int) * CHAR_BIT; i++)
        {
            if (IsBitSet(value, i))
            {
                return i;
            }
        }
        return -1;
    }

    // Prints value to the console as a binary number
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

    // Returns true if value is a power of 2 and false otherwise
    bool IsPowerOf2(unsigned int value)
    {
        unsigned int temp = 1;
        for (unsigned char i = 0; i < sizeof(unsigned int) * CHAR_BIT; i++)
        {
            if (value == temp)
            {
                return true;
            }
            temp = temp << 1;
        }
        return false;
    }
}
