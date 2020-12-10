#pragma once
#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Skill.h"

using namespace std;

class PlayerCharacter
{
public:
	LinkedList<Skill> skills;

	bool skillCheck(string skillName, int level) {
		return true;
	}

	void addNewSkill(string skillName, int level) {
		cout << "Added new skill" << endl;
	}

	void removeSkill(string skillName, int level) {
		cout << "Removed skill" << endl;
	}
};
