/*-----------------------------------------------------------
pocket class
-----------------------------------------------------------*/
#pragma once
#include "vecmath.h"

class pocket
{
public:
	vec2 position;
	float drawRadius;
	float colRadius;
	pocket();
	~pocket();

	pocket(vec2 pos);
	pocket(vec2 pos, float drawRad, float colRad);
	void setPosition(vec2 pos);

};

