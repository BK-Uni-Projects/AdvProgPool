/*-----------------------------------------------------------
pocket class members
-----------------------------------------------------------*/
#include "pocket.h"
#include "ball.h"

pocket::pocket()
{
	drawRadius = BALL_RADIUS * 2;
	colRadius = BALL_RADIUS;
}

// Destructor
pocket::~pocket()
{
}
