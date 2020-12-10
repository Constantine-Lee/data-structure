// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dungeon.h"
#include "Player.h"
#include <time.h>

int main()
{
    
    while(true) {
        system("cls");
        cout << "A New Game." << endl;
        /* initialize random seed: */
        srand(time(0));

        // player and dungeon
        Player p("Constantine");
        cout << "Player name: " << p.name << endl;

        Dungeon d;
        d.buildDungeon();

        // get starting room from Dungeon
        TreeNode<Room>* startingRoom = d.startingRoom;

        // visit the first room
        startingRoom->acceptVisitor(&p);

        // ask whether to move to left room or right room
        cout << endl << "Move to ?" << endl;
        cout << "(1)Left" << endl;
        cout << "(2)Right" << endl;

        // get input 
        int selection;
        cin >> selection;

        // go to left room if input is 1
        if (selection == 1) {
            startingRoom->left->acceptVisitor(&p);
        }
        else {
            startingRoom->right->acceptVisitor(&p);
        }

        // ask whether to move forward or not
        cout << endl << "Move to ?" << endl;
        cout << "(1)Left" << endl;

        // get input
        cin >> selection;

        // proceeed
        if (selection == 1) {
            startingRoom->left->right->acceptVisitor(&p);
        }

        // ask again
        cout << endl << "Move to ?" << endl;
        cout << "(1)Left" << endl;

        // get input
        cin >> selection;

        // proceed
        if (selection == 1) {
            startingRoom->left->right->left->acceptVisitor(&p);
        }

        // success in finding the treasure
        cout << "You found the treasure !!!" << endl;

        int wait;
        cin >> wait;
    }
    
}

    