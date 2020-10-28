#pragma once
#include "Stack.h"
#include "Monster.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"
#include "LinkedList.h"
#include "Item.h"
#include "Queue.h"

class Room
{
public:
	int id;
	string roomIntro;
	Stack<Monster> monsters;	
	boolean chest = true;
	Queue<Item>* chests;

	Room() {};

	Room(int ID, string RoomIntro, Queue<Item>* Chests): id(ID), roomIntro(RoomIntro), chests(Chests) {
	};

	friend ostream& operator<<(ostream& aOstream, Room room) {
		aOstream << room.roomIntro << endl;
		return aOstream;
	}

	Item openChest() {
		chest = false;
		return chests->dequeue();
	}

	void addMonster(Monster monster) {
		monsters.push(monster);
	}

	~Room() {};
};

