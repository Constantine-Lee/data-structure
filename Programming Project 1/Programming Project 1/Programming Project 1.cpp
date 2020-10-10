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
#include "Party.h"
#include "windows.h"

using namespace std;

int main()
{
    Party<Slime>* slimes = new Party<Slime>();
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
        cout << endl << fireSlime.name << "," << endl << "    " << " Water Slime and Wind Slime will be joining you for this adventure..." << endl;
        slimes->addMember(fireSlime);
        slimes->addMember(waterSlime);
        slimes->addMember(windSlime);
    }
    else if (charSelection == 2) {
        cout << "Please tell me your name..." << endl;
        cin >> waterSlime.name;
        cout << endl << waterSlime.name << "," << endl << "    " << " Fire Slime and Wind Slime will be joining you for this adventure..." << endl;
        slimes->addMember(waterSlime);
        slimes->addMember(fireSlime);
        slimes->addMember(windSlime);
    }
    else if (charSelection == 3) {
        cout << "Please tell me your name..." << endl;
        cin >> windSlime.name;
        cout << endl << windSlime.name << "," << endl << "    " << "Fire Slime and Water Slime will be joining you for this adventure..." << endl;
        slimes->addMember(windSlime);
        slimes->addMember(waterSlime);
        slimes->addMember(fireSlime);
    }

    Item slimeBanner("Slime Party Banner", "", 1);
    slimes->inventory.addAtTail(slimeBanner);

    Item smallPotion("Small Potiion", "", 1);
    slimes->inventory.addAtTail(smallPotion);

    cout << endl << "Party Overview" << endl;
    slimes->listMembers();
    cout << endl << "Inventory Overview" << endl;
    slimes->inventory.display();
    cout << slimes->inventory.get(1);
    cout << slimes->inventory.get(2);

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
            system("cls");
            cout << "Entered room..." << endl;
            cout << endl << currNode->data.roomIntro << endl;
            Sleep(1000);
            
            while (!currNode->data.monsters->isEmpty()) {     
                Monster monster = currNode->data.monsters->peek();

                cout << endl << "Monster appeared !!!" << endl;                
                Sleep(300);
                cout << endl << monster.monsterDes << endl;
                
                Sleep(1000);
                cout << endl << "============Battle Start============" << endl;
                Sleep(1000);
                for (int j = 1; monster.hP >= 0; j++) {
                    cout << endl << "Round " << j << endl;
                    for (int i = 1; i <= slimes->size(); i++) {
                        ::Sleep(200);
                        Slime& slime = slimes->getMembers(i);
                        int damageReceived;
                        if (slime.type == "Fire Slime") {
                            damageReceived = monster.fireElem;
                        }
                        else if (slime.type == "Water Slime") {
                            damageReceived = monster.waterElem;
                        }
                        else if (slime.type == "Wind Slime") {
                            damageReceived = monster.windElem;
                        }

                        if (slime.status != "Dead") {
                            monster.hP -= slime.attack;
                            cout << slime.name << " dealed " << slime.attack << " damage to Monster, received " << damageReceived << " damage." << endl;
                            slime.hP -= damageReceived;
                        }
                        if (slime.hP <= 0 && slime.status == "Normal") {
                            slime.status = "Dead";
                            cout << slime.name << " is dead." << endl;
                        }
                    }
                }   
                currNode->data.monsters->pop();   
                cout << endl << "============Battle End============" << endl;

                cout << endl << "Party Overview" << endl;
                slimes->listMembers();

                if (currNode->data.monsters->isEmpty()) {
                    cout << endl << "                                VICTORY VICTORY VICTORY !!!" << endl;
                }                            

                cout << endl << "Press any key to continue..." << endl;
                string wait;
                cin >> wait;                
            }            

            system("cls");
            cout << "Resting..." << endl;

            while (true) {
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
                    cout << endl << "List of Items: " << endl;
                    slimes->inventory.display();
                    string itemUseSelection;
                    cin >> itemUseSelection;
                        
                }
                else if (chooice == "3") {

                }
                else if (chooice == "4") {
                    cout << endl << "Move direction available: " << endl;
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
                    break;
                }
            }            
        }                 
    }
}

