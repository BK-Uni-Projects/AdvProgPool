/*-----------------------------------------------------------
player class
-----------------------------------------------------------*/
#pragma once
#include <string>
#include <iostream>

class player
{
public:
	int ID;
	std::string name;
	int currentScore;
	bool myturn;


	player(int id, std::string n);
	virtual ~player();
};

