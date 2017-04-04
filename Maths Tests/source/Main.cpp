#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix4 matA(5, 6, 7, 6, 8, 9, 3, 4, 5, 6, 3, 1, 10, 12, 22, 77);
    Matrix4 matB(17, 18, 19, 20, 21, 22, 23, 24, 222, 26, 27, 28, 29, 30, 31, 32);

    std::cout << "The determinant of " << std::endl << matA << std::endl << " is " << matA.determinant() << std::endl;


	system("pause");
	return 0;
}