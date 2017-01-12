#include "player.h"
#include <iostream>

player::player(int id, std::string n){
	name = n;
	ID = id;
	currentScore = 0;
	set = 0;		
}

player::~player()
{
}

