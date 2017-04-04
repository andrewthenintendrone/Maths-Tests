#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix4 matA(5, 6, 6, 6, 8, 9, 3, 4, 5, 6, 3, 1, 10, 12, 22, 6);
    Matrix4 matB(17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32);

    std::cout << "The determinant of " << std::endl << matA << std::endl << " is " << matA.determinant() << std::endl;

	//std::cout << matA << "\n * \n" << matB << "\n = \n" << matA.dot(matB) << std::endl;
	//std::cout << "and it's determinant is " << matA.dot(matB).determinant() << std::endl;


	system("pause");
	return 0;
}