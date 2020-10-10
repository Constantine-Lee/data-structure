#pragma once
#include "Slime.h"
class WaterSlime :
    public Slime
{
public:
    WaterSlime(int MaxHP, int HP, int attack, string Name = "Water Slime") : Slime(MaxHP, HP, attack, "Water Slime", Name) {};
};

