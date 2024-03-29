#pragma once

#include "Application.h"
#include "Gizmos.h"
#include "Renderer2D.h"
#include "Audio.h"
#include "Input.h"
#include "Font.h"
#include <Texture.h>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <MathsLib.h>
#include <random>
#include <chrono>
#include <string>


class exampleprogram : public aie::Application {
public:

	exampleprogram();
	virtual ~exampleprogram();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
    int getNumFaces();

    void colorCenterObject(AMMaths::Vector4& color1, AMMaths::Vector4& color2, AMMaths::Vector4& color3, AMMaths::Vector4& color4);
    void randomizeOtherPalettes();
    void randomizeOrbits();
    void exit();

    std::vector<AMMaths::Transform>m_orbitTransforms;
	std::vector<AMMaths::GameObject>m_gameobjects;
    std::vector<AMMaths::Vector3>m_orbitSpeeds;
    std::vector<AMMaths::Vector3>m_gameobjectRotationSpeeds;
    float m_brightness;

    bool m_exiting = false;
    float m_exittimer = 3.39f;
    float m_exitTexturePositionX;
    int m_facecount;

    bool m_independantMotion = true;
    std::default_random_engine m_prng;

protected:

    aie::Renderer2D*	m_2dRenderer;
    aie::Font*			m_font;
    aie::Texture*       m_exitTexture;
    aie::Audio*         m_exitMusic;
	glm::mat4	        m_viewMatrix;
	glm::mat4       	m_projectionMatrix;
};