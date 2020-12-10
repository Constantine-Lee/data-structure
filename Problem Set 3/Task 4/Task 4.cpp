// Task 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PlayerCharacter.h"

int main()
{
    PlayerCharacter pC;
    pC.addNewSkill("Intimidation Skill", 3);
    pC.addNewSkill("Persuasion Skill", 4);

    while (true) {
        cout << endl << "Hand over your money" << endl;
        cout << endl << "(1) Here's my money." << endl;
        cout << "(2) You can try, when you get older." << endl;
        cout << "(3) Money? Life? I'm an Engineer." << endl;
        cout << "(4) *Fight*" << endl;

        int selection;
        cin >> selection;

        if (selection == 1) {
            exit(0);
        }
        else if (selection == 2) {
            if (pC.skillCheck("Intimidation Skill", 3)) {
                cout << endl << "Ok..." << endl;
            }
            else {
                cout << endl << "#%*@^$" << endl;
            }
        }
        else if (selection == 3) {
            if (pC.skillCheck("Persuasion Skill", 5)) {
                cout << endl << "Acceptable..." << endl;
            }
            else {
                cout << endl << "???" << endl;
                pC.addNewSkill("Persuasion Skill", 1);
            }
        }
        else if (selection == 4) {
            cout << "Combat !!!" << endl;
            pC.removeSkill("Persuasion Skill", 5);
        }       
    }
}
