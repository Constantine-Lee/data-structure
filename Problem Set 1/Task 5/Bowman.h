#pragma once
#include "Unit.h"
class Bowman : public Unit
{
private:
	int arrow;
public:
	Bowman(string owner, UnitCategory unitCat, int iD, int position[2], int maxHP, int currentHP, int maxShield, int currentShield, int maxEnergy, int currentEnergy, GateState gateState): Unit{ owner, unitCat, iD, position, maxHP, currentHP, maxShield, currentShield, maxEnergy, currentEnergy, gateState }, arrow(100) {}
	void shootArrow() { arrow--; }
};

