#pragma once
#include "vecmath.h"
#include "glm/detail/type_vec2.hpp"

class pocket
{
public:
	glm::vec2 position;
	float drawRadius;
	float colRadius;
	pocket();
	~pocket();

	pocket(glm::vec2 pos);
	pocket(glm::vec2 pos, float drawRad, float colRad);
	void setPosition(glm::vec2 pos);

};

