#pragma once

class Matrix2
{
public:
	// use union for easier access
	union
	{
		struct
		{
			float xAxis[2];
			float yAxis[2];
		};
		float m[2][2];
	};

	// constructors and destructor
	Matrix2();
	Matrix2(float newM[2][2]);
	~Matrix2();
};