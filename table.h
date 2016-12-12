/*-----------------------------------------------------------
  table class
  -----------------------------------------------------------*/
#pragma once
#include "ball.h"
#include "cushion.h"
#include "particleset.h"
#include "pocket.h"

/*-----------------------------------------------------------
Macros
-----------------------------------------------------------*/
#define TABLE_X			(0.6f) 
#define TABLE_Z			(1.2f)
#define TABLE_Y			(0.1f)
#define NUM_BALLS		(7)		
#define NUM_CUSHIONS	(5)	
#define NUM_POCKETS		(6)



class table
{
public:
	ball balls[NUM_BALLS];	
	cushion cushions[NUM_CUSHIONS];
	pocket pocket[NUM_POCKETS];
	particleSet parts;

	void SetupCushions(void);
	void SetupPockets(void);
	void Update(int ms);	
	bool AnyBallsMoving(void) const;
};