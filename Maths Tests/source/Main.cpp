#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Vector3 vec(1, 2, 3);
	float* fp = (float*)vec;

	std::cout << *fp << std::endl;
	system("pause");
	return 0;
}