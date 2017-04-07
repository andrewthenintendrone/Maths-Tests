#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 mat(1, 2, 3, 4);
    Matrix2 mat2 = mat - 2.5f;

    std::cout << mat2 << std::endl;
	system("pause");
	return 0;
}