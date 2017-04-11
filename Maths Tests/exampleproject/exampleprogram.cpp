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
	Gizmos::create(20000, 20000, 20000, 20000);

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(0, 0, 10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(5.0f,
		getWindowWidth() / (float)getWindowHeight(),
		0.1f, 1000.f);

	// load models
	models.push_back(Model());

	models[0].load("./models/sun.obj");

	return true;
}

void exampleprogram::shutdown() {

	Gizmos::destroy();
}

void exampleprogram::update(float deltaTime) {

	// query time since application started
	float time = getTime();

	// rotate camera
	m_viewMatrix = glm::lookAt(vec3(glm::sin(time * 2) * 10, 0, glm::cos(time * 2) * 10),
		vec3(0), vec3(0, 1, 0));

	// wipe the gizmos clean for this frame
	Gizmos::clear();

	// draw a simple grid with gizmos
	Vector4 black(0, 0, 0, 1);
	Vector4 white(1);
	Vector4 orange(0.5f, 1.0f, 0.0f, 1.0f);
	Vector4 purple(0.5f, 0.0f, 1.0f, 1.0f);

	for (unsigned int i = 0; i < models.size(); i++)
	{
		for (unsigned int j = 0; j < models[i].faces.size(); j++)
		{
			Gizmos::addTri(models[i].vertices[models[i].faces[j].x].toGLM(), models[i].vertices[models[i].faces[j].y].toGLM(), models[i].vertices[models[i].faces[j].z].toGLM(), black.toGLM());
			Gizmos::addLine(models[i].vertices[models[i].faces[j].x].toGLM(), models[i].vertices[models[i].faces[j].y].toGLM(), purple.toGLM());
			Gizmos::addLine(models[i].vertices[models[i].faces[j].y].toGLM(), models[i].vertices[models[i].faces[j].z].toGLM(), purple.toGLM());
			Gizmos::addLine(models[i].vertices[models[i].faces[j].z].toGLM(), models[i].vertices[models[i].faces[j].x].toGLM(), purple.toGLM());
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