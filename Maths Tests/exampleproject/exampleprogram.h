#pragma once

#include "Application.h"
#include "Renderer2D.h"
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

	std::vector<GameObject>m_gameobjects;

protected:

    aie::Renderer2D*	m_2dRenderer;
    aie::Font*			m_font;
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};