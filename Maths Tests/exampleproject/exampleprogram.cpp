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

// randomizes the palette of the center GameObject
void exampleprogram::randomizeCenterPalette()
{
    // generate 4 random colors
    Vector4 randomColor1(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    Vector4 randomColor2(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    Vector4 randomColor3(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    Vector4 randomColor4(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);

    // assign random colors to faces
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        if (i < 8)
        {
            m_gameobjects[0].colors[i] = randomColor1;
        }
        else if (i < 24)
        {
            m_gameobjects[0].colors[i] = randomColor2;
        }
        else if (i < 60)
        {
            m_gameobjects[0].colors[i] = randomColor3;
        }
        else if (i < 96)
        {
            m_gameobjects[0].colors[i] = randomColor4;
        }
    }
}

// randomizes the palette of the other GameObjects
void exampleprogram::randomizeOtherPalettes()
{
    for (unsigned int i = 1; i < m_gameobjects.size(); i++)
    {
        // choose a random base color for the current GameObject
        Vector3 baseColor((float)(rand() % 256), (float)(rand() % 256), (float)(rand() % 256));
        // set the GameObjects pallete close to the base color
        m_gameobjects[i].setColorPallete(baseColor.x - 32, baseColor.x + 32, baseColor.y - 32, baseColor.y + 32, baseColor.z - 32, baseColor.z + 32, 255, 255);
        m_gameobjects[i].setColorsRandom();
    }
}

// randomizes the orbit speeds and rotation speeds for all the orbiting objects
void exampleprogram::randomizeOrbits()
{
    for (unsigned int i = 1; i < m_orbitSpeeds.size(); i++)
    {
        // push back a new orbit speed with random float values from -2 to 2
        m_orbitSpeeds[i] = Vector3(-2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)));
        // push back a new gameobject rotation speed with random float values from -2 to 2
        m_gameobjectRotationSpeeds[i] = Vector3(-2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)),
            -2.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4)));
    }
}

// resizes all the orbits 
void exampleprogram::resizeOrbits(const float& ammount)
{
    for (unsigned int i = 1; i < m_gameobjects.size(); i++)
    {
        Vector3 temp (m_gameobjects[i].transform.m_position.vecs[3]);
        temp.normalize();
        temp *= 
        temp.w = 1;
        m_gameobjects[i].transform.m_position = Vector3
    }
}

bool exampleprogram::startup() {

	// set RNG seed
	srand((int)time(NULL));

    // set background to grey
	setBackgroundColour(30.0f / 255.0f, 30.0f / 255.0f, 30.0f / 255.0f, 1);
    //setBackgroundColour(0, 0, 0, 1);

    // create 2d renderer for text etc
    m_2dRenderer = new aie::Renderer2D();

    // open a font
    m_font = new aie::Font("./font/consolas.ttf", 16);

	// initialise gizmo primitive counts
	Gizmos::create(1000000, 1000000, 1000000, 1000000);

	// position camera
	m_viewMatrix = glm::lookAt(vec3(0, 10, 20), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

    // set up center GameObject
    m_orbitTransforms.push_back(Transform());
    m_gameobjects.push_back(GameObject());
    m_gameobjects[0].loadModelOBJ("./models/n64.obj");

    // assign default colors to faces
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

    // load model into a temporary GameObject instead of reading the file many times
    GameObject temporaryGameObject;
    temporaryGameObject.loadModelOBJ("./models/sphere.obj");

    // create gameobjects and orbit transforms
    for (unsigned int i = 1; i < 101; i++)
    {
        // push back a new orbit transform and a new copy of the temporary GameObject
        m_orbitTransforms.push_back(Transform());
        m_gameobjects.push_back(GameObject(temporaryGameObject));

        // push back default rotations of 0
        m_orbitSpeeds.push_back(Vector3(0));
        m_gameobjectRotationSpeeds.push_back(Vector3(0));
    }

    randomizeOrbits();
    randomizeOtherPalettes();

    // position and parent each gameobject to it's orbit
    for (unsigned int i = 1; i < 101; i++)
    {
        // scale the gameobject somewhere between 0.1 and 0.25
        //m_gameobjects[i].transform.setScaleAll(Vector3(0.1f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 0.15f))) / 4.0f);
        m_gameobjects[i].transform.setScaleAll(Vector3(0.1f));
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

	// parent all orbit transforms to the n64
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

    // toggle whether all the gameobjects rotate independantly or as a group with the space bar
    if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
    {
        m_independantMotion = !m_independantMotion;
    }

    // randomize the center objects palette with Q
    if (input->wasKeyPressed(aie::INPUT_KEY_Q))
    {
        randomizeCenterPalette();
    }

    // randomize the other objects palettes with W
    if (input->wasKeyPressed(aie::INPUT_KEY_W))
    {
        randomizeOtherPalettes();
    }

    // randomize all the orbits with E
    if (input->wasKeyPressed(aie::INPUT_KEY_E))
    {
        randomizeOrbits();
    }

    // resize all the orbits with the UP and DOWN keys
    if (input->wasKeyPressed(aie::INPUT_KEY_UP))
    {
        resizeOrbits(0.9f);
    }

    // rotate all GameObjects and their orbit transforms
    if (m_independantMotion == true)
    {
        for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
        {
            m_gameobjects[i].transform.rotateAll(deltaTime * m_gameobjectRotationSpeeds[i]);
            m_orbitTransforms[i].rotateAll(deltaTime * m_orbitSpeeds[i]);
        }
    }
    else
    {
        for (unsigned int i = 0; i < m_orbitTransforms.size(); i++)
        {
            m_gameobjects[i].transform.rotateAll(deltaTime * m_gameobjectRotationSpeeds[i]);
        }
    }
    // update all global transforms
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

    m_2dRenderer->drawText(m_font, "Space Bar: toggle independant motion", 100, (float)getWindowHeight() - 50);
    m_2dRenderer->drawText(m_font, "Q key: randomize center object color palette", 100, (float)getWindowHeight() - 70);
    m_2dRenderer->drawText(m_font, "W key: randomize other objects color palettes", 100, (float)getWindowHeight() - 90);
    m_2dRenderer->drawText(m_font, "E key: randomize orbits", 100, (float)getWindowHeight() - 110);
    m_2dRenderer->drawText(m_font, "UP / DOWN keys: resize orbits", 100, (float)getWindowHeight() - 130);
    m_2dRenderer->drawText(m_font, "ESC: exit example", 100, (float)getWindowHeight() - 150);

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