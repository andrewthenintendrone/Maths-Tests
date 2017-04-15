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

    // create 21 teapots
    for (unsigned int i = 0; i < 21; i++)
    {
        m_gameobjects.push_back(GameObject());
        m_gameobjects[i].load("./models/teapot.obj");
        m_gameobjects[i].setColorPallete(191, 255, 191, 255, 191, 255);
        m_gameobjects[i].setColorsRandom();
    }

    Vector3 offsets[4] = { Vector3::Left(), Vector3::Right(), Vector3::Forward(), Vector3::Back() };

    m_gameobjects[0].transform.scaleAll(Vector3(0.75f));

    for (unsigned int i = 1; i < 5; i++)
    {
        m_gameobjects[i].transform.setParent(&m_gameobjects[0].transform);
        m_gameobjects[i].transform.scaleAll(Vector3(0.5f));
        m_gameobjects[i].transform.translateAll(offsets[i - 1] * 8);
        for (unsigned int j = 1; j < 5; j++)
        {
            m_gameobjects[4 * i + j].transform.setParent(&m_gameobjects[i].transform);
            m_gameobjects[4 * i + j].transform.scaleAll(Vector3(0.5f));
            m_gameobjects[4 * i + j].transform.translateAll(offsets[j - 1] * 4);
        }
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

    for (GameObject& object : m_gameobjects)
    {
        object.transform.rotateY(deltaTime);
    }

    m_gameobjects[0].transform.updateGlobalTransform();

    /*else
    {
        if (input->isKeyDown(aie::INPUT_KEY_LEFT))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[i].transform.rotateY(-2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[i].transform.rotateY(2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_UP))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[i].transform.rotateX(-2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_DOWN))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[i].transform.rotateX(2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_Q))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[0].transform.translateX(2.0f * deltaTime);
            }
        }
        if (input->isKeyDown(aie::INPUT_KEY_W))
        {
            for (unsigned int i = 0; i < m_gameobjects.size(); i++)
            {
                m_gameobjects[0].transform.translateX(-2.0f * deltaTime);
            }
        }
    }*/
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

    Vector4 black(0, 1, 0, 1);

    // draw 3D elements
    for (unsigned int i = 0; i < m_gameobjects.size(); i++)
    {
        m_gameobjects[i].updateVerts();
        for (unsigned int j = 0; j < m_gameobjects[i].faces.size(); j++)
        {
            /*Gizmos::addTri(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
                m_gameobjects[i].colors[j].toGLM());*/

            
            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            black.toGLM());

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            black.toGLM());

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            black.toGLM());
        }
    }

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);
}