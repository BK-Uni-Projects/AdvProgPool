/*-----------------------------------------------------------
Ruleset class
-----------------------------------------------------------*/
#pragma once

class ruleset
{
public:
	int ID;
	std::string name;
	bool twoshots;
	bool freeball;
	bool placeball;
	bool freetable;


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
	// game management functions
	void ProcessGame();

	void swapPlayer();	
	void CallFoul(void);
};

