#pragma once
#include "Slime.h"
class WindSlime :
    public Slime
{
public:
    WindSlime(int MaxHP, int HP, int attack, string Name = "Wind Slime") : Slime(MaxHP, HP, attack, "Wind Slime", Name) {};

	void specialLuck() {
		attack += 3;
		hP += 20;
		maxHP += 20;
		cout << "Increased Attack by 3 and HP by 20" << endl;
	}
};

