/*-----------------------------------------------------------
Ruleset class
-----------------------------------------------------------*/
#pragma once
#include <string>

class ruleset
{
private:
	int ID;
	std::string name;
	bool twoshots;
	bool freeball;
	bool placeball;
	bool freetable;

public:
	int currentPlayer;
	// Constructors
	ruleset();
	ruleset(int ID, std::string rulename, bool two, bool free, bool place);

	// Destructor
	~ruleset();

	// Logic Functions
	bool isTwoShots();
	bool isFreeBall();
	bool isPlaceball();
	bool isFreeTable();
	void swapPlayer();

	int checkrules();
};

