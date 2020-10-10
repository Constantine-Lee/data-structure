#pragma once
#include "Slime.h"
class FireSlime :
    public Slime
{
public:
    FireSlime(int MaxHP, int HP, int attack, string Name = "Fire Slime") : Slime(MaxHP, HP, attack, "Fire Slime", Name)  {};
};

