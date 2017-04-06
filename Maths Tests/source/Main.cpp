#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 mat = Matrix2::identity();
    mat.setRotate(90);

    std::cout << mat;

	system("pause");
	return 0;
}