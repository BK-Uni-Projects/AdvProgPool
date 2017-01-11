/*-----------------------------------------------------------
  table class members
  -----------------------------------------------------------*/
#include "table.h"

void table::SetupCushions(void)
{
	cushions[0].vertices[0](0) = -TABLE_X; 
	cushions[0].vertices[0](1) = -TABLE_Z; 
	cushions[0].vertices[1](0) = -TABLE_X; 
	cushions[0].vertices[1](1) = TABLE_Z; 

	cushions[1].vertices[0](0) = -TABLE_X; 
	cushions[1].vertices[0](1) = TABLE_Z; 
	cushions[1].vertices[1](0) = TABLE_X; 
	cushions[1].vertices[1](1) = TABLE_Z; 

	cushions[2].vertices[0](0) = TABLE_X; 
	cushions[2].vertices[0](1) = TABLE_Z; 
	cushions[2].vertices[1](0) = TABLE_X; 
	cushions[2].vertices[1](1) = -TABLE_Z;

	cushions[3].vertices[0](0) = TABLE_X;
	cushions[3].vertices[0](1) = -TABLE_Z; 
	cushions[3].vertices[1](0) = -TABLE_X; 
	cushions[3].vertices[1](1) = -TABLE_Z; 

	for(int i=0;i<NUM_CUSHIONS;i++)
	{
		cushions[i].MakeCentre();
		cushions[i].MakeNormal();
	}
}

void table::SetupPockets()
{
	pocket[0].position(0) = -TABLE_X;	pocket[0].position(1) = TABLE_Z  ;			// Baulk left
	pocket[3].position(0) = -TABLE_X ;	pocket[3].position(1) = -TABLE_Z  ;			// bottom left

	pocket[1].position(0) = TABLE_X ;	pocket[1].position(1) = TABLE_Z  ;			// baulk right
	pocket[2].position(0) = TABLE_X ;	pocket[2].position(1) = -TABLE_Z  ;			// bottom right
	

	pocket[4].position(0) = TABLE_X ;	pocket[4].position(1) = 0;					// center right
	pocket[5].position(0) = -TABLE_X ;	pocket[5].position(1) = 0;					// center left
}

void table::SetupPlayers() {
	players[0] = new player(0, "Jack");
	players[1] = new player(1, "John");
}

void table::Update(int ms){
	//check for collisions for each ball
	for(int i=0;i<NUM_BALLS;i++){
		for (int j = 0; j<NUM_POCKETS; j++){
			balls[i].DoPocketCollision(pocket[j]);
		}

		for(int j=0;j<NUM_CUSHIONS;j++){
			balls[i].DoPlaneCollision(cushions[j]);
		}

		for(int j=(i+1);j<NUM_BALLS;j++){
			balls[i].DoBallCollision(balls[j]);
		}
	}
	
	//update all balls
	for(int i=0;i<NUM_BALLS;i++) balls[i].Update(ms);

	//update particles
	parts.update(ms);
}

bool table::AnyBallsMoving(void) const{
	//return true if any ball has a non-zero velocity
	for(int i=0;i<NUM_BALLS;i++){
		if(balls[i].velocity(0)!=0.0) return true;
		if(balls[i].velocity(1)!=0.0) return true;
	}

	gGame.ProcessGame();

	return false;
}

table::~table(){
	// delete players
	for (int i=0; i<NUM_PLAYERS; i++) {
		delete players[i];
	}
}
