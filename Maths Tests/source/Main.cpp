#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix3 m3b(1, 0, 0, 0, 1, 0, 0, 0, 1);
	m3b[2] = Vector3(55, 44, 1);

	std::cout << m3b << std::endl;
	system("pause");
	return 0;
}