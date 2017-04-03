#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	std::cout << "30 degrees is " << degreesToRadians(30) << " radians" << std::endl;
	std::cout << "45 degrees is " << degreesToRadians(45) << " radians" << std::endl;
	std::cout << "72 degrees is " << degreesToRadians(72) << " radians" << std::endl;

	std::cout << std::endl;

	std::cout << "1.5 radians is " << radiansToDegrees(1.5f) << " degrees" << std::endl;
	std::cout << "3PI/2 radians is " << radiansToDegrees(3.0f * PI / 2.0f) << " degrees" << std::endl;
	std::cout << "2 radians is " << radiansToDegrees(2) << " degrees" << std::endl;

	std::cout << std::endl;

	system("pause");
	return 0;
}
