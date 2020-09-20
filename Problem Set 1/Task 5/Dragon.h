#pragma once
#include "Unit.h"
class Dragon : public Unit
{
private: 
	int mana;
public:
	Dragon(string owner, UnitCategory unitCat, int iD, int position[2], int maxHP, int currentHP, int maxShield, int currentShield, int maxEnergy, int currentEnergy, GateState gateState): Unit{ owner, unitCat, iD, position, maxHP, currentHP, maxShield, currentShield, maxEnergy, currentEnergy, gateState }, mana(100) {}
};

