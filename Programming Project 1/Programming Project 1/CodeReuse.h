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
#include <typeinfo> 

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
        //pointer to queue of chests
        Queue<Item>* chests = new Queue<Item>();
        //get the location of buried Aztec Gold
        int aztecGoldLocation = rand() % 18;
        //fill in Item to the queue and Aztec Gold based on location
        for (int i = 0; i < 18; i++) {
            if (i == aztecGoldLocation) {
                Item aztecGold("Aztec Gold", "", 1);
                chests->enqueue(aztecGold);
            }
            else {
                Item gachaKey("Gacha Key", "", 1);
                chests->enqueue(gachaKey);
            }
        }
        RoomBuilder roomBuilder;
        // declare an array of 9 doubly linked list. 
        // There will be 2 rooms in each doubly linked list.
        DoublyLinkedList<Room> rooms[9];
        //build room and insert into doubly linked list
        for (int i = 0; i < 9; i++) {
            Room room_1 = roomBuilder.buildRoom(1, chests);
            rooms[i].append(room_1);
            rooms[i].append(roomBuilder.buildRoom(2, chests));
        }        
        // put doubly linked list into array
        DoublyLinkedList<Room> arr[9] = { rooms[0], rooms[1], rooms[2], rooms[3], rooms[4], rooms[5], rooms[6], rooms[7], rooms[8] };
        int n = sizeof(arr) / sizeof(arr[0]);
        // tree generator
        Tree<DoublyLinkedList<Room>> tree;
        // pointer to the root of tree
        TreeNode<DoublyLinkedList<Room>>* root = new TreeNode<DoublyLinkedList<Room>>();
        // build the tree
        root = tree.insertLevelOrder(arr, root, 0, n, NULL);
        return root;
    }

    // Setup Party
    Party<Slime>* PartySetup() {
        Party<Slime>* slimes = new Party<Slime>();
        FireSlime* fireSlime = new FireSlime(80, 80, 5);
        WaterSlime* waterSlime = new WaterSlime(120, 120, 3);
        WindSlime* windSlime = new WindSlime(100, 100, 4);

        cout << "Who are YOU ?" << endl << endl;
        cout << "(1) Fire Slime..." << endl;
        cout << "(2) Water Slime..." << endl;
        cout << "(3) Wind Slime..." << endl;

        int charSelection;
        cout << "Input: ";
        cin >> charSelection;

        Slime* protagonistSlime = fireSlime;
        if (charSelection == 1) {
            protagonistSlime = fireSlime;            
        }
        else if (charSelection == 2) {
            protagonistSlime = waterSlime;
        }
        else if (charSelection == 3) {
            protagonistSlime = windSlime;
        }
        cout << endl << protagonistSlime->name << " gain ";
        protagonistSlime->specialLuck();

        cout << endl << "Please tell me your name..." << endl;
        if (charSelection == 1) {            
            cin >> fireSlime->name;            
            system("cls");
            cout << fireSlime->name << "," << endl << "    " << " Water Slime and Wind Slime will be joining you for this adventure..." << endl;
            slimes->addMember(*fireSlime);
            slimes->addMember(*waterSlime);
            slimes->addMember(*windSlime);
        }
        else if (charSelection == 2) {
            cin >> waterSlime->name;            
            system("cls");
            cout << waterSlime->name << "," << endl << "    " << " Fire Slime and Wind Slime will be joining you for this adventure..." << endl;
            slimes->addMember(*waterSlime);
            slimes->addMember(*fireSlime);
            slimes->addMember(*windSlime);
        }
        else if (charSelection == 3) {
            cin >> windSlime->name;
            system("cls");
            cout << windSlime->name << "," << endl << "    " << "Fire Slime and Water Slime will be joining you for this adventure..." << endl;
            slimes->addMember(*windSlime);
            slimes->addMember(*waterSlime);
            slimes->addMember(*fireSlime);
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

    // battle phase
    boolean BattlePhase(Room* currRoom, Party<Slime>* slimes) {
        boolean fight = false;
        // if stack of monster is not empty
        while (!currRoom->monsters.isEmpty()) {
            fight = true;
            // get the top element as monster to fight
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
                        slime.setHP(slime.getHP() - damageReceived);
                    }                                       
                }
                if (slimes->getMembers(0).status == "Dead" && slimes->getMembers(1).status == "Dead" && slimes->getMembers(2).status == "Dead") {
                    cout << endl << "All dead... all dead... all the slimes are dead..." << endl;
                    cout << endl << "                                           GAME OVER" << endl;
                    exit(0);
                }
            }
            // battle finished, remove monster from stack by pop operation
            currRoom->monsters.pop();
            ::Sleep(100);
            cout << endl << "============Battle End============" << endl;

            ::Sleep(100);
            cout << endl << "Party Overview" << endl;
            slimes->listMembers();

            // if the popped monster reincarnate, then push a new reincarnated monster into the stack, and it will be the next monster to fight
            if (monster.reincarnate) {
                ::Sleep(100);
                cout << endl << "Monster reincarnate... Prepare for another battle..." << endl;
                MonsterBuilder monsterBuilder;
                currRoom->addMonster(monsterBuilder.buildMonster());
            }                     
       
           ::Sleep(100);
           // victory if there are no monsters left
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
            healSlime->setHP(healSlime->getHP() + 10);
            slimes->inventory.getValue(itemUseSelection - 1).amount--;
            cout << endl << "1 Small Potion used." << endl;
            if (slimes->inventory.getValue(itemUseSelection - 1).amount == 0) {
                slimes->inventory.deleteAtIndex(itemUseSelection - 1);
            }
            cout << endl << healSlime->name << " recovered 10 hp." << endl;
        }
        else if (slimes->inventory.getValue(itemUseSelection - 1).name == "Gacha Key") {
            GachaAction(slimes);
        }
    }

    //Gacha Action
    void GachaAction(Party<Slime>* slimes) {
        bool haveGachaKey = false;
        // check if there is a Gacha Key available
        for (int i = 0; i < slimes->inventory.size; i++) {
            string test = slimes->inventory.getValue(i).name;
            if (slimes->inventory.getValue(i).name == "Gacha Key") {
                slimes->inventory.getValue(i).amount--;
                cout << endl << "1 Gacha Key used." << endl;
                if (slimes->inventory.getValue(i).amount == 0) {
                    slimes->inventory.deleteAtIndex(i);
                }
                haveGachaKey = true;
                break;
            }
        }
        // if Gache Key available
        if (haveGachaKey) {
            cout << endl << "Which character you want to use lottery on ?" << endl;
            Slime* lotterySlime;
            lotterySlime = CharSelection(slimes);

            // throw a dice
            cout << endl << "Throwing Dice.";
            for (int i = 0; i < 10; i++) {
                ::Sleep(100);
                cout << ".";
            }
            int diceNumber = lotterySlime->throwDice();
            cout << "You got " << diceNumber << " !" << endl;

            GachaMachine gM;
            //get lottery
            Lottery lottery = gM.generateLottery();

            // open number of slots based on dice number
            for (int i = 1; i <= diceNumber; lottery.nextSlot(), i++) {
                ::Sleep(200);
                string lotteryResult = lottery.getSlot();
                // increase HP if slot prize is HP
                if (lotteryResult == "HP") {
                    int amount = 1;
                    lotterySlime->setHP(lotterySlime->getHP() + amount);
                    lotterySlime->maxHP++;
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Increased HP of " << lotterySlime->name << " by " << amount << endl;
                }
                // increase Attack if slot prize is Attack
                else if (lotteryResult == "Attack") {
                    int amount = 1;
                    lotterySlime->attack++;
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Increased Attack of " << lotterySlime->name << " by " << amount << endl;
                }
                // put small potion into inventory
                else if (lotteryResult == "Small Potion") {
                    bool found = false;
                    int inventorySize = slimes->inventory.size;

                    for (int i = 0; i < inventorySize; i++) {
                        if (slimes->inventory.getValue(i).name == lotteryResult) {
                            slimes->inventory.getValue(i).amount++;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        Item smallPotion(lotteryResult, "", 1);
                        slimes->inventory.append(smallPotion);
                    }
                    cout << "(" << i << ") " << lottery.getSlot() << ": " << "Obtain 1 " << lotteryResult << "." << endl;
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
        // if there is next room, print front
        if ((*currRoom)->next) {
            cout << "   W(Front)" << endl;
        }
        // if there is left child node and the current room is the first room in the current node, print left
        if ((*currNode)->left && (*currRoom)->data.id == 1) {
            cout << "   A(Left)" << endl;
        }
        // if there is parent node and the current room is the first room in the current node, print back
        if (!((*currNode)->parent == NULL && (*currRoom)->data.id == 1)) {
            cout << "   S(Back)" << endl;
        }
        // if there is right child node and the current room is the first room in the current node, print right
        if ((*currNode)->right && (*currRoom)->data.id == 1) {
            cout << "   D(Right)" << endl;
        }

        string movement;
        cout << "Input: ";
        cin >> movement;

        // if player decided to move back
        if (movement == "S") {
            // if current room is the first room in current node and there is parent node for current node, then move to parent node and set current room as first room in parent node.
            if ((*currRoom)->data.id == 1 && (*currNode)->parent) {
                *currNode = (*currNode)->parent;
                *currRoom = (*currNode)->data.getNode(0);
            }
            else {
                // otherwise move to previous room in doubly linked list
                *currRoom = (*currRoom)->prev;
            }            
        }
        // if there is next room for current room in doubly linked list
        else if (movement == "W") {
            *currRoom = (*currRoom)->next;
        }
        // the player select move right
        else if (movement == "D") {
            // if there is right child node and the current room is first room in current node, then move to right child node and set current room as first room in parent node.
            if ((*currNode)->right && (*currRoom)->data.id == 1) {
                *currNode = (*currNode)->right;
                *currRoom = (*currNode)->data.getNode(0);
            }
        }
        // the player select move left
        else if (movement == "A") {
            // if there is left child node and the current room is first room in current node, then move to left child node and set current room as first room in parent node.
            if ((*currNode)->left && (*currRoom)->data.id == 1) {
                *currNode = (*currNode)->left;
                *currRoom = (*currNode)->data.getNode(0);
            }
        }
    }
};

