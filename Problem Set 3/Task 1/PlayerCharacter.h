#pragma once
#include <iostream>
#include <string>

using namespace std;

class PlayerCharacter
{
public:
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

