#include "Lerp.h"

#include <iostream>
#include <algorithm>

float Lerpf(const float start, const float end, const float t) {

	float clampedT = std::clamp(t, 0.0f, 1.0f);

	return (1.0f - clampedT) * start + clampedT * end;

}