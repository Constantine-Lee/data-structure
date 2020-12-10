#pragma once
#include "SkillList.h"

class PlayerCharacter
{
public:
	SkillList skills;

	bool skillCheck(string skillName, int level) {
		return skills.skillCheck(skillName, level);
	}

	void addNewSkill(string skillName, int level) {
		skills.addNewSkill(skillName, level);
	}

	void removeSkill(string skillName, int level) {
		skills.removeSkill(skillName, level);
	}
};
