#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Vector3 vecA(14, 5, -5);
	Vector3 vecB(-2, 1, 43);

	std::cout << "The cross product of " << vecA << " and " << vecB << " is " << vecA.cross(vecB) << std::endl;

	system("pause");
	return 0;
}
