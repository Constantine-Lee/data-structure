#pragma once
#include "Slime.h"
class WindSlime :
    public Slime
{
public:
    WindSlime(int MaxHP, int HP, int attack, string Name = "Wind Slime") : Slime(MaxHP, HP, attack, Name) {};
};

