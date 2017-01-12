/*-----------------------------------------------------------
ruleset class members
-----------------------------------------------------------*/
#include <iostream>
#include "ruleset.h"
#include "table.h"

extern table gTable;

// Default Consructor
ruleset::ruleset(){
	//game rules
	ID = 0;
	name = "default";
	twoshots = true;
	freeball = true;
	placeball = false;

	// game state
	freetable = true;
	currentPlayer = 0;
	switchplay = true;
}

// Main Constructor
/*
ruleset::ruleset(int id, std::string rulename, bool two, bool free, bool place){
	// rules
	ID = id;
	name = rulename;
	twoshots = two;
	freeball = free;
	placeball = place;
	// game state
	freetable = true;
	currentPlayer = 0;
	switchplay = true;
}
*/

void ruleset::reset(void) {
	//game rules
	ID = 0;
	name = "default";
	twoshots = true;
	freeball = true;
	placeball = false;

	// game state
	freetable = true;
	currentPlayer = 0;
	switchplay = true;
}

// Destructor
ruleset::~ruleset() {
}

// Logic Functions
bool ruleset::isTwoShots() {
	if (twoshots==true) {
		return true;
	}
	return false;
}

bool ruleset::isFreeBall() {
	if (freeball == true) {
		return true;
	}
	return false;
}

bool ruleset::isPlaceball() {
	if (placeball == true) {
		return true;
	}
	return false;
}

bool ruleset::isFreeTable() {
	if (freetable == true) {
		return true;
	}
	return false;
}

void ruleset::swapPlayer() {
	// Swap current player
	if(currentPlayer==0) {
		currentPlayer = 1;
	}else {
		currentPlayer = 0;
	}
	std::cout << "Current player is " << gTable.players[currentPlayer]->name << "!" << std::endl;
	// reset states
	gTable.CueballStruck = false;
}

void ruleset::CallFoul() {
	std::cout<< gTable.players[currentPlayer]->name << " caused a foul" << std::endl;	
}

// Main game controlling logic
void ruleset::ProcessGame() {

	if (gTable.CueballStruck) {
		std::cout << "Current scores are :- "
			<< gTable.players[0]->name << "=" << gTable.players[0]->currentScore << " vs "
			<< gTable.players[1]->name << "=" << gTable.players[1]->currentScore
			<< std::endl;

		if (switchplay==true) {
			swapPlayer();
		}
		
		if (gTable.balls[0].inPlay==false) {
			gTable.balls[0].Reset();
		}
		gTable.CueballStruck = false;
	}
	
}

