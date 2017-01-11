/*-----------------------------------------------------------
ruleset class members
-----------------------------------------------------------*/
#include "ruleset.h"

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




int ruleset::checkrules(){
	return 0;
}