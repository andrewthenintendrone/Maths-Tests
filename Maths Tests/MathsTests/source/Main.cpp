#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    unsigned int upperBound = 2048;

    std::cout << "Powers of 2 up to " << upperBound << ":\n\n";

    for (unsigned int i = 0; i < upperBound + 1; i++)
    {
        if (IsPowerOf2(i))
        {
            std::cout << i << std::endl;
        }
    }

    std::cout << std::endl;

	system("pause");
	return 0;
}