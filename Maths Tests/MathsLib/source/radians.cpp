#define PI 3.1415926535897932384626433832795f

float degreesToRadians(const float& degrees)
{
	return degrees * PI / 180.0f;
}

float radiansToDegrees(const float& radians)
{
	return radians * 180.0f / PI;
}

float degreesToRadians(const int& degrees)
{
	return degrees * PI / 180.0f;
}

float radiansToDegrees(const int& radians)
{
	return radians * 180.0f / PI;
}