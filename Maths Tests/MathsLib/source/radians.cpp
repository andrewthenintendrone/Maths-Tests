#include "radians.h"

namespace AFMaths
{
    float degreesToRadians(const float& degrees)
    {
        return degrees * PI / 180.0f;
    }

    float radiansToDegrees(const float& radians)
    {
        return radians * 180.0f / PI;
    }
}
