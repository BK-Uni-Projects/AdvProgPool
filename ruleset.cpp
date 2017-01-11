/*-----------------------------------------------------------
ruleset class members
-----------------------------------------------------------*/
#include "ruleset.h"
#include "table.h"
#include <iostream>

extern table gTable;
// Default Consructor
ruleset::ruleset()
{
	ID = 0;
	name = "default";
	twoshots = true;
	freeball = true;
	placeball = false;
	freetable = false;
	currentPlayer = 0;
}

// Main Constructor
ruleset::ruleset(int id, std::string rulename, bool two, bool free, bool place)
{
	ID = id;
	name = rulename;
	twoshots = two;
	freeball = free;
	placeball = place;
	freetable = false;
	currentPlayer = 0;
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
}


int ruleset::checkrules(){
	return 0;
}