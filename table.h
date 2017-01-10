/*-----------------------------------------------------------
table class
-----------------------------------------------------------*/
#pragma once
#include <array>

#include "ball.h"
#include "cushion.h"
#include "particleset.h"
#include "pocket.h"
#include "player.h"


/*-----------------------------------------------------------
Macros
-----------------------------------------------------------*/
#define TABLE_X			(0.6f) 
#define TABLE_Z			(1.2f)
#define TABLE_Y			(0.1f)
#define NUM_BALLS		(16)		
#define NUM_CUSHIONS	(4)	
#define NUM_POCKETS		(6)
#define NUM_PLAYERS		(2)

class table
{
public:
	ball balls[NUM_BALLS];	
	cushion cushions[NUM_CUSHIONS];
	pocket pocket[NUM_POCKETS];
	particleSet parts;
	std::array<player*, NUM_PLAYERS> players;

	void SetupCushions(void);
	void SetupPockets(void);
	void SetupPlayers();
	void Update(int ms);	
	bool AnyBallsMoving(void) const;

	~table();
};