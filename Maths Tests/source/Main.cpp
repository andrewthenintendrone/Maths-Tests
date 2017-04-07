#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix2 m2;
    m2.setRotate(4.576f);

    std::cout << m2 << std::endl;

    Vector2 v2a(13.5f, -48.23f);
    Vector2 v2c = m2 * v2a;

    std::cout << v2c << std::endl;

	system("pause");
	return 0;
}