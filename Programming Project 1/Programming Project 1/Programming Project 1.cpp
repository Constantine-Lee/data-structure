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
    TreeNode<Room>* currNode = codeReuse.WorldSetup();
    Party<Slime>* slimes = codeReuse.PartySetup();

    while (true) {
        if (currNode) {  
            system("cls");
            // Entered room
            cout << "Entered room..." << endl;
            cout << endl << currNode->data.roomIntro << endl; 
            ::Sleep(100);           
      
            // Battle if there is any monster
            codeReuse.BattlePhase(currNode, slimes);

            while (true) {
                system("cls");
                cout << "Resting..." << endl;
                codeReuse.Overview(*slimes);
                cout << endl << "Action Available:" << endl;
                cout << "(1) Check Surrounding" << endl;
                cout << "(2) Use Item" << endl;
                cout << "(3) Gacha!!!" << endl;
                cout << "(4) Move..." << endl;

                string chooice;
                cin >> chooice;

                if (chooice == "1") {

                }
                else if (chooice == "2") {
                    codeReuse.UseItem(slimes);
                }
                else if (chooice == "3") {
                    codeReuse.GachaAction(slimes);
                }
                else if (chooice == "4") {
                    codeReuse.MoveAction(currNode);
                    break;
                }
            }            
        }                 
    }
}

