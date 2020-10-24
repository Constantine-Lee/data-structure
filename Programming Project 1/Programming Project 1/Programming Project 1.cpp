// Programming Project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CodeReuse.h"

using namespace std;

// Starting Point
int main()
{
    /* initialize random seed: */
    srand(time(0));
    CodeReuse codeReuse;
    TreeNode<DoublyLinkedList<Room>>* currentNode = codeReuse.WorldSetup();
    TreeNode<DoublyLinkedList<Room>>** currentNodePtr = &currentNode;
    DoublyLinkedNode<Room>* currentRoom = (*currentNodePtr)->data.getNode(0);
    DoublyLinkedNode<Room>** currentRoomPtr = &currentRoom;
    Party<Slime>* slimes = codeReuse.PartySetup();

    while (true) {
        if (currentNodePtr) {  
            system("cls");
            // Entered room
            cout << "Entered room..." << endl;
            cout << endl << (*currentRoomPtr)->data.roomIntro << endl; 
            ::Sleep(100);           
      
            // Battle if there is any monster
            boolean fight = codeReuse.BattlePhase(&((*currentRoomPtr)->data), slimes);

            while (true) {               
                cout << endl << "Resting";
                for (int i = 0; i < 10; i++) {
                    ::Sleep(100);
                    cout << ".";
                }
                cout << endl;
                codeReuse.Overview(*slimes);
                cout << endl << "Action Available:" << endl;
                cout << "(1) Check Surrounding" << endl;
                cout << "(2) Use Item" << endl;
                cout << "(3) Gacha!!!" << endl;
                cout << "(4) Move..." << endl;

                string chooice;
                cout << "Input: ";
                cin >> chooice;

                if (chooice == "1") {
                    codeReuse.checkSurrounding();
                }
                else if (chooice == "2") {
                    codeReuse.UseItem(slimes);
                }
                else if (chooice == "3") {
                    codeReuse.GachaAction(slimes);
                }
                else if (chooice == "4") {
                    codeReuse.MoveAction(currentNodePtr, currentRoomPtr);
                    break;
                }
            }            
        }                 
    }
}

