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

    // set background to grey
	//setBackgroundColour(30.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f, 1);
    setBackgroundColour(0, 0, 0, 1);

    // create 2d renderer for text etc
    m_2dRenderer = new aie::Renderer2D();

    // open a font
    m_font = new aie::Font("./font/consolas.ttf", 32);

	// initialise gizmo primitive counts
	Gizmos::create(1000000, 1000000, 1000000, 1000000);

	// position camera
	m_viewMatrix = glm::lookAt(vec3(0, 10, 20), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

    // load n64 as first gameobject
    m_orbitTransforms.push_back(Transform());
    m_gameobjects.push_back(GameObject());
    m_gameobjects[0].loadModelOBJ("./models/n64.obj");

	// set up n64 colors
	for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
	{
		if (i < 8)
		{
			m_gameobjects[0].colors[i] = Vector4(1, 0, 0, 1);
		}
		else if (i < 24)
		{
			m_gameobjects[0].colors[i] = Vector4(1, 1, 0, 1);
		}
		else if (i < 60)
		{
			m_gameobjects[0].colors[i] = Vector4(0, 1, 0, 1);
		}
		else if (i < 96)
		{
			m_gameobjects[0].colors[i] = Vector4(0, 0, 1, 1);
		}
	}
    m_orbitSpeeds.push_back(0);
    m_gameobjectRotationSpeeds.push_back(Vector3(0, 1.5f, 0));
	m_gameobjects[0].transform.setScaleAll(Vector3(4.0f));

    // create gameobjects and orbit transforms
    for (unsigned int i = 1; i < 101; i++)
    {
        // push back a new orbit transform and gameobject
        m_orbitTransforms.push_back(Transform());
        m_gameobjects.push_back(GameObject());
        // load model
        m_gameobjects[i].loadModelOBJ("./models/cube.obj");
        // choose a random base color for the gameobject
        Vector3 baseColor((float)(rand() % 256), (float)(rand() % 256), (float)(rand() % 256));
        // set the gameobjects pallete close to the base color
        m_gameobjects[i].setColorPallete(baseColor.x - 32, baseColor.x + 32, baseColor.y - 32, baseColor.y + 32, baseColor.z - 32, baseColor.z + 32, 255, 255);
        m_gameobjects[i].setColorsRandom();
        // push back a new orbit speed with random float values from -2 to 2
        m_orbitSpeeds.push_back(Vector3(-2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4))));
        // push back a new gameobject rotation speed with random float values from -2 to 2
        m_gameobjectRotationSpeeds.push_back(Vector3(-2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4))));
    }

    // position and parent each gameobject to it's orbit
    for (unsigned int i = 1; i < 101; i++)
    {
        // scale the gameobject somewhere between 0.1 and 0.25
        m_gameobjects[i].transform.setScaleAll(Vector3(0.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.15f))) / 4.0f);
        // create a temporary start position
        Vector3 startPosition(1.0f);
        // randomly negate each value of the start position
        for (unsigned int j = 0; j < 3; j++)
        {
            if (rand() % 2 == 0)
            {
                startPosition[j] -= (2 * startPosition[j]);
            }
        }
        // translate the gameobject to its start position
        m_gameobjects[i].transform.translateAll(startPosition);
        // parent the gameobject to its orbit transform
        m_gameobjects[i].transform.setParent(&m_orbitTransforms[i]);
    }

	// parent n64 to the first orbit transform
    m_gameobjects[0].transform.setParent(&m_orbitTransforms[0]);

	// parent all orbits to the n64
	for (unsigned int i = 1; i < m_orbitTransforms.size(); i++)
	{
		m_orbitTransforms[i].setParent(&m_gameobjects[0].transform);
	}

	return true;
}

void exampleprogram::shutdown() {

	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime) {
    //deltaTime /= 10;

	// query time since application started
	float time = getTime();

	// rotate camera
	//m_viewMatrix = glm::lookAt(vec3(glm::sin(time) * 5, 2.5, glm::cos(time) * 5),
		//vec3(0), vec3(0, 1, 0));

	// wipe the gizmos clean for this frame
	Gizmos::clear();

	aie::Input* input = aie::Input::getInstance();

    // quit if we press escape
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

    // rotate each gameobject and their orbits then update orbits global transforms
    for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
    {
        m_gameobjects[i].transform.rotateAll(deltaTime * m_gameobjectRotationSpeeds[i]);
        m_orbitTransforms[i].rotateAll(deltaTime * m_orbitSpeeds[i]);
        //m_orbitTransforms[i].updateGlobalTransform();
    }
	m_orbitTransforms[0].updateGlobalTransform();
}

void exampleprogram::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// update perspective in case window resized
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

    // draw 2D elements

    // time
    clearScreen();
    m_2dRenderer->setCameraPos(0, 0);
    m_2dRenderer->begin();
    m_2dRenderer->setRenderColour(1, 1, 1, 1);
    //char time[32];
    //sprintf_s(time, 32, "TIME: %i", (int)getTime());

    //m_2dRenderer->drawText(m_font, "NINTENDO 64", 100, (float)getWindowHeight() - 100);

    // stop drawing 2D elements
    m_2dRenderer->end();

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