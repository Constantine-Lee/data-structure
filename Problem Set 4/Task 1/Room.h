#pragma once
#include "Monster.h"

class Room
{
public:
	int id;
	string roomIntro;
	Monster monsters;

	Room() {};

	Room(int ID, string RoomIntro) : id(ID), roomIntro(RoomIntro) {
	};

	friend ostream& operator<<(ostream& aOstream, Room room) {
		aOstream << room.roomIntro << endl;
		return aOstream;
	}


	void addMonster(Monster monster) {
		monsters = monster;
	}

	~Room() {};
};

