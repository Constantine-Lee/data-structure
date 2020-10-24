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
    TreeNode<DoublyLinkedList<Room>>* WorldSetup() {
        RoomBuilder roomBuilder;
        DoublyLinkedList<Room> rooms[9];
        for (int i = 0; i < 9; i++) {
            rooms[i].insertBack(roomBuilder.buildRoom(1));
            rooms[i].insertBack(roomBuilder.buildRoom(2));
        }        

        DoublyLinkedList<Room> arr[9] = { rooms[0], rooms[1], rooms[2], rooms[3], rooms[4], rooms[5], rooms[6], rooms[7], rooms[8] };

        int n = sizeof(arr) / sizeof(arr[0]);
        Tree<DoublyLinkedList<Room>> tree;
        TreeNode<DoublyLinkedList<Room>>* root = new TreeNode<DoublyLinkedList<Room>>();
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
        cout << "(1) Fire Slime..." << endl;
        cout << "(2) Water Slime..." << endl;
        cout << "(3) Wind Slime..." << endl;

        int charSelection;
        cout << "Input: ";
        cin >> charSelection;


        cout << endl << "Please tell me your name..." << endl;
        if (charSelection == 1) {            
            cin >> fireSlime.name;
            system("cls");
            cout << fireSlime.name << "," << endl << "    " << " Water Slime and Wind Slime will be joining you for this adventure..." << endl;
            slimes->addMember(fireSlime);
            slimes->addMember(waterSlime);
            slimes->addMember(windSlime);
        }
        else if (charSelection == 2) {
            cin >> waterSlime.name;
            system("cls");
            cout << waterSlime.name << "," << endl << "    " << " Fire Slime and Wind Slime will be joining you for this adventure..." << endl;
            slimes->addMember(waterSlime);
            slimes->addMember(fireSlime);
            slimes->addMember(windSlime);
        }
        else if (charSelection == 3) {
            cin >> windSlime.name;
            system("cls");
            cout << windSlime.name << "," << endl << "    " << "Fire Slime and Water Slime will be joining you for this adventure..." << endl;
            slimes->addMember(windSlime);
            slimes->addMember(waterSlime);
            slimes->addMember(fireSlime);
        }

        Item slimeBanner("Slime Party Banner", "", 1);
        slimes->inventory.append(slimeBanner);

        Item smallPotion("Small Potion", "", 1);
        slimes->inventory.append(smallPotion);

        Item gachaKey("Gacha Key", "", 1);
        slimes->inventory.append(gachaKey);

        Overview(*slimes);

        cout << endl << "Let the Adventure Begins !!!" << endl;
        cout << endl << "Press any key to continue..." << endl;
        string placeHolder;
        cin >> placeHolder;

        return slimes;
    }

    // 
    boolean BattlePhase(Room* currRoom, Party<Slime>* slimes) {
        boolean fight = false;
        while (!currRoom->monsters.isEmpty()) {
            fight = true;
            Monster monster = currRoom->monsters.peek();

            cout << endl << "Monster appeared !!!" << endl;
            ::Sleep(100);
            cout << endl << monster.monsterDes << endl;

            ::Sleep(100);
            cout << endl << "============Battle Start============" << endl;
            ::Sleep(100);
            for (int j = 1; monster.hP >= 0; j++) {
                cout << endl << "Round " << j << endl;
                for (int i = 0; i < slimes->size(); i++) {
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
            currRoom->monsters.pop();
            ::Sleep(100);
            cout << endl << "============Battle End============" << endl;

            ::Sleep(100);
            cout << endl << "Party Overview" << endl;
            slimes->listMembers();

            ::Sleep(100);
            if (currRoom->monsters.isEmpty()) {
                cout << endl << "                                ";
                for (int i = 0; i < 3; i++) {
                    ::Sleep(100);
                    cout << " VICTORY";
                }
                cout << " !!!" << endl;
            }
            else {
                cout << endl << "Press any key to continue..." << endl;
                string wait;
                cin >> wait;
            }
            ::Sleep(100);            
        }
        return fight;
    }

    //Character Selection
    Slime* CharSelection(Party<Slime>* slimes) {
        slimes->listMembers();
        cout << "Input: ";
        int charSelection;
        cin >> charSelection;
        return &(slimes->getMembers(charSelection - 1));
    }

    void checkSurrounding() {

    }

    //Use Item
    void UseItem(Party<Slime>* slimes) {
        cout << endl << "List of Items: " << endl;
        slimes->inventory.display();
        cout << "Input: ";
        int itemUseSelection;
        cin >> itemUseSelection;

        if (slimes->inventory.getValue(itemUseSelection - 1).name == "Small Potion") {
            cout << endl << "Which character you want to use potion on ?" << endl;
            Slime* healSlime;
            healSlime = CharSelection(slimes);
            healSlime->hP += 10;
            if (healSlime->hP > healSlime->maxHP) {
                healSlime->hP = healSlime->maxHP;
            };
            slimes->inventory.getValue(itemUseSelection - 1).amount--;
            cout << endl << "1 Small Potion used." << endl;
            if (slimes->inventory.getValue(itemUseSelection - 1).amount == 0) {
                slimes->inventory.deleteAtIndex(itemUseSelection - 1);
            }
            cout << endl << healSlime->name << " recovered 10 hp." << endl;
        }
    }

    //Gacha Action
    void GachaAction(Party<Slime>* slimes) {
        bool haveGachaKey = false;
        for (int i = 0; i < slimes->inventory.size; i++) {
            string test = slimes->inventory.getValue(i).name;
            if (slimes->inventory.getValue(i).name == "Gacha Key") {
                slimes->inventory.getValue(i).amount--;
                cout << endl << "1 Gache Key used." << endl;
                if (slimes->inventory.getValue(i).amount == 0) {
                    slimes->inventory.deleteAtIndex(i - 1);
                }
                haveGachaKey = true;
                break;
            }
        }
        if (haveGachaKey) {
            cout << endl << "Which character you want to use lottery on ?" << endl;
            Slime* lotterySlime;
            lotterySlime = CharSelection(slimes);

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

                    for (int i = 0; i < inventorySize; i++) {
                        if (slimes->inventory.getValue(i).name == "Small Potion") {
                            slimes->inventory.getValue(i).amount++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        Item smallPotion("Small Potion", "", 1);
                        slimes->inventory.append(smallPotion);
                    }
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Acquire 1 Small Potion." << endl;
                }
            }
        }
        else {
            cout << "No Gacha Key found." << endl;
        }
        ::Sleep(100);
    }

    // Move Action 
    void MoveAction(TreeNode<DoublyLinkedList<Room>>** currNode, DoublyLinkedNode<Room>** currRoom) {
        cout << endl << "Move direction available: " << endl;
        if ((*currRoom)->next) {
            cout << "   W(Front)" << endl;
        }
        if ((*currNode)->left && (*currRoom)->data.id == 1) {
            cout << "   A(Left)" << endl;
        }
        if (!((*currNode)->parent == NULL && (*currRoom)->data.id == 1)) {
            cout << "   S(Back)" << endl;
        }
        if ((*currNode)->right && (*currRoom)->data.id == 1) {
            cout << "   D(Right)" << endl;
        }

        string movement;
        cout << "Input: ";
        cin >> movement;

        if (movement == "S") {
            if ((*currRoom)->data.id == 1 && (*currNode)->parent) {
                *currNode = (*currNode)->parent;
                *currRoom = (*currNode)->data.getNode(0);
            }
            else {
                *currRoom = (*currRoom)->prev;
            }            
        }
        else if (movement == "W") {
            *currRoom = (*currRoom)->next;
        }
        else if (movement == "D") {
            if ((*currNode)->right && (*currRoom)->data.id == 1) {
                *currNode = (*currNode)->right;
                *currRoom = (*currNode)->data.getNode(0);
            }
        }
        else if (movement == "A") {
            if ((*currNode)->left && (*currRoom)->data.id == 1) {
                *currNode = (*currNode)->left;
                *currRoom = (*currNode)->data.getNode(0);
            }
        }
    }
};

