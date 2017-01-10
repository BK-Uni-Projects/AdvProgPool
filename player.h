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
	bool myturn;
	int potted;


	player(int id, std::string n);
	virtual ~player();
	void setTurn(const int t);
};

