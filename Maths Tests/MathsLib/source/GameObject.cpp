#include "GameObject.h"


GameObject::GameObject()
{
    minColorValues = Vector3(255);
    colorDifferences = Vector3(1);
}

// set the minimum and maximum color values for random color generation
void GameObject::setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB)
{
    minColorValues = Vector3(newMinR, newMinG, newMinB);
    colorDifferences = Vector3(newMaxR - newMinR + 1, newMaxG - newMinG + 1, newMaxB - newMinB + 1);
}

// changes to a random color within the minimum and maximum values
void GameObject::setColorsRandom()
{
	for (unsigned int currentColor = 0; currentColor < colors.size(); currentColor++)
	{
        colors[currentColor] = Vector4((minColorValues.r + rand() % (int)colorDifferences.r) / 255.0f, (minColorValues.g + rand() % (int)colorDifferences.g) / 255.0f, (minColorValues.b + rand() % (int)colorDifferences.b) / 255.0f, 0.5f);
	}
}

void GameObject::load(std::string fileName)
{
	//open GameObject
	FILE * file;
	fopen_s(&file, fileName.c_str(), "r");

	// break if the GameObject doesn't exist
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
			vertices.push_back(Vector4(x, y, z, 1));
		}
		if (strcmp(lineHeader, "f") == 0)
		{
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			Vector3 temp;
			temp.x = (float)vertexIndex[0] - 1;
			temp.y = (float)vertexIndex[1] - 1;
			temp.z = (float)vertexIndex[2] - 1;
			faces.push_back(temp);
			colors.push_back(Vector4(1));
		}
        transformedVertices = vertices;
	}
}

GameObject GameObject::generateRandom()
{
	GameObject temp;
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

// transforms each vert by the global transform and stores them in transformedVertices
void GameObject::updateVerts()
{
    for (unsigned int i = 0; i < transformedVertices.size(); i++)
    {
        transformedVertices[i] = transform.m_globalTransform * vertices[i];
    }
}