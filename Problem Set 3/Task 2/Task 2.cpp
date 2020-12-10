// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PlayerCharacter.h"
#include "LinkedListNode.h"
#include "Skill.h"

int main()
{
    Skill skill("Intimidation Skill", 3);
    LinkedListNode<Skill>* skillNode = new LinkedListNode<Skill>(skill);
    cout << skillNode->val << endl;

    Skill skill2("Persuasion Skill", 5);
    LinkedListNode<Skill>* skillNode2 = new LinkedListNode<Skill>(skill2);
    cout << skillNode2->val << endl;
}

