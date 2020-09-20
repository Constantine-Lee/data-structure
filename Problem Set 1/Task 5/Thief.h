#pragma once
#include "Unit.h"

class Thief : public Unit
{
private:
    int stolenGold;
public:
    Thief(string owner, UnitCategory unitCat, int iD, int position[2], int maxHP, int currentHP, int maxShield, int currentShield, int maxEnergy, int currentEnergy, GateState gateState) : Unit{ owner, unitCat, iD, position, maxHP, currentHP, maxShield, currentShield, maxEnergy, currentEnergy, gateState }, stolenGold(0) {}
    void stealGold(int gold) { stolenGold += gold; }
};

