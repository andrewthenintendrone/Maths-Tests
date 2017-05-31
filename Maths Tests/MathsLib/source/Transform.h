#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix4.h"
#include <vector>

namespace AFMaths
{
    class Transform
    {
    public:
        Transform* m_parent;
        std::vector<Transform*> m_children;

        Matrix4 m_localTransform;
        Matrix4 m_globalTransform;

        Matrix4 m_scale;
        Matrix4 m_rotation;
        Matrix4 m_position;

        void setParent(Transform* newParent);
        void updateGlobalTransform();

        void setScaleX(const float& newScaleX);
        void setScaleY(const float& newScaleY);
        void setScaleZ(const float& newScaleZ);
        void setScaleAll(Vector3& newScale);

        void scaleX(const float& amount);
        void scaleY(const float& amount);
        void scaleZ(const float& amount);
        void scaleAll(Vector3& scaleVector);

        void rotateX(const float& amount);
        void rotateY(const float& amount);
        void rotateZ(const float& amount);
        void rotateAll(Vector3& rotationVector);

        void translateX(const float& amount);
        void translateY(const float& amount);
        void translateZ(const float& amount);
        void translateAll(Vector3& translation);

        Transform();
        ~Transform();
    };
}
