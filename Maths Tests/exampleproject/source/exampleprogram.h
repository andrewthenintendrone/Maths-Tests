#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <Texture.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <MathsLib.h>
#include <random>
#include <chrono>

class exampleprogram : public aie::Application {
public:

	exampleprogram();
	virtual ~exampleprogram();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

    void setUpRNG();
    void randomizeCenterPalette();
    void randomizeOtherPalettes();
    void randomizeOrbits();

    std::vector<AFMaths::Transform>m_orbitTransforms;
	std::vector<AFMaths::GameObject>m_gameobjects;
    std::vector<AFMaths::Vector3>m_orbitSpeeds;
    std::vector<AFMaths::Vector3>m_gameobjectRotationSpeeds;
    float m_brightness;

    bool m_independantMotion = true;
    std::default_random_engine m_prng;

protected:

    aie::Renderer2D*	m_2dRenderer;
    aie::Font*			m_font;
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};