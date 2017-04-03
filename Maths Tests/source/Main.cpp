#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Vector4 a(1, 2, 3, 4);
    Vector4 b(5, 6, 7, 8);
    Vector4 c = a * 5 - b * 2;

	std::cout << c << std::endl;

	system("pause");
	return 0;
}