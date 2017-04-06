#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 mat(1, 2, 3, 4);
    Matrix2 mat2(5, 6, 7, 8);

    Matrix2 mat3 = mat * mat2;

    std::cout << mat3;

	system("pause");
	return 0;
}