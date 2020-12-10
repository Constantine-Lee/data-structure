#pragma once
#include "Slime.h"
class WaterSlime :
    public Slime
{
public:
    WaterSlime(int MaxHP, int HP, int attack, string Name = "Water Slime") : Slime(MaxHP, HP, attack, "Water Slime", Name) {};

	void specialLuck() {
		hP += 40;
		maxHP += 40;
		cout << "Increased HP by 40" << endl;
	}
};

