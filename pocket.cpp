#include "pocket.h"
#include "ball.h"

pocket::pocket()
{
	drawRadius = BALL_RADIUS * 2;
	colRadius = BALL_RADIUS;
}


pocket::pocket(vec2 pos)
{
	position = pos;
	drawRadius = BALL_RADIUS*2;
	colRadius = BALL_RADIUS;
}

pocket::pocket(vec2 pos, float drawRad, float colRad)
{
	position = pos;
	drawRadius = drawRad;
	colRadius = colRad;
}

void pocket::setPosition(vec2 pos)
{
	position = pos;
}

// Destructor
pocket::~pocket()
{
}
