#pragma once
#include "Stack.h"
#include "Monster.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"
#include "LinkedList.h"
#include "Item.h"

class Room
{
public:
	int id;
	string roomIntro;
	Stack<Monster> monsters;	
	LinkedList<Item> inventory;

	Room() {};

	Room(int ID, string RoomIntro): id(ID), roomIntro(RoomIntro) {
	};

	friend ostream& operator<<(ostream& aOstream, Room room) {
		aOstream << room.roomIntro << endl;
		return aOstream;
	}

	void addMonster(Monster monster) {
		monsters.push(monster);
	}

	void explore() {					
	}

	~Room() {};
};

