#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix3 mat(1, 2, 3, 4, 5, 6, 7, 8, 9);
    Matrix3 mat2(10, 11, 12, 13, 14, 15, 16, 17, 18);

    Matrix3 mat3 = mat * mat2;

    std::cout << mat3;

	system("pause");
	return 0;
}