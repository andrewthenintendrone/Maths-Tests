#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    unsigned int value = 59786546;
    unsigned char checkbit = 5;

    std::cout << "The number " << (int)checkbit << " bit of " << value << " is ";

    if (IsBitSet(value, checkbit))
    {
        std::cout << "set.";
    }
    else
    {
        std::cout << "unset.";
    }

	system("pause");
	return 0;
}