#include "pocket.h"

pocket::pocket()
{
	drawRadius = 1.25f;
	colRadius = .5f;
}


pocket::pocket(glm::vec2 pos)
{
	position = pos;
	drawRadius = 1.25f;
	colRadius = .5f;
}

pocket::pocket(glm::vec2 pos, float drawRad, float colRad)
{
	position = pos;
	drawRadius = drawRad;
	colRadius = colRad;
}

void pocket::setPosition(glm::vec2 pos)
{
	position = pos;
}

// Destructor
pocket::~pocket()
{
}
