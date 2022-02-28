#include "exampleprogram.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

using namespace AMMaths;

exampleprogram::exampleprogram()
{

}

exampleprogram::~exampleprogram()
{

}

// randomizes the palette of the center GameObject
void exampleprogram::colorCenterObject(Vector4& color1, Vector4& color2, Vector4& color3, Vector4& color4)
{
    // apply random colors to faces
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        if (i < 16)
        {
            m_gameobjects[0].colors[i] = color1 / 255.0f;
        }
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = color2 / 255.0f;
        }
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = color3 / 255.0f;
        }
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = color4 / 255.0f;
        }
    }
}

// randomizes the palette of the other GameObjects
void exampleprogram::randomizeOtherPalettes()
{
    // create a distribution between 0 and 255
    std::uniform_int_distribution<int> range(0, 255);

    for (unsigned int i = 1; i < m_gameobjects.size(); i++)
    {
        // choose a random base color for the current GameObject
        Vector3 baseColor = Vector3((float)range(m_prng), (float)range(m_prng), (float)range(m_prng));
        // set the GameObjects pallete close to the base color
        m_gameobjects[i].setColorPallete(baseColor.x - 32, baseColor.x + 32, baseColor.y - 32, baseColor.y + 32, baseColor.z - 32, baseColor.z + 32, 255, 255);
        m_gameobjects[i].setColorsRandom(m_prng);
    }
}

// randomizes the orbit speeds and rotation speeds for all the orbiting objects
void exampleprogram::randomizeOrbits()
{
    // create a distribution between -2 and 2
    std::uniform_real_distribution<float> range(-2.0f, 2.0f);

    for (unsigned int i = 1; i < m_orbitSpeeds.size(); i++)
    {
        // push back a new orbit speed with random float values from -2 to 2
        m_orbitSpeeds[i] = Vector3(range(m_prng), range(m_prng), range(m_prng));
        // push back a new gameobject rotation speed with random float values from -2 to 2
        m_gameobjectRotationSpeeds[i] = Vector3(range(m_prng), range(m_prng), range(m_prng));
    }
}

// exits
void exampleprogram::exit()
{
    // freeze all objects
    for (unsigned int i = 0; i < m_gameobjectRotationSpeeds.size(); i++)
    {
        m_gameobjectRotationSpeeds[i] = Vector3(0);
    }
    for (unsigned int i = 0; i < m_orbitSpeeds.size(); i++)
    {
        m_orbitSpeeds[i] = Vector3(0);
    }

    // create distribution from 0 to 4
    std::uniform_int_distribution<int> range(0, 4);

    // create some colors
    Vector4 exitColors[5] = { Vector4(179, 129, 56, 255), Vector4(211, 145, 43, 255), Vector4(210, 127, 41, 255), Vector4(217, 95, 27, 255), Vector4(160, 32, 26, 255) };
    
    // color all objects using one of the colors
    for (unsigned int i = 1; i < m_gameobjects.size(); i++)
    {
        Vector3 baseColor = exitColors[range(m_prng)];
        m_gameobjects[i].setColorPallete(baseColor.r, baseColor.r, baseColor.g, baseColor.g, baseColor.b, baseColor.b, 255, 255);
        m_gameobjects[i].setColorsRandom(m_prng);
    }

    // set the center GameObjects colors
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        if (i < 16)
        {
            m_gameobjects[0].colors[i] = exitColors[0] / 255.0f;
        }
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = exitColors[1] / 255.0f;
        }
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = exitColors[2] / 255.0f;
        }
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = exitColors[3] / 255.0f;
        }
    }

    // slight zoom
    m_viewMatrix = glm::lookAt(vec3(0, 9.5f, 19), vec3(0), vec3(0, 1, 0));
}

