#include <iostream>
#include <time.h>
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
    Matrix3 m3a, m3b, m3c, m3d;
    m3a.setRotateX(3.98f);
    m3b.setRotateY(1.76f);
    m3c.setRotateZ(9.62f);

    std::cout << m3a << std::endl;
    std::cout << m3b << std::endl;
    std::cout << m3c << std::endl;


	system("pause");
	return 0;
}