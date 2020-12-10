#pragma once
#include "TreeNode.h"
#include "Room.h"

class Dungeon
{
public:
	TreeNode<Room>* startingRoom;

	Dungeon() {};

	void buildDungeon() {
		startingRoom = new TreeNode<Room>();
		Room room1(1, "Warm Room");
		Monster monster1("Fire Spirit");
		room1.addMonster(monster1);
		startingRoom->data = room1;

		TreeNode<Room>* secondRoom = new TreeNode<Room>();
		Room room2(2, "Water Cave");
		Monster monster2("Mermaid");
		room2.addMonster(monster2);
		secondRoom->data = room2;

		TreeNode<Room>* thirdRoom = new TreeNode<Room>();
		Room room3(3, "Tunnel");
		Monster monster3("Rocky rocky !!!");
		room2.addMonster(monster3);
		thirdRoom->data = room3;

		TreeNode<Room>* fourthRoom = new TreeNode<Room>();
		Room room4(4, "Hall");
		Monster monster4("Robot");
		room4.addMonster(monster4);
		fourthRoom->data = room4;

		TreeNode<Room>* fifthRoom = new TreeNode<Room>();
		Room room5(5, "Treasure Room");
		Monster monster5("Treasure Guardian");
		room5.addMonster(monster5);
		fifthRoom->data = room5;

		startingRoom->left = secondRoom;
		startingRoom->right = thirdRoom;
		secondRoom->right = fourthRoom;
		thirdRoom->left = fourthRoom;
		fourthRoom->left = fifthRoom;
	}
};