bool exampleprogram::startup()
{
    // load resources
    m_2dRenderer = new aie::Renderer2D;
    m_font = new aie::Font("./resources/font/Roboto-Regular.ttf", 20);
    m_exitTexture = new aie::Texture("./resources/textures/tobecontinued.png");
    m_exitTexturePositionX = (float)getWindowWidth();
    m_exitMusic = new aie::Audio("./resources/audio/roundabout.wav");

    // seed rng
    unsigned seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
    m_prng = std::default_random_engine(seed);

    // initialise gizmo primitive counts
    Gizmos::create(1000000, 1000000, 1000000, 1000000);

    // set background color
    m_brightness = 0;
    setBackgroundColour(m_brightness, m_brightness, m_brightness, 1);

	// set up view and projection matrices
	m_viewMatrix = glm::lookAt(vec3(0, 10, 20), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

    // create center orbit transform and GameObject
    m_orbitTransforms.push_back(Transform());
    m_gameobjects.push_back(GameObject());
    m_gameobjects[0].loadModelOBJ("./resources/models/n64.obj");

    // assign default colors to center GameObjects faces
    Vector4 red(254.0f, 32.0f, 21.0f, 255.0f);
    Vector4 yellow(255.0f, 192.0f, 1.0f, 255.0f);
    Vector4 green(6.0f, 147.0f, 48.0f, 255.0f);
    Vector4 blue(1.0f, 29.0f, 169.0f, 255.0f);
    colorCenterObject(red, yellow, green, blue);

    // set rotation speed, and scale of center GameObject
    m_orbitSpeeds.push_back(0);
    m_gameobjectRotationSpeeds.push_back(Vector3(0, 1.5f, 0));
	m_gameobjects[0].transform.setScaleAll(Vector3(4.0f));

    // create a distribution between A-Z
    std::uniform_int_distribution<int> letters((int)'A', (int)'Z');

    // create the rest of the GameObjects
    for (unsigned int i = 1; i < 101; i++)
    {
        // push back a GameObject along with a Transform to orbit around
        m_orbitTransforms.push_back(Transform());
        m_gameobjects.push_back(GameObject());

        // pick a random letter and load that model
        std::string file = "./resources/models/letters/";
        file.push_back((char)letters(m_prng));
        file.append (".obj");
        m_gameobjects[i].loadModelOBJ(file);

        // push back default rotations of 0
        m_orbitSpeeds.push_back(Vector3());
        m_gameobjectRotationSpeeds.push_back(Vector3());
    }

    // randomize orbits and colors of other GameObjects
    randomizeOrbits();
    randomizeOtherPalettes();

    // further set up GameObjects and orbits
    for (unsigned int i = 1; i < 101; i++)
    {
        // set GameObject scale to 0.1
        m_gameobjects[i].transform.setScaleAll(Vector3(0.1f));

        // create a distribution of either 1 or 2
        std::uniform_int_distribution<int> range(1, 2);

        // place the GameObject at a new position with each value being either positive or negative 1
        m_gameobjects[i].transform.translateAll(Vector3(((range(m_prng) % 2 == 0) ? -1.0f : 1.0f),
            ((range(m_prng) % 2 == 0) ? -1.0f : 1.0f),
            ((range(m_prng) % 2 == 0) ? -1.0f : 1.0f)));

        // parent the gameobject to its orbit
        m_gameobjects[i].transform.setParent(&m_orbitTransforms[i]);
    }

    m_gameobjects[0].transform.setParent(&m_orbitTransforms[0]);

	// parent all orbit transforms to the center GameObjects Transform
	for (unsigned int i = 1; i < m_orbitTransforms.size(); i++)
	{
		m_orbitTransforms[i].setParent(&m_gameobjects[0].transform);
	}

    for (unsigned int i = 0; i < m_gameobjects.size(); i++)
    {
        for (unsigned int j = 0; j < m_gameobjects.size(); j++)
        {
            m_facecount++;
        }
    }

	return true;
}

void exampleprogram::shutdown()
{
    delete m_2dRenderer;
    delete m_font;
    delete m_exitTexture;
    delete m_exitMusic;
	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime)
{
	// query time since application started
	float time = getTime();

	// wipe the gizmos clean for this frame
	Gizmos::clear();

    // check input
	aie::Input* input = aie::Input::getInstance();

    // exit if escape is pressed
    if (input->wasKeyPressed(aie::INPUT_KEY_ESCAPE))
    {
        if (m_exiting == false)
        {
            m_exitMusic->setLooping(false);
            m_exitMusic->play();
            m_exiting = true;
        }
        else
        {
            quit();
        }
    }

    // when exiting no other commands work
    if (m_exiting == true)
    {
        if (m_exittimer > 0)
        {
            m_exittimer -= deltaTime;
        }
        else
        {
            if (m_exitTexturePositionX > getWindowWidth() / 1920.0f * 100.0f)
            {
                m_exitTexturePositionX -= (getWindowWidth() * 4.0f * deltaTime);
                if (m_exitTexturePositionX < getWindowWidth() / 1920.0f * 100.0f)
                {
                    m_exitTexturePositionX = getWindowWidth() / 1920.0f * 100.0f;
                    exit();
                }
            }
        }
        if (m_exitMusic->getIsPlaying() == false)
        {
            quit();
        }
    }
    else
    {
        // toggle whether all the gameobjects rotate independantly or as a group with the space bar
        if (input->wasKeyPressed(aie::INPUT_KEY_SPACE))
        {
            m_independantMotion = !m_independantMotion;
        }

        // randomize the center objects palette with Q
        if (input->wasKeyPressed(aie::INPUT_KEY_Q))
        {
            // create a distribution between 0 and 1
            std::uniform_int_distribution<int> range(0, 255);

            // generate 4 random colors
            Vector4 randomColor1((float)range(m_prng), (float)range(m_prng), (float)range(m_prng), 255.0f);
            Vector4 randomColor2((float)range(m_prng), (float)range(m_prng), (float)range(m_prng), 255.0f);
            Vector4 randomColor3((float)range(m_prng), (float)range(m_prng), (float)range(m_prng), 255.0f);
            Vector4 randomColor4((float)range(m_prng), (float)range(m_prng), (float)range(m_prng), 255.0f);

            colorCenterObject(randomColor1, randomColor2, randomColor3, randomColor4);
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

int exampleprogram::getNumFaces()
{
    unsigned int numFaces = 0;
    for (unsigned int i = 0; i < m_gameobjects.size(); i++)
    {
        for (unsigned int j = 0; j < m_gameobjects[i].faces.size(); j++)
        {
            numFaces++;
        }
    }
    return numFaces;
}

void exampleprogram::draw() {

	// wipe the screen to the background colour
	clearScreen();

    // render 2D elements
    clearScreen();
    m_2dRenderer->setCameraPos(0, 0);
    m_2dRenderer->begin();
    m_2dRenderer->setRenderColour(1 - m_brightness, 1 - m_brightness, 1 - m_brightness, 1);

    if (m_exiting)
    {
        m_2dRenderer->drawSprite(m_exitTexture, m_exitTexturePositionX, getWindowHeight() / 1080.0f * 100.0f, getWindowWidth() / 1920.0f * 486.0f, getWindowHeight() / 1080.0f * 110.0f, 0, 0, 0, 0);
    }
    else
    {
        m_2dRenderer->drawText(m_font, "Space Bar: toggle independant motion", 100, (float)getWindowHeight() - 50);
        m_2dRenderer->drawText(m_font, "Q key: randomize center object color palette", 100, (float)getWindowHeight() - 70);
        m_2dRenderer->drawText(m_font, "W key: randomize other objects color palettes", 100, (float)getWindowHeight() - 90);
        m_2dRenderer->drawText(m_font, "E key: randomize orbits", 100, (float)getWindowHeight() - 110);
        m_2dRenderer->drawText(m_font, "1 and 2 keys: change background brightness", 100, (float)getWindowHeight() - 130);
        m_2dRenderer->drawText(m_font, "ESC: exit example", 100, (float)getWindowHeight() - 170);
        char faces[32];
        sprintf_s(faces, 32, "Number of Faces: %i", m_facecount);
        m_2dRenderer->drawText(m_font, faces, 0.0f, 0.0f, 0.0f);
    }

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