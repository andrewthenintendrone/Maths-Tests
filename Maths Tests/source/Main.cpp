#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Vector2 vecA(-6.5f, -8.12f);
    Vector2 vecB(7.8f, 1.36f);

    std::cout << Vector2::getAngle(vecA, vecB) << std::endl;

	system("pause");
	return 0;
}
