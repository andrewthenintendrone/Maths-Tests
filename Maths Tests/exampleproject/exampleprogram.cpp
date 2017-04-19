#include "exampleprogram.h"
#include "Gizmos.h"
#include "Input.h"
#include "font.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

exampleprogram::exampleprogram() {

}

exampleprogram::~exampleprogram() {

}

bool exampleprogram::startup() {

	// set RNG seed
	srand((int)time(NULL));

	setBackgroundColour(30.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f, 1);

    // create 2d renderer
    m_2dRenderer = new aie::Renderer2D();

    // open comic sans
    m_font = new aie::Font("./font/Andrew_Fitzpatrick_Handwriting.ttf", 32);

	// initialise gizmo primitive counts
	Gizmos::create(1000000, 1000000, 1000000, 1000000);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(0, 10, 20), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);
    
    // push back orbit transforms and gameobjects
    // also set random orbit speeds and rotation speeds for each planet
    for (unsigned int i = 0; i < 11; i++)
    {
        m_orbitTransforms.push_back(Transform());
        m_gameobjects.push_back(GameObject());
        m_orbitSpeeds.push_back((rand() % 101 - 50) / 50.0f);
        m_gameobjectRotationSpeeds.push_back((rand() % 101 - 50) / 50.0f);
    }

    // load models for each gameobject and set a color pallete
    // also parent each gameobject to its orbit transform and scale and translate randomly
    for (unsigned int i = 0; i < 11; i++)
    {
        m_gameobjects[i].load("./models/sphere_low.obj");
        m_gameobjects[i].setColorPallete(0, 255, 0, 255, 0, 255);
        m_gameobjects[i].setColorsRandom();
        m_gameobjects[i].transform.setParent(&m_orbitTransforms[i]);
        m_gameobjects[i].transform.setScaleAll(Vector3((100 + rand() % 101) / 100.0f));
        m_gameobjects[i].transform.translateX(3 * i + 1);
    }

	return true;
}

void exampleprogram::shutdown() {

	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime) {
    //deltaTime /= 100;

	// query time since application started
	float time = getTime();

	// rotate camera
	//m_viewMatrix = glm::lookAt(vec3(glm::sin(time) * 5, 0, glm::cos(time) * 5),
		//vec3(0), vec3(0, 1, 0));

	// wipe the gizmos clean for this frame
	Gizmos::clear();

    // define some colors
	Vector4 black(0, 0, 0, 1);
	Vector4 white(1);
	Vector4 red(1, 0, 0, 1);
	Vector4 orange(0.5f, 1.0f, 0.0f, 1.0f);
	Vector4 yellow(1, 1, 0, 1);
	Vector4 green(0, 1, 0, 1);
	Vector4 blue(0, 0, 1, 1);
	Vector4 purple(0.5f, 0.0f, 1.0f, 1.0f);

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

    /*else
    {
        if (input->isKeyDown(aie::INPUT_KEY_LEFT))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].rotateY(-2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].rotateY(2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_UP))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].rotateX(-2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_DOWN))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].rotateX(2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_Q))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].translateX(-deltaTime / 5.0f);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_W))
        {
            for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
            {
                m_orbitTransforms[i].translateX(deltaTime / 5.0f);
            }
        }
    }*/


    for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
    {
        m_orbitTransforms[i].rotateY(deltaTime * m_orbitSpeeds[i]);
        m_gameobjects[i].transform.rotateY(deltaTime * m_gameobjectRotationSpeeds[i]);
        m_orbitTransforms[i].updateGlobalTransform();
    }
}

void exampleprogram::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// update perspective in case window resized
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

    // draw 2D elements
    clearScreen();
    m_2dRenderer->setCameraPos(0, 0);
    m_2dRenderer->begin();
    m_2dRenderer->setRenderColour(1, 1, 1, 1);
    char time[32];
    sprintf_s(time, 32, "TIME: %i", (int)getTime());
    m_2dRenderer->drawText(m_font, time, 100, 620);

    m_2dRenderer->end();

    Vector4 red(1, 0, 0, 1);

    // draw 3D elements
    for (unsigned int i = 0; i < m_gameobjects.size(); i++)
    {
        m_gameobjects[i].updateVerts();
        for (unsigned int j = 0; j < m_gameobjects[i].faces.size(); j++)
        {
            Gizmos::addTri(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
                m_gameobjects[i].colors[j].toGLM());

            
            /*Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            red.toGLM());

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            red.toGLM());

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            red.toGLM());*/
        }
    }

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);
}