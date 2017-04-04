#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix3 matA(1, 2, 3, 0, -4, 1, 0, 3, -1);
	Matrix3 matB(matA * 4);

	std::cout << matA << "\n * \n" << matB << "\n = \n" << matA.dot(matB) << std::endl;
	std::cout << "and it's determinant is " << matA.dot(matB).determinant() << std::endl;


	system("pause");
	return 0;
}