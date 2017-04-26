#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    unsigned int value = 123;

    std::cout << "The rightmost set bit of " << value << " is " << GetRightMostSetBit(value) << std::endl;

	system("pause");
	return 0;
}