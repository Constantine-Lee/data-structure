#pragma once
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Iterator.h"
#include "Lottery.h"

using namespace std;

class GachaMachine
{
public:
	GachaMachine() {
		
	}

	Lottery generateLottery() {
		return Lottery();
	}
};

