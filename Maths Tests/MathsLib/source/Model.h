#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include <vector>

class Model
{
public:
	std::vector<Vector3>vertices;
	std::vector<Vector3>faces;
	std::vector<Vector4>colors;
	int minR;
	int maxR;
	int minG;
	int maxG;
	int minB;
	int maxB;


	Model();
	virtual ~Model() {};

	void setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB);
	void setColorsRandom();
	void rotateX(const float& ammount);
	void rotateY(const float& ammount);
	void rotateZ(const float& ammount);
	void scale(Vector3& scaleVector);
	void translate(Vector3& translation);
	void load(std::string fileName);
	static Model generateRandom();
};