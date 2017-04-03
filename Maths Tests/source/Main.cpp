#include <iostream>
#include <time.h>
#include "Vector3.h"
#include <vector>
#include <iostream>
#include "MathsLib.h"

int main()
{
	std::vector<Vector2>vectors;
	vectors.push_back(Vector2(1, 2));
	vectors.push_back(Vector2(3, 4));
	vectors.push_back(Vector2(5, 6));

	for (unsigned int i = 0; i < vectors.size(); i++)
	{
		std::cout << vectors[i] << " * 5 = " << vectors[i] * 5 << std::endl;
		std::cout << "5 * " << vectors[i] << " = " << 5 * vectors[i] << std::endl << std::endl;
	}

	system("pause");
	return 0;
}
