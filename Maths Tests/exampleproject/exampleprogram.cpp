#include "exampleprogram.h"
#include "Gizmos.h"
#include "Input.h"
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

	// initialise gizmo primitive counts
	Gizmos::create(50000, 50000, 50000, 50000);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(0, 0, -10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

	// load models
	models.push_back(Model());
	models.push_back(Model());
	models.push_back(Model());
	models.push_back(Model());

	models[0].load("./models/sphere.obj");
	models[0].setColorPallete(96, 160, 0, 0, 191, 255);
	models[0].scale(Vector3(0.75f, 0.75f, 0.75f));
	models[0].setColorsRandom();

	models[1].load("./models/andrew.obj");
	models[1].setColorPallete(191, 255, 96, 160, 0, 0);
	models[1].scale(Vector3(0.25f, 0.25f, 0.25f));
	models[1].setColorsRandom();

	models[2].load("./models/cube.obj");
	models[2].setColorPallete(10, 30, 10, 30, 10, 30);
	models[2].scale(Vector3(0.5f, 0.5f, 0.5f));
	models[2].setColorsRandom();

	models[3].load("./models/monkey.obj");
	models[3].setColorPallete(235, 255, 235, 255, 235, 255);
	models[2].scale(Vector3(1.0f, 1.0f, 1.0f));
	models[3].setColorsRandom();

	return true;
}

void exampleprogram::shutdown() {

	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime) {

	// query time since application started
	float time = getTime();

	// rotate camera
	//m_viewMatrix = glm::lookAt(vec3(glm::sin(time) * 5, 0, glm::cos(time) * 5),
		//vec3(0), vec3(0, 1, 0));

	// wipe the gizmos clean for this frame
	Gizmos::clear();

	// draw a simple grid with gizmos
	Vector4 black(0, 0, 0, 1);
	Vector4 white(1);
	Vector4 red(1, 0, 0, 1);
	Vector4 orange(0.5f, 1.0f, 0.0f, 1.0f);
	Vector4 yellow(1, 1, 0, 1);
	Vector4 green(0, 1, 0, 1);
	Vector4 blue(0, 0, 1, 1);
	Vector4 purple(0.5f, 0.0f, 1.0f, 1.0f);


	// rotate sun
	if (time < 3)
	{
		models[0].translate(Vector3::Right() * deltaTime);
		models[1].translate(Vector3::Left() * deltaTime);
		models[2].translate(Vector3::Up() * deltaTime);
		models[3].translate(Vector3::Down() * deltaTime);
	}
	else
	{
		switch ((int)time % 3)
		{
		case 0:
			models[0].rotateX(deltaTime * 2.0);
			models[1].rotateX(deltaTime * 2.0);
			models[2].rotateX(deltaTime * 2.0);
			models[3].rotateX(deltaTime * 2.0);
			break;
			
		case 1:
			models[0].rotateY(deltaTime * 2.0);
			models[1].rotateY(deltaTime * 2.0);
			models[2].rotateY(deltaTime * 2.0);
			models[3].rotateY(deltaTime * 2.0);
			break;

		case 2:
			models[0].rotateZ(deltaTime * 2.0);
			models[1].rotateZ(deltaTime * 2.0);
			models[2].rotateZ(deltaTime * 2.0);
			models[3].rotateZ(deltaTime * 2.0);
			break;
		}
	}

	for (unsigned int i = 0; i < models.size(); i++)
	{
		currentModel = models[i];
		for (unsigned int j = 0; j < currentModel.faces.size(); j++)
		{
			Gizmos::addTri(currentModel.vertices[(int)currentModel.faces[j].x].toGLM(),
				currentModel.vertices[(int)currentModel.faces[j].y].toGLM(), 
				currentModel.vertices[(int)currentModel.faces[j].z].toGLM(), 
				currentModel.colors[j].toGLM());

			/*Gizmos::addLine(currentModel.vertices[(int)currentModel.faces[j].x].toGLM(),
				currentModel.vertices[(int)currentModel.faces[j].y].toGLM(),
				blue.toGLM());

			Gizmos::addLine(currentModel.vertices[(int)currentModel.faces[j].y].toGLM(),
				currentModel.vertices[(int)currentModel.faces[j].z].toGLM(),
				blue.toGLM());

			Gizmos::addLine(currentModel.vertices[(int)currentModel.faces[j].z].toGLM(),
				currentModel.vertices[(int)currentModel.faces[j].x].toGLM(),
				blue.toGLM());*/
		}
	}

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void exampleprogram::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// update perspective in case window resized
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);
}