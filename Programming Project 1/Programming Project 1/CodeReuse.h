#pragma once
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
#include "GachaMachine.h"

class CodeReuse
{
public:
    void Overview(Party<Slime> slimes) {
        cout << endl << "Party Overview" << endl;
        slimes.listMembers();
        cout << endl << "Inventory Overview" << endl;
        slimes.inventory.display();
    }

    // Setup World
    TreeNode<Room>* WorldSetup() {
        RoomBuilder roomBuilder;

        Room arr[] = { roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom(), roomBuilder.buildRoom() };

        int n = sizeof(arr) / sizeof(arr[0]);
        Tree<Room> tree;
        TreeNode<Room>* root = new TreeNode<Room>();
        root = tree.insertLevelOrder(arr, root, 0, n, NULL);

        return root;
    }

    // Setup Party
    Party<Slime>* PartySetup() {
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

        Item smallPotion("Small Potion", "", 1);
        slimes->inventory.addAtTail(smallPotion);

        Item gachaKey("Gacha Key", "", 1);
        slimes->inventory.addAtTail(gachaKey);

        Overview(*slimes);

        cout << endl << "Let the Adventure Begins !!!" << endl;
        cout << endl << "Press any key to continue..." << endl;
        string placeHolder;
        cin >> placeHolder;

        return slimes;
    }

    // 
    void BattlePhase(TreeNode<Room>* currNode, Party<Slime>* slimes) {
        while (!currNode->data.monsters->isEmpty()) {
            Monster monster = currNode->data.monsters->peek();

            cout << endl << "Monster appeared !!!" << endl;
            ::Sleep(100);
            cout << endl << monster.monsterDes << endl;

            ::Sleep(100);
            cout << endl << "============Battle Start============" << endl;
            ::Sleep(100);
            for (int j = 1; monster.hP >= 0; j++) {
                cout << endl << "Round " << j << endl;
                for (int i = 1; i <= slimes->size(); i++) {
                    ::Sleep(100);
                    Slime& slime = slimes->getMembers(i);
                    int damageReceived = 0;
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
            ::Sleep(100);
            cout << endl << "============Battle End============" << endl;

            ::Sleep(100);
            cout << endl << "Party Overview" << endl;
            slimes->listMembers();

            ::Sleep(100);
            if (currNode->data.monsters->isEmpty()) {
                cout << endl << "                                VICTORY VICTORY VICTORY !!!" << endl;
            }

            ::Sleep(100);
            cout << endl << "Press any key to continue..." << endl;
            string wait;
            cin >> wait;
        }
    }

    //Character Selection
    Slime* CharSelection(Party<Slime> slimes) {
        slimes.listMembers();
        cout << "Input: ";
        int charSelection;
        cin >> charSelection;
        return &(slimes.getMembers(charSelection));
    }

    //Use Item
    void UseItem(Party<Slime>* slimes) {
        cout << endl << "List of Items: " << endl;
        slimes->inventory.display();
        cout << "Input: ";
        int itemUseSelection;
        cin >> itemUseSelection;

        if (slimes->inventory.get(itemUseSelection).name == "Small Potion") {
            cout << endl << "Which character you want to use potion on ?" << endl;
            Slime* healSlime;
            healSlime = CharSelection(*slimes);
            healSlime->hP += 10;
            if (healSlime->hP > healSlime->maxHP) {
                healSlime->hP = healSlime->maxHP;
            };
            slimes->inventory.get(itemUseSelection).amount--;
            cout << endl << "1 Small Potion used." << endl;
            if (slimes->inventory.get(itemUseSelection).amount == 0) {
                slimes->inventory.deleteAtIndex(itemUseSelection);
            }
            cout << endl << healSlime->name << "recovered 10 hp." << endl;
        }
    }

    //Gacha Action
    void GachaAction(Party<Slime>* slimes) {
        bool haveGachaKey = false;
        for (int i = 1; i <= slimes->inventory.size; i++) {
            if (slimes->inventory.get(i).name == "Gacha Key") {
                slimes->inventory.get(i).amount--;
                cout << endl << "1 Gache Key used." << endl;
                if (slimes->inventory.get(i).amount == 0) {
                    slimes->inventory.deleteAtIndex(i);
                }
                haveGachaKey = true;
                break;
            }
        }
        if (haveGachaKey) {
            cout << endl << "Which character you want to use lottery on ?" << endl;
            Slime* lotterySlime;
            lotterySlime = CharSelection(*slimes);

            cout << endl << "Throwing Dice.";
            for (int i = 0; i < 10; i++) {
                ::Sleep(100);
                cout << ".";
            }
            int diceNumber = lotterySlime->throwDice();
            cout << "You got " << diceNumber << " !" << endl;

            GachaMachine gM;
            Lottery lottery = gM.generateLottery();

            for (int i = 1; i <= diceNumber; lottery.nextSlot(), i++) {
                ::Sleep(200);
                string lotteryResult = lottery.getSlot();
                if (lotteryResult == "HP") {
                    lotterySlime->hP++;
                    lotterySlime->maxHP++;
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Increased HP of " << lotterySlime->name << " by 1" << endl;
                }
                else if (lotteryResult == "Attack") {
                    lotterySlime->attack++;
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Increased Attack of " << lotterySlime->name << " by 1" << endl;
                }
                else if (lotteryResult == "Small Potion") {
                    bool found = false;
                    int inventorySize = slimes->inventory.size;

                    for (int i = 1; i <= inventorySize; i++) {
                        if (slimes->inventory.get(i).name == "Small Potion") {
                            slimes->inventory.get(i).amount++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        Item smallPotion("Small Potion", "", 1);
                        slimes->inventory.addAtTail(smallPotion);
                    }
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Acquire 1 Small Potion." << endl;
                }
            }
        }
        else {
            cout << "No Gacha Key found." << endl;
        }
        ::Sleep(100);
        cout << endl << "Press any key to continue..." << endl;
        string wait;
        cin >> wait;
    }

    // Move Action 
    void MoveAction(TreeNode<Room>* currNode) {
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
    }
};

