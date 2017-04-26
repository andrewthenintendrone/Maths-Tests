#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    unsigned int test = 4294967295;

    std::cout << "The leftmost bit of " << test << " is ";

    if (IsLeftMostBitSet(test))
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