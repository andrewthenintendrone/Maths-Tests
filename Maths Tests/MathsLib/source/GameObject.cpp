#include "GameObject.h"

// set all colors to be white by default
GameObject::GameObject()
{
    minColorValues = Vector4(255);
    colorDifferences = Vector4(1);
}

// set the minimum and maximum color values for random color generation
void GameObject::setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB, const int& newMinA, const int& newMaxA)
{
    minColorValues = Vector4((float)newMinR, (float)newMinG, (float)newMinB, (float)newMinA);
    colorDifferences = Vector4((float)newMaxR - newMinR + 1, (float)newMaxG - newMinG + 1, (float)newMaxB - newMinB + 1, (float)newMaxA - newMinA + 1);
}

// sets every color randomly using the minimum values and the difference
void GameObject::setColorsRandom()
{
	for (unsigned int currentColor = 0; currentColor < colors.size(); currentColor++)
	{
        colors[currentColor] = Vector4((minColorValues.r + rand() % (int)colorDifferences.r) / 255.0f,
            (minColorValues.g + rand() % (int)colorDifferences.g) / 255.0f,
            (minColorValues.b + rand() % (int)colorDifferences.b) / 255.0f,
            1.0f);
	}
}

// load vertices and faces from a .obj file
void GameObject::load(std::string fileName)
{
	//open model file
	FILE * file;
	fopen_s(&file, fileName.c_str(), "r");

	// return if the file doesn't exist
	if (file == NULL) {
		printf("Impossible to open the file !\n");
		return;
	}

	while (1)
	{
		char lineHeader[256];

		// read the first three characters of the current line
		int res = fscanf_s(file, "%s", lineHeader, sizeof(lineHeader));

		if (res == EOF)
		{
			break; // EOF = End Of File. Quit the loop.
		}

        // if the line has a v at the start it is a vertex
		if (strcmp(lineHeader, "v") == 0)
		{
            // read 3 floats from the line into floats x y and z
			float x, y, z;
			fscanf_s(file, "%f %f %f\n", &x, &y, &z);
            // push back the new vertex
			vertices.push_back(Vector4(x, y, z, 1));
		}
        // if the line has a f at the start it is a face
		if (strcmp(lineHeader, "f") == 0)
		{
            // create an array to store face data with an extra value to read unwanted UV and normal data into
            int facedata[4];
            // read vertex data into array and other data into the extra value
            int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &facedata[0], &facedata[3], &facedata[3], &facedata[1], &facedata[3], &facedata[3], &facedata[2], &facedata[3], &facedata[3]);
			// push back the new face and push back a default white color
			colors.push_back(Vector4(1));
		}
        // copy the vertices into transformed vertices
        transformedVertices = vertices;
	}
}

// generates a random set of vertices and faces which often looks bad
GameObject GameObject::generateRandom()
{
	GameObject temp;
    // push back 20 random vertices with coordinates inside a range
	for (int i = 0; i < 20; i++)
	{
		Vector3 vertex((rand() % 500 - 250) / 100.0f, (rand() % 500 - 250) / 100.0f, (rand() % 500 - 250) / 100.0f);
		temp.vertices.push_back(vertex);
	}
    // push back 5 faces connecting random vertices
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