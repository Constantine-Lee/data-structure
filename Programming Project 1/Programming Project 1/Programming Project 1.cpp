// Programming Project 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "Room.h"
#include "RoomBuilder.h"
#include "FireSlime.h"
#include "WindSlime.h"
#include "WaterSlime.h"
#include "LinkedList.h"


using namespace std;

int main()
{
    LinkedList<Slime>* slimes = new LinkedList<Slime>();
    FireSlime fireSlime(80, 80, 5);
    WaterSlime waterSlime(120, 120, 3);
    WindSlime windSlime(100, 100, 4);

    cout << "Who are YOU ?" << endl << endl;
    cout << "Enter 1 if you are a Fire Slime..." << endl;
    cout << "Enter 2 if you are a Water Slime..." << endl;
    cout << "Enter 3 if you are a Wind Slime..." << endl;

    int charSelection;
    cin >> charSelection;

    system("cls");
    if (charSelection == 1) {
        cout << "Please tell me your name..." << endl;
        cin >> fireSlime.name;
        system("cls");
        cout << fireSlime.name << "," << endl << "    " << " Water Slime and Wind Slime will be joining you for this adventure..." << endl;
        slimes->addAtTail(fireSlime);
        slimes->addAtTail(waterSlime);
        slimes->addAtTail(windSlime);
    }
    else if (charSelection == 2) {
        cout << "Please tell me your name..." << endl;
        cin >> waterSlime.name;
        system("cls");
        cout << waterSlime.name << "," << endl << "    " << " Fire Slime and Wind Slime will be joining you for this adventure..." << endl;
        slimes->addAtTail(waterSlime);
        slimes->addAtTail(fireSlime);
        slimes->addAtTail(windSlime);
    }
    else if (charSelection == 3) {
        cout << "Please tell me your name..." << endl;
        cin >> windSlime.name;
        system("cls");
        cout << windSlime.name << "," << endl << "    " << "Fire Slime and Water Slime will be joining you for this adventure..." << endl;
        slimes->addAtTail(windSlime);
        slimes->addAtTail(waterSlime);
        slimes->addAtTail(fireSlime);
    }

    Item slimeBanner("Slime Party Banner", "", 1);
    Slime::inventory.addAtTail(slimeBanner);

    Item smallPotion("Small Potiion", "", 1);
    Slime::inventory.addAtTail(smallPotion);

    cout << endl << "Party Overview" << endl;
    slimes->display();
    cout << endl << "Inventory Overview" << endl;
    Slime::inventory.display();
    cout << Slime::inventory.get(1);
    cout << Slime::inventory.get(2);

    cout << endl << "Let the Adventure Begins !!!" << endl;
    cout << endl << "Press any key to continue..." << endl;
    string placeHolder;
    cin >> placeHolder;

    RoomBuilder roomBuilder;

    Room arr[] = { roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom() };
    int n = sizeof(arr) / sizeof(arr[0]);
    Tree<Room> tree;
    TreeNode<Room>* root = new TreeNode<Room>();
    root = tree.insertLevelOrder(arr, root, 0, n, NULL);
    
    TreeNode<Room>* currNode = root;    

    while (true) {
        if (currNode) {
            cout << "Entered room..." << endl;
            cout << endl << currNode->data.roomIntro << endl;
            cout << endl << "Enter any key to continue..." << endl;

            string placeHolder;
            cin >> placeHolder;

            if (!currNode->data.monsters->isEmpty()) {
                system("cls");
                cout << "Monster appeared !!!" << endl;
                cout << endl << currNode->data.monsters->peek().monsterDes << endl;
            }

            cout << "Move direction available: " << endl;
            if (currNode->data.rooms->head != nullptr) {
                cout << "   W(North)" << endl;
            }
            if (currNode->left) {
                cout << "   A(West)" << endl;
            }
            if (currNode->parent) {
                cout << "   S(South)" << endl;
            }
            if (currNode->right) {
                cout << "   D(East)" << endl;
            }

            string movement;
            cin >> movement;

            if (movement == "S") {
                currNode = currNode->parent;
            }
            else if (movement == "W") {
                currNode->data.explore();
            }
            else if (movement == "D") {
                currNode = currNode->right;

            }
            else if (movement == "A") {
                if (currNode->left) {
                    currNode = currNode->left;
                }
            }
        }                 
    }
}

