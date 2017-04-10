#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	Matrix3 m3b;
	m3b.setRotateY(1.76f);

    std::cout << m3b << std::endl;

	system("pause");
	return 0;
}