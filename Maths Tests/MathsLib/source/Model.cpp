#include "Model.h"


Model::Model()
{
	minR = 0;
	maxR = 0;
	minG = 0;
	maxG = 0;
	minB = 0;
	maxB = 0;
}

// set the minimum and maximum color values for random color generation
void Model::setColorPallete(const int& newMinR, const int& newMaxR, const int& newMinG, const int& newMaxG, const int& newMinB, const int& newMaxB)
{
	minR = newMinR;
	maxR = newMaxR;
	minG = newMinG;
	maxG = newMaxG;
	minB = newMinB;
	maxB = newMaxB;
}

// changes to a random color within the minimum and maximum values
void Model::setColorsRandom()
{
	for (unsigned int currentColor = 0; currentColor < colors.size(); currentColor++)
	{
		colors[currentColor] = Vector4((minR + rand() % (maxR - minR + 1)) / 255.0f, (minG + rand() % (maxG - minG + 1)) / 255.0f, (minB + 1 + rand() % (maxB - minB + 1)) / 255.0f, 1.0f);
	}
}

void Model::rotateX(const float& ammount)
{
	Matrix3 rotationMatrix;
	rotationMatrix.setRotateX(ammount);
	for (unsigned int v = 0; v < vertices.size(); v++)
	{
		vertices[v] = rotationMatrix * vertices[v];
	}
}

void Model::rotateY(const float& ammount)
{
	Matrix3 rotationMatrix;
	rotationMatrix.setRotateY(ammount);
	for (unsigned int v = 0; v < vertices.size(); v++)
	{
		vertices[v] = rotationMatrix * vertices[v];
	}
}

void Model::rotateZ(const float& ammount)
{
	Matrix3 rotationMatrix;
	rotationMatrix.setRotateZ(ammount);
	for (unsigned int v = 0; v < vertices.size(); v++)
	{
		vertices[v] = rotationMatrix * vertices[v];
	}
}

void Model::scale(Vector3& scaleVector)
{
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		vertices[i] *= scaleVector;
	}
}

void Model::translate(Vector3& translation)
{
	for (unsigned int v = 0; v < vertices.size(); v++)
	{
		vertices[v] += translation;
	}
}

void Model::load(std::string fileName)
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
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf_s(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			Vector3 temp;
			temp.x = (float)vertexIndex[0] - 1;
			temp.y = (float)vertexIndex[1] - 1;
			temp.z = (float)vertexIndex[2] - 1;
			faces.push_back(temp);
			colors.push_back(Vector4(1));
		}
	}
}

Model Model::generateRandom()
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