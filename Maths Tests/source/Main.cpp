#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 m2(1, 2, 3, 4);
    Vector2 v2(8, 6);

    std::cout << m2 * v2 << std::endl;
	system("pause");
	return 0;
}