#include "exampleprogram.h"

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

// loads 2D elements
void exampleprogram::setUp2D()
{
    // create 2d renderer
    m_2dRenderer = new aie::Renderer2D;

    // load font
    m_font = new aie::Font("./resources/font/Roboto-Regular.ttf", 20);

    // load exit image
    m_exitTexture = new aie::Texture("./resources/textures/tbc.png");

    // put exit texture on the right side of the screen
    m_exitTexturePositionX = (float)getWindowWidth();
}

// loads audio elements
void exampleprogram::setUpAudio()
{
    m_exitMusic = new aie::Audio("./resources/audio/roundabout.wav");
}

// creates the RNG engine and seeds it
void exampleprogram::setUpRNG()
{
    // generate seed from time since epoch
    unsigned seed = (unsigned int)std::chrono::system_clock::now().time_since_epoch().count();
    // apply seed to rng engine
    m_prng = std::default_random_engine(seed);
}

// randomizes the palette of the center GameObject
void exampleprogram::randomizeCenterPalette()
{
    // create a distribution between 0 and 1
    std::uniform_real_distribution<float> range(0.0f, 1.0f);

    // generate 4 random colors
    Vector4 randomColor1(range(m_prng), range(m_prng), range(m_prng), 1);
    Vector4 randomColor2(range(m_prng), range(m_prng), range(m_prng), 1);
    Vector4 randomColor3(range(m_prng), range(m_prng), range(m_prng), 1);
    Vector4 randomColor4(range(m_prng), range(m_prng), range(m_prng), 1);

    // apply random colors to faces
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        if (i < 16)
        {
            m_gameobjects[0].colors[i] = randomColor1;
        }
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = randomColor2;
        }
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = randomColor3;
        }
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = randomColor4;
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
    std::uniform_int_distribution<int> range(1, 4);
    // create palletes
    Vector4 colors[5] = { Vector4(179, 129, 56, 255), Vector4(211, 145, 43, 255), Vector4(210, 127, 41, 255), Vector4(217, 95, 27, 255), Vector4(160, 32, 26, 255) };
    // color all objects
    for (unsigned int i = 1; i < m_gameobjects.size(); i++)
    {
        Vector3 baseColor = colors[range(m_prng)];
        m_gameobjects[i].setColorPallete(baseColor.r, baseColor.r, baseColor.g, baseColor.g, baseColor.b, baseColor.b, 255, 255);
        m_gameobjects[i].setColorsRandom(m_prng);
    }

    // color center object
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        if (i < 16)
        {
            m_gameobjects[0].colors[i] = colors[0] / 255.0f;
        }
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = colors[1] / 255.0f;
        }
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = colors[2] / 255.0f;
        }
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = colors[3] / 255.0f;
        }
    }
}

bool exampleprogram::startup()
{
    // set up 2D elements
    setUp2D();

    // set up audio elements
    setUpAudio();

	// set up RNG
    setUpRNG();

    // set background to black
    m_brightness = 0;
    setBackgroundColour(m_brightness, m_brightness, m_brightness, 1);

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
    m_gameobjects[0].loadModelOBJ("./resources/models/n64.obj");

    // assign default colors to faces
    for (unsigned int i = 0; i < m_gameobjects[0].colors.size(); i++)
    {
        // red
        if (i < 16)
        {
            m_gameobjects[0].colors[i] = Vector4(254, 32, 21, 255) / 255.0f;
        }
        // yellow
        else if (i < 32)
        {
            m_gameobjects[0].colors[i] = Vector4(255, 192, 1, 255) / 255.0f;
        }
        // green
        else if (i < 80)
        {
            m_gameobjects[0].colors[i] = Vector4(6, 147, 48, 255) / 255.0f;
        }
        // blue
        else if (i < 128)
        {
            m_gameobjects[0].colors[i] = Vector4(1, 29, 169, 255) / 255.0f;
        }
    }
    m_orbitSpeeds.push_back(0);
    m_gameobjectRotationSpeeds.push_back(Vector3(0, 1.5f, 0));
	m_gameobjects[0].transform.setScaleAll(Vector3(4.0f));

    // load model into a temporary GameObject instead of reading the file many times
    /*GameObject temporaryGameObject;
    temporaryGameObject.loadModelOBJ("./resources/models/sphere.obj");*/

    // create letter distribution
    std::uniform_int_distribution<int> letters(65, 90);

    // create gameobjects and orbit transforms
    for (unsigned int i = 1; i < 101; i++)
    {
        // push back a new orbit transform and a new copy of the temporary GameObject
        m_orbitTransforms.push_back(Transform());
        m_gameobjects.push_back(GameObject());

        std::string file = "./resources/models/letters/";
        file.push_back((char)letters(m_prng));
        file.append (".obj");

        std::cout << file;

        // loads random letter for model
        m_gameobjects[i].loadModelOBJ(file);

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
        m_gameobjects[i].transform.setScaleAll(Vector3(0.1f));
        // create a temporary start position
        Vector3 startPosition(1.0f);

        // create a distribution of either 1 or 2
        std::uniform_int_distribution<int> range(1, 2);

        // randomly negate each value of the start position
        for (unsigned int j = 0; j < 3; j++)
        {
            if (range(m_prng) % 2 == 0)
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

	aie::Input* input = aie::Input::getInstance();

    // exit if escape is pressed
    if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
    {
        if (m_exiting == false)
        {
            m_exitMusic->setLooping(false);
            m_exitMusic->play();
            m_exiting = true;
        }
    }

    // if exiting count down
    if (m_exiting == true)
    {
        if (m_exittimer > 0)
        {
            m_exittimer -= deltaTime;
        }
        else
        {
            if (m_exitTexturePositionX > 100.0f)
            {
                m_exitTexturePositionX -= (getWindowWidth() * 3.0f * deltaTime);
                if (m_exitTexturePositionX < 100.0f)
                {
                    m_exitTexturePositionX = 100.0f;
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

    if (m_exiting)
    {
        m_2dRenderer->drawSprite(m_exitTexture, m_exitTexturePositionX, 100.0f, 0, 0, 0, 0, 0, 0);
    }
    else
    {
        m_2dRenderer->drawText(m_font, "Space Bar: toggle independant motion", 100, (float)getWindowHeight() - 50);
        m_2dRenderer->drawText(m_font, "Q key: randomize center object color palette", 100, (float)getWindowHeight() - 70);
        m_2dRenderer->drawText(m_font, "W key: randomize other objects color palettes", 100, (float)getWindowHeight() - 90);
        m_2dRenderer->drawText(m_font, "E key: randomize orbits", 100, (float)getWindowHeight() - 110);
        m_2dRenderer->drawText(m_font, "1 and 2 keys: change background brightness", 100, (float)getWindowHeight() - 130);
        m_2dRenderer->drawText(m_font, "ESC: exit example", 100, (float)getWindowHeight() - 170);
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