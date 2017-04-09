#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix3 m3a(1, 0, 0, 0, -0.668648f, -0.743579f, 0, 0.743579f, -0.668648f);
    Matrix3 m3c(-0.981005f, -0.193984f, 0, 0.193984f, -0.981005f, 0, 0, 0, 1);
    Matrix3 m3d = m3a * m3c;

    std::cout << m3d << std::endl;

	system("pause");
	return 0;
}