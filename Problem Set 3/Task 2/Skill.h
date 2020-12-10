#pragma once
#include <iostream>
#include <string>

using namespace std;

class Skill
{
public:
	string name;
	int level;

	Skill(string Name, int Level) : name(Name), level(Level) {

	}

	Skill() {

	}

	friend ostream& operator<<(ostream& aOstream, Skill skill) {
		aOstream << skill.name << ": " << skill.level;
		return aOstream;
	}
};

