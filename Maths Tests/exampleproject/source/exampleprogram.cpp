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

using namespace AFMaths;

exampleprogram::exampleprogram()
{

}

exampleprogram::~exampleprogram()
{

}

// randomizes the palette of the center GameObject
void exampleprogram::randomizeCenterPalette()
{
    // generate 4 random colors
    Vector4 randomColor1(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    Vector4 randomColor2(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    /*Vector4 randomColor3(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);
    Vector4 randomColor4(rand() % 256 / 255.0f, rand() % 256 / 255.0f, rand() % 256 / 255.0f, 1);*/
    // apply random colors to faces
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        /*if (i < 16)
        {
            m_gameobjects[0].colors[i] = Vector4(254, 32, 21, 255) / 255.0f;
        }
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = Vector4(255, 192, 1, 255) / 255.0f;
        }
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = Vector4(6, 147, 48, 255) / 255.0f;
        }
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = Vector4(1, 29, 169, 255) / 255.0f;
        }*/

        if (i % 2 == 0)
        {
            m_gameobjects[0].colors[i] = randomColor1;
        }
        else
        {
            m_gameobjects[0].colors[i] = randomColor2;
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

bool exampleprogram::startup()
{

	// set RNG seed
	srand((int)time(NULL));

    // set background to black
    m_brightness = 0;
    setBackgroundColour(m_brightness, m_brightness, m_brightness, 1);

    // create 2d renderer for text etc
    m_2dRenderer = new aie::Renderer2D();

    // open a font
    m_font = new aie::Font("./resources/font/Roboto-Regular.ttf", 20);

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
    m_gameobjects[0].loadModelOBJ("./resources/models/cat.obj");

    // assign default colors to faces
    //for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    //{
    //    // red
    //    if (i < 16)
    //    {
    //        m_gameobjects[0].colors[i] = Vector4(254, 32, 21, 255) / 255.0f;
    //    }
    //    // yellow
    //    else if (i < 32)
    //    {
    //        m_gameobjects[0].colors[i] = Vector4(255, 192, 1, 255) / 255.0f;
    //    }
    //    // green
    //    else if (i < 80)
    //    {
    //        m_gameobjects[0].colors[i] = Vector4(6, 147, 48, 255) / 255.0f;
    //    }
    //    // blue
    //    else if (i < 128)
    //    {
    //        m_gameobjects[0].colors[i] = Vector4(1, 29, 169, 255) / 255.0f;
    //    }
    //}
    randomizeCenterPalette();
    m_orbitSpeeds.push_back(0);
    m_gameobjectRotationSpeeds.push_back(Vector3(0, 1.5f, 0));
	m_gameobjects[0].transform.setScaleAll(Vector3(4.0f));

    // load model into a temporary GameObject instead of reading the file many times
    GameObject temporaryGameObject;
    temporaryGameObject.loadModelOBJ("./resources/models/sphere.obj");

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

    // randomize orbits and colors of othr GameObjects
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

void exampleprogram::shutdown()
{

	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime)
{

	// query time since application started
	float time = getTime();

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

    // change background brightness with 1 and 2 keys
    if (input->isKeyDown(aie::INPUT_KEY_1))
    {
        if (m_brightness > 0)
        {
            m_brightness -= (deltaTime);
        }
        else
        {
            m_brightness = 0;
        }

        setBackgroundColour(m_brightness, m_brightness, m_brightness, 1);
    }

    if (input->isKeyDown(aie::INPUT_KEY_2))
    {
        if (m_brightness < 1)
        {
            m_brightness += (deltaTime);
        }
        else
        {
            m_brightness = 1;
        }

        setBackgroundColour(m_brightness, m_brightness, m_brightness, 1);
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

    // render 2D elements
    clearScreen();
    m_2dRenderer->setCameraPos(0, 0);
    m_2dRenderer->begin();
    m_2dRenderer->setRenderColour(1 - m_brightness, 1 - m_brightness, 1 - m_brightness, 1);

    m_2dRenderer->drawText(m_font, "Space Bar: toggle independant motion", 100, (float)getWindowHeight() - 50);
    m_2dRenderer->drawText(m_font, "Q key: randomize center object color palette", 100, (float)getWindowHeight() - 70);
    m_2dRenderer->drawText(m_font, "W key: randomize other objects color palettes", 100, (float)getWindowHeight() - 90);
    m_2dRenderer->drawText(m_font, "E key: randomize orbits", 100, (float)getWindowHeight() - 110);
    m_2dRenderer->drawText(m_font, "1 and 2 keys: change background brightness", 100, (float)getWindowHeight() - 130);
    m_2dRenderer->drawText(m_font, "ESC: exit example", 100, (float)getWindowHeight() - 170);

    // stop drawing 2D elements
    m_2dRenderer->end();

    // update perspective in case window resized
    m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
        getWindowWidth() / (float)getWindowHeight(),
        0.1f, 1000.f);

    // draw 3D elements
    for (unsigned int i = 0; i < m_gameobjects.size(); i++)
    {
        m_gameobjects[i].updateVerts();
        if (i != m_gameobjects.size() - 1)
        {
            Gizmos::addLine(m_gameobjects[i].transform.m_globalTransform[3].toGLM3(), m_gameobjects[i + 1].transform.m_globalTransform[3].toGLM3(), glm::vec4(0, 1, 0, 1));
        }
        else
        {
            Gizmos::addLine(m_gameobjects[i].transform.m_globalTransform[3].toGLM3(), m_gameobjects[0].transform.m_globalTransform[3].toGLM3(), glm::vec4(0, 1, 0, 1));
        }
        for (unsigned int j = 0; j < m_gameobjects[i].faces.size(); j++)
        {
            Gizmos::addTri(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
                m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
                m_gameobjects[i].colors[j].toGLM());

            // draw edges in black
            /*Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            glm::vec4(0, 1, 0, 1));

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].y].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            glm::vec4(0, 1, 0, 1));

            Gizmos::addLine(m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].z].toGLM3(),
            m_gameobjects[i].transformedVertices[(int)m_gameobjects[i].faces[j].x].toGLM3(),
            glm::vec4(0, 1, 0, 1));*/
        }
    }

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);
}