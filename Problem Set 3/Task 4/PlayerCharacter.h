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
		Skill skill(skillName, level);
		if (skills.exist(skill)) {
			if (skills.getValue(skill).level >= level) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	void addNewSkill(string skillName, int level) {
		Skill skill(skillName, level);
		if (skills.exist(skill)) {
			skills.getValue(skill).level += skill.level;
			cout << "Upgrade skill level" << endl;
		}
		else {
			skills.append(skill);
			cout << "Added new skill: " << skill.name << endl;
		}		
	}

	void removeSkill(string skillName, int level) {
		Skill skill(skillName, level);
		if (skills.exist(skill)) {
			skills.remove(skill);
			cout << "Removed skill" << endl;
		}
	}
};
