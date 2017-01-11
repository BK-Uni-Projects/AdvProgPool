#include "player.h"
#include <iostream>


player::player(int id, std::string n)
{
	name = n;
	ID = id;
	currentScore = 0;
	myturn = false;
	potted = 0;
	set = 0;

	std::cout	<< "Setup of Player ID = " << id
				<< " is completed, Players name is " << name
				<<std::endl;
			
}

player::~player()
{
}

