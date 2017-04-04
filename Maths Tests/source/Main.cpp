#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	float arA[4] = { 1, 2, 3, 4 };
	float arB[4] = { 5, 6, 7, 8 };
	Matrix2 matA(arA);
	Matrix2 matB(arB);

	std::cout << matA << " * " << std::endl << matB << " = " << std::endl << matA.dot(matB) << std::endl;

	system("pause");
	return 0;
}