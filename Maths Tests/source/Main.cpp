#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Vector2 vecA(-1, -1);
	Vector2 vecB(-5, -6);

	float angle = Vector2::Angle(vecA, vecB);

	std::cout << "The angle between " << vecA << " and " << vecB << " is " << angle << " radians" << std::endl;
	std::cout << "or " << radiansToDegrees(angle) << " degrees" << std::endl;

	system("pause");
	return 0;
}
