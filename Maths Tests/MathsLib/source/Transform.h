#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <vector>

class Transform
{
public:
    Transform* m_parent;
    std::vector<Transform*> m_children;

    Matrix4 m_localTransform;
    Matrix4 m_globalTransform;

    Vector3 m_scale;
    Vector3 m_rotation;
    Vector3 m_position;

    void setParent(Transform* newParent);
    void updateGlobalTransform();

    void setScaleX(const float& newScaleX);
    void setScaleY(const float& newScaleY);
    void setScaleZ(const float& newScaleZ);
    void setScaleAll(Vector3& newScale);

    void rotateX(const float& ammount);
    void rotateY(const float& ammount);
    void rotateZ(const float& ammount);
    void rotateAll(Vector3& rotationVector);

    void translateX(const float& ammount);
    void translateY(const float& ammount);
    void translateZ(const float& ammount);
    void translateAll(Vector3& translation);

    Transform();
    ~Transform();
};