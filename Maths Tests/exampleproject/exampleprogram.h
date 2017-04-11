#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <MathsLib.h>

class exampleprogram : public aie::Application {
public:

	exampleprogram();
	virtual ~exampleprogram();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	std::vector<Model>models;
	Model currentModel;

	float changetime;

protected:

	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};