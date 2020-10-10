#pragma once
#include "Stack.h"
#include "Monster.h"
#include "DoublyLinkedList.h"
#include "DoublyLinkedNode.h"

class Room
{
public:
	int fireElem;
	int waterElem;
	int windElem;
	int universalElem;
	string roomIntro;

	Stack<Monster>* monsters;
	DoublyLinkedList<Room>* rooms;

	Room() {};

	Room(int FireElem, int WaterElem, int WindElem, int UniversalElem, string RoomIntro): 
		fireElem(FireElem), waterElem(WaterElem), windElem(WindElem), universalElem(UniversalElem), roomIntro(RoomIntro) {
			monsters = new Stack<Monster>();
			rooms = new DoublyLinkedList<Room>();
	};

	void addMonster(Monster monster) {
		monsters->push(monster);
	}

	void addRoom(Room room) {
		rooms->insertBack(room);
	}

	void explore() {		
		DoublyLinkedNode<Room>* currRoom = rooms->head;
		while (true) {
			system("cls");
			if (currRoom) {
				cout << "Entered room..." << endl;
				cout << endl << currRoom->data.roomIntro << endl;
				cout << endl << "Enter any key to continue..." << endl;
				string placeHolder;
				cin >> placeHolder;

				if (!monsters->isEmpty()) {
					system("cls");
					cout << "Monster appeared !!!" << endl;
					cout << endl << monsters->peek().monsterDes << endl;
				}

				cout << "Move direction available: " << endl;
				if (currRoom->next) {
					cout << "   W(North)" << endl;
				}
				cout << "   S(South)" << endl;

				string movement;
				cin >> movement;

				if (movement == "W") {
					currRoom = currRoom->next;
				}
				else if (movement == "S") {
					if (currRoom->prev) {
						currRoom = currRoom->prev;
					}
					else {
						break;
					}
				}
			}				
		}				
	}

	~Room() {};
};

