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

    // model vertices loaded from file
	std::vector<Vector4>vertices;
    // model vertices multiplied by transform
    std::vector<Vector4>transformedVertices;
    // model faces loaded from file
	std::vector<Vector3>faces;
    // randomly generated colors used for each face
	std::vector<Vector4>colors;
    // minimum r, g, b, and alpha values to use when generating colors
    Vector4 minColorValues;
    // difference between maximum and minimum values to use for color generation
    Vector4 colorDifferences;


	GameObject();
	virtual ~GameObject() {};

	void setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB, const int& newMinA, const int& newMaxA);
	void setColorsRandom();
	void load(std::string fileName);
	static GameObject generateRandom();
    void updateVerts();
};