#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix4 matA(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    Matrix4 matB(17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

	std::cout << matA << "\n * \n" << matB << "\n = \n" << matA.dot(matB) << std::endl;
	std::cout << "and it's determinant is " << matA.dot(matB).determinant() << std::endl;


	system("pause");
	return 0;
}