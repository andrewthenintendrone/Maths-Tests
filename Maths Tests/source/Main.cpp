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

	std::cout << "The Vector2 perpendicular to " << vecA << " is " << vecA.getPerpendicular() << std::endl;
	std::cout << "The Vector2 perpendicular to " << vecB << " is " << vecB.getPerpendicular() << std::endl;

	system("pause");
	return 0;
}
