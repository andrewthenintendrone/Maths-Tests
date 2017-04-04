#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix3 matA(1, 2, 3, 4, 5, 6, 7, 8, 9);
	Matrix3 matB(10, 11, 12, 13, 14, 15, 16, 17, 18);

	std::cout << matA << "\n * \n" << matB << "\n = \n" << matA.dot(matB) << std::endl;


	system("pause");
	return 0;
}