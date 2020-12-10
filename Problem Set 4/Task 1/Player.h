#pragma once
#include "Visitor.h"
#include "TreeNode.h"
#include "Room.h"
#include <iostream>
using namespace std;

#include <stdlib.h>     /* srand, rand */

class Player: public Visitor
{
public:
	string name;

	Player(string Name) : name(Name) {}

	void visitDungeonRoom(TreeNode<Room>* node) {
		cout << endl << "Room Description:" << endl;
		cout << node->data.roomIntro << endl;
		cout << "Monster Description:" << endl;
		cout << node->data.monsters.monsterDes << endl;


		cout << "---Battle Start---" << endl;
		if (rand() % 2) {
			cout << "You win !!!" << endl ;
		}
		else {
			cout << "You lose TT" << endl;
			cout << endl << "Keep Play ?" << endl;
			int keepPlay = 1;
			cout << "(1) Yes" << endl;
			cout << "(2) No" << endl;
			cin >> keepPlay;
			if (keepPlay == 1) {

			}
			else {
				exit(0);
			}
		}
	}
};

