/*-----------------------------------------------------------
player class
-----------------------------------------------------------*/
#pragma once
#include <string>

class player
{
public:
	int ID;
	std::string name;
	int currentScore;
	bool fouled;
	int potted;
	int set;


	player(int id, std::string n);
	virtual ~player();
};

