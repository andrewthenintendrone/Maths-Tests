#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	float arA[2][2] = { {1, 0}, {0, 1} };
	float arB[2][2] = { {-8, 4}, {2, 5} };
	Matrix2 matA(arA);
	Matrix2 matB(arB);

	std::cout << matA << std::endl << " * " << matB << std::endl << " = " << matA.dot(matB) << std::endl;

	system("pause");
	return 0;
}