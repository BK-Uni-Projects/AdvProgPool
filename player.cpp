#include "player.h"



player::player(int id, std::string n)
{
	name = n;
	ID = id;
	currentScore = 0;
	myturn = false;

	std::cout	<< "Setup of Player ID = " << id
				<< " is completed, Players name is " << name
				<<std::endl;
			
}


player::~player()
{
}
