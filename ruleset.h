/*-----------------------------------------------------------
Ruleset class
-----------------------------------------------------------*/
#pragma once

class ruleset
{
public:
	// Game rules
	int ID;
	std::string name;
	bool twoshots;
	bool freeball;
	bool placeball;
	
	// Game state
	bool freetable;			// Initial table state
	int currentPlayer;		// Player at table
	bool switchplay;		// change players

	// Constructors
	ruleset();
	//ruleset(int ID, std::string rulename, bool two, bool free, bool place);
	void reset();
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

