#include "player.h"
#include <iostream>


player::player(int id, std::string n)
{
	name = n;
	ID = id;
	currentScore = 0;
	myturn = false;
	potted = 0;

	std::cout	<< "Setup of Player ID = " << id
				<< " is completed, Players name is " << name
				<<std::endl;
			
}

player::~player()
{
}

void player::setTurn(const int t)
{
	if (t == 0) {
		myturn = false;
		std::cout <<name<< " has completed his turn! He potted " <<potted<<" balls!"<< std::endl;
		currentScore += potted;
		potted = 0;
		return;
	} 
	if (t==1){
		myturn = true;
		std::cout << "it is now " <<name<<"s turn!" ;
		return;
	}
	std::cout << "*ERROR* in player::setTurn()" << std::endl;
}