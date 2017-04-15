#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Transform.h"
#include <vector>

class GameObject
{
public:
    Transform transform;

    // used for model
	std::vector<Vector4>vertices;
    std::vector<Vector4>transformedVertices;
	std::vector<Vector3>faces;
	std::vector<Vector4>colors;
	int minR;
	int maxR;
	int minG;
	int maxG;
	int minB;
	int maxB;


	GameObject();
	virtual ~GameObject() {};

	void setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB);
	void setColorsRandom();
	void load(std::string fileName);
	static GameObject generateRandom();
    void updateVerts();
};