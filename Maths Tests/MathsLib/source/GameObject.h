#pragma once
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include "Transform.h"
#include <vector>
#include <random>

namespace AFMaths
{
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
        Vector4 maxColorValues;


        GameObject();
        GameObject(const GameObject& rhs);
        virtual ~GameObject() {};

        void setColorPallete(const float& newMinR, const float& newMaxR, const float& newMinG, const float& newMaxG, const float& newMinB, const float& newMaxB, const float& newMinA, const float& newMaxA);
        void setColorsRandom(std::default_random_engine rng);
        void loadModelOBJ(std::string fileName);
        void updateVerts();
    };
}
