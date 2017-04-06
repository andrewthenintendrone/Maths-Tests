#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix4 mat;
    mat.setRotateY(-2.6f);

    std::cout << mat << std::endl;


	system("pause");
	return 0;
}