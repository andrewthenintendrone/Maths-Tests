#include "Transform.h"

namespace AFMaths
{
    Transform::Transform()
    {
        m_parent = nullptr;
    }

    Transform::~Transform()
    {

    }

    // sets a Transform as this Transforms parent and adds this Transform to the new parents children
    void Transform::setParent(Transform* newParent)
    {
        m_parent = newParent;
        newParent->m_children.push_back(this);
    }

    // updates m_globalTransform for this Transform and its children
    void Transform::updateGlobalTransform()
    {
        m_localTransform = m_position * m_rotation * m_scale;
        if (m_parent != nullptr)
        {
            m_globalTransform = m_parent->m_globalTransform * m_localTransform;
        }
        else
        {
            m_globalTransform = m_localTransform;
        }
        for (auto& child : m_children)
        {
            child->updateGlobalTransform();
        }
    }

    // sets scale on the x axis
    void Transform::setScaleX(const float& newScaleX)
    {
        m_scale.mm[0][0] = newScaleX;
    }

    // sets scale on the y axis
    void Transform::setScaleY(const float& newScaleY)
    {
        m_scale.mm[1][1] = newScaleY;
    }

    // sets scale on the z axis
    void Transform::setScaleZ(const float& newScaleZ)
    {
        m_scale.mm[2][2] = newScaleZ;
    }

    // sets scale on all axis
    void Transform::setScaleAll(Vector3& newScale)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            m_scale.mm[i][i] = newScale[i];
        }
    }

    void Transform::scaleX(const float& amount)
    {
        m_scale[0][0] += amount;
    }

    void Transform::scaleY(const float& amount)
    {
        m_scale[1][1] += amount;
    }

    void Transform::scaleZ(const float& amount)
    {
        m_scale[2][2] += amount;
    }

    void Transform::scaleAll(Vector3& scaleVector)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            m_scale.mm[i][i] += scaleVector[i];
        }
    }

    // rotates on the x axis
    void Transform::rotateX(const float& amount)
    {
        Matrix4 rotationMatrix;
        rotationMatrix.setRotateX(amount);
        m_rotation *= rotationMatrix;
    }

    // rotates on the y axis
    void Transform::rotateY(const float& amount)
    {
        Matrix4 rotationMatrix;
        rotationMatrix.setRotateY(amount);
        m_rotation *= rotationMatrix;
    }

    // rotates on the z axis
    void Transform::rotateZ(const float& amount)
    {
        Matrix4 rotationMatrix;
        rotationMatrix.setRotateZ(amount);
        m_rotation *= rotationMatrix;
    }

    // rotates on all axis
    void Transform::rotateAll(Vector3& rotationVector)
    {
        Matrix4 rotationMatrix;

        rotationMatrix.setRotateX(rotationVector.x);
        m_rotation *= rotationMatrix;
        rotationMatrix.setRotateY(rotationVector.y);
        m_rotation *= rotationMatrix;
        rotationMatrix.setRotateZ(rotationVector.z);
        m_rotation *= rotationMatrix;
    }

    // translates on the x axis
    void Transform::translateX(const float& amount)
    {
        m_position.vecs[3].x += amount;
    }

    // translates on the y axis
    void Transform::translateY(const float& amount)
    {
        m_position.vecs[3].y += amount;
    }

    // translates on the z axis
    void Transform::translateZ(const float& amount)
    {
        m_position.vecs[3].z += amount;
    }

    // translates on all axis
    void Transform::translateAll(Vector3& translation)
    {
        m_position.vecs[3] += translation;
    }
}
