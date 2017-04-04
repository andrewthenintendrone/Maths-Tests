#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix2 matA(1, 2, 3, 4);
	Matrix2 matB(5, 6, 7, 8);

	std::cout << matA << "\n * \n" << matB << "\n = \n" << matA.dot(matB) << std::endl;
	std::cout << "and it's determinant is " << matA.dot(matB).determinant() << std::endl;


	system("pause");
	return 0;
}