#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Iterator.h"

class Lottery
{
public:
	string prize[3] = { "HP", "Attack", "Small Potion" };
	string slots[10] ;
	Iterator fIter = Iterator(slots, 10);

	Lottery() {
		for (int i = 0; i < 10; i++) {
			slots[i] = prize[rand() % 3];
		}		
	}

	const std::string& nextSlot() {
		fIter++;
		if (fIter == fIter.end()) {
			fIter--;
		}
		return *fIter;
	}

	const std::string& prevSlot() {
		if (fIter == fIter.begin()) {}
		else {
			fIter--;
		}
		return *fIter;
	}

	const std::string& getSlot() {
		return *fIter;
	}
};

