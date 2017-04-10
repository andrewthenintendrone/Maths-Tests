#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix2 mat(1, 2, 3, 6);
	Matrix2 mat2(1, 2, 3, 4);

    std::cout << mat * mat2 << std::endl;

	system("pause");
	return 0;
}