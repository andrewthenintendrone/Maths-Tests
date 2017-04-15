#include "Transform.h"

Transform::Transform()
{
    m_parent = nullptr;
}

Transform::~Transform()
{

}

// sets a gameobject as this gameobjects parent and adds this gameobject to the new parents children
void Transform::setParent(Transform* newParent)
{
    m_parent = newParent;
    newParent->m_children.push_back(this);
}

// updates the global transform of the gameobject and its children
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
    for (auto child : m_children)
    {
        child->updateGlobalTransform();
    }
}

void Transform::scaleX(const float& ammount)
{
    m_scale.mm[0][0] *= ammount;
}

void Transform::scaleY(const float& ammount)
{
    m_scale.mm[1][1] *= ammount;
}

void Transform::scaleZ(const float& ammount)
{
    m_scale.mm[2][2] *= ammount;
}

void Transform::scaleAll(Vector3& scaleVector)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        m_scale.mm[i][i] *= scaleVector[i];
    }
}

void Transform::setScaleX(const float& newScaleX)
{
    m_scale.mm[0][0] = newScaleX;
}

void Transform::setScaleY(const float& newScaleY)
{
    m_scale.mm[1][1] = newScaleY;
}

void Transform::setScaleZ(const float& newScaleZ)
{
    m_scale.mm[2][2] = newScaleZ;
}

void Transform::setScaleAll(Vector3& newScale)
{
    for (unsigned int i = 0; i < 3; i++)
    {
        m_scale.mm[i][i] = newScale[i];
    }
}

void Transform::rotateX(const float& ammount)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateX(ammount);
    m_rotation *= rotationMatrix;
}

void Transform::rotateY(const float& ammount)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateY(ammount);
    m_rotation *= rotationMatrix;
}

void Transform::rotateZ(const float& ammount)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateZ(ammount);
    m_rotation *= rotationMatrix;
}

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

void Transform::setRotationX(const float& newRotationX)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateX(newRotationX);
    m_rotation *= rotationMatrix;
}

void Transform::setRotationY(const float& newRotationY)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateY(newRotationY);
    m_rotation *= rotationMatrix;
}

void Transform::setRotationZ(const float& newRotationZ)
{
    Matrix4 rotationMatrix;
    rotationMatrix.setRotateZ(newRotationZ);
    m_rotation *= rotationMatrix;
}

void Transform::setRotationAll(Vector3& newRotation)
{
    Matrix4 rotationMatrix;

    rotationMatrix.setRotateX(newRotation.x);
    m_rotation *= rotationMatrix;
    rotationMatrix.setRotateY(newRotation.y);
    m_rotation *= rotationMatrix;
    rotationMatrix.setRotateZ(newRotation.z);
    m_rotation *= rotationMatrix;
}

void Transform::translateX(const float& ammount)
{
    m_position.vecs[3].x += ammount;
}

void Transform::translateY(const float& ammount)
{
    m_position.vecs[3].y += ammount;
}

void Transform::translateZ(const float& ammount)
{
    m_position.vecs[3].z += ammount;
}

void Transform::translateAll(Vector3& translation)
{
    m_position.vecs[3] += translation;
}

void Transform::setPositionX(const float& newPositionX)
{
    m_position.vecs[3].x = newPositionX;
}

void Transform::setPositionY(const float& newPositionY)
{
    m_position.vecs[3].y = newPositionY;
}

void Transform::setPositionZ(const float& newPositionZ)
{
    m_position.vecs[3].z = newPositionZ;
}

void Transform::setPositionAll(Vector3& newPosition)
{
    m_position.vecs[3] = newPosition;
}