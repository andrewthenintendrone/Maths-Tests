#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 matA(0.7f, -0.7f, 0.7f, 0.7f);
    Matrix2 matB(2, 0, 0, -1);

    std::cout << matA * matB << std::endl;

	system("pause");
	return 0;
}