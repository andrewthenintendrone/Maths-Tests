#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	float arA[2][2] = { {1, 2}, {3, 4} };
	Matrix2 matA(arA);
	Matrix2 matB(5);

	std::cout << matB * 5 << std::endl;

	system("pause");
	return 0;
}