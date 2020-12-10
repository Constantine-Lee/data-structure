// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PlayerCharacter.h"

int main()
{
    Skill skill("Intimidation Skill", 3);
    Skill skill2("Persuasion Skill", 5);
    LinkedList<Skill>* skills = new LinkedList<Skill>();

    if (!skills->exist(skill)) {
        skills->append(skill);
    }
    else {
        skills->getValue(skill).level += skill.level;
    }

    if (!skills->exist(skill2)) {
        skills->append(skill2);
    }
    else {
        skills->getValue(skill2).level += skill2.level;
    }

    skills->display();

    if (!skills->exist(skill)) {
        skills->append(skill);
    }
    else {
        skills->getValue(skill).level += skill.level;
    }

    skills->remove(skill2);

    skills->display();

}

