#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    unsigned int test = 33;

    std::cout << "The rightmost bit of " << test << " is ";

    if (IsRightMostBitSet(test))
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