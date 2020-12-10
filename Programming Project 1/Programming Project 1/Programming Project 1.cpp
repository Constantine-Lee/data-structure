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
    // get pointer to current node
    TreeNode<DoublyLinkedList<Room>>* currentNode = codeReuse.WorldSetup();
    // a pointer to pointer and initialise it with the pointer to current node
    TreeNode<DoublyLinkedList<Room>>** currentNodePtr = &currentNode;
    // get pointer to the first room in current node
    DoublyLinkedNode<Room>* currentRoom = (*currentNodePtr)->data.getNode(0);
    // a pointer to pointer and initialise it with the pointer to current room
    DoublyLinkedNode<Room>** currentRoomPtr = &currentRoom;
    Party<Slime>* slimes = codeReuse.PartySetup();

    while (true) {
        if (currentNodePtr) {  
            system("cls");
            // Entered room
            cout << "Entered room..." << endl;
            // print current room description
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

                // if check surrounding
                if (chooice == "1") {
                    if ((*currentRoomPtr)->data.chest && !((*currentRoomPtr)->data.chests->isEmpty())) {
                        Item chestItem = (*currentRoomPtr)->data.openChest();
                        if (chestItem.name == "Aztec Gold") {
                            cout << endl << "You had found Aztec Gold... You will be cursed for a thousand years..." << endl;
                            cout << endl << "                                GAME OVER";
                            exit(0);
                        }

                        bool found = false;
                        for (int i = 0; i < slimes->inventory.size; i++) {
                            if (slimes->inventory.getValue(i).name == chestItem.name) {
                                slimes->inventory.getValue(i).amount++;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            Item smallPotion(chestItem.name, "", 1);
                            slimes->inventory.append(smallPotion);
                        }
                        cout << endl << "Obtain 1 " << chestItem.name << "." << endl;
                    }
                    else {
                        cout << endl << "Nothing found..." << endl;
                    }
                }
                else if (chooice == "2") {
                    codeReuse.UseItem(slimes);
                }
                else if (chooice == "3") {
                    codeReuse.GachaAction(slimes);
                }
                // move action
                else if (chooice == "4") {
                    codeReuse.MoveAction(currentNodePtr, currentRoomPtr);
                    break;
                }
            }            
        }                 
    }
}

