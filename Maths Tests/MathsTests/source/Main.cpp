#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

using namespace AFMaths;

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


    Vector4 veca = { 1, 2, 3, 4 };
    Vector4 vecb = { 5, 6, 7, 8 };

    float* fp = (float*)veca;
    float* fp2 = (float*)vecb;

    for (unsigned int i = 0; i < 4; i++)
    {
        std::cout << fp[i] << " " << fp2[i] << std::endl;
    }

	system("pause");
	return 0;
}