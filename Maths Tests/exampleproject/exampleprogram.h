#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>
#include <vector>
#include <MathsLib.h>

struct Model
{
	std::vector<Vector3>vertices;
	std::vector<Vector3>faces;

	void load(std::string fileName)
	{
		//open model
		FILE * file;
		fopen_s(&file, fileName.c_str(), "r");

		// break if the model doesn't exist
		if (file == NULL) {
			printf("Impossible to open the file !\n");
			return;
		}

		while (1)
		{
			char lineHeader[256];

			// read the first word of the line
			int res = fscanf_s(file, "%s", lineHeader, sizeof(lineHeader));

			if (res == EOF)
			{
				break; // EOF = End Of File. Quit the loop.
			}

			if (strcmp(lineHeader, "v") == 0)
			{
				float x, y, z;
				fscanf_s(file, "%f %f %f\n", &x, &y, &z);
				vertices.push_back(Vector3(x, y, z));
			}
			if (strcmp(lineHeader, "f") == 0)
			{
				int x, y, z;
				fscanf_s(file, "%d %d %d\n", &x, &y, &z);
				faces.push_back(Vector3{ (float)x - 1, (float)y - 1, (float)z - 1 });
			}
		}
	}

	static Model generateRandom()
	{
		Model temp;
		for (int i = 0; i < 20; i++)
		{
			Vector3 vertex((rand() % 500 - 250) / 100.0f, (rand() % 500 - 250) / 100.0f, (rand() % 500 - 250) / 100.0f);
			temp.vertices.push_back(vertex);
		}
		for (int i = 0; i < 5; i++)
		{
			temp.faces.push_back(Vector3());
			temp.faces[i].x = (float)(rand() % 20);
			temp.faces[i].y = (float)(rand() % 20);
			temp.faces[i].z = (float)(rand() % 20);
		}
		return temp;
	}
};

class exampleprogram : public aie::Application {
public:

	exampleprogram();
	virtual ~exampleprogram();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	std::vector<Model>models;

protected:

	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};