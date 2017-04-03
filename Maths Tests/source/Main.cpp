#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Vector3 a(12, 5, 7.8f);
	Vector3 b(6.5f, 7, 14);
	Vector3 c = a.cross(b);

	std::cout << c << std::endl;

	system("pause");
	return 0;
}