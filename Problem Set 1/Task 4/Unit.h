#pragma once
// Include the string library
#include <iostream>
#include <string>
using std::string;

enum UnitCategory { LAND, AIR, WATER, BUILDING, TERRAIN };
enum GateState { Passive, Active, Destroyed };

class Unit
{
private:
	string fOwner;
	UnitCategory fUnitCat;
	int fID;
	int fPosition[2];
	int fMaxHP;
	int fCurrentHP;
	int fMaxShield;
	int fCurrentShield;
	int fMaxEnergy;
	int fCurrentEnergy;
	GateState fGateState;
	string fMessage;

public:
	Unit() {};
	Unit(string owner, UnitCategory unitCat, int iD, int position[2], int maxHP, int currentHP, int maxShield, int currentShield, int maxEnergy, int currentEnergy, GateState gateState) : fOwner(owner), fUnitCat(unitCat), fID(iD), fMaxHP(maxHP), fCurrentHP(currentHP), fMaxShield(maxShield), fCurrentShield(currentShield), fMaxEnergy(maxEnergy), fCurrentEnergy(currentEnergy), fGateState(gateState) {
		fPosition[0] = position[0];
		fPosition[1] = position[1];
	}
	string getOwner() { return fOwner; }
	UnitCategory getUnitCat() { return fUnitCat; }
	int getID() { return fID; }
	int* getPosition() { return fPosition; }
	int getMaxHP() { return fMaxHP; }
	int getCurrentHP() { return fCurrentHP; }
	int getMaxShield() { return fMaxShield; }
	int getCurrentShield() { return fCurrentShield; }
	int getMaxEnergy() { return fCurrentEnergy; }
	int getCurrentEnergy() { return fCurrentEnergy; }
	GateState getGateState() { return fGateState; }

	void setOwner(string owner) { fOwner = owner; }
	void setUnitCat(UnitCategory unitCat) { fUnitCat = unitCat; }
	void setID(int iD) { fID = iD; }
	void setPosition(int position[2]) { fPosition[0] = position[0]; fPosition[1] = position[1]; }
	void setMaxHP(int maxHP) { fMaxHP = maxHP; }
	void setCurrentHP(int currentHP) { fCurrentHP = currentHP; }
	void setMaxShield(int maxShield) { fMaxShield = maxShield; }
	void setCurrentShield(int currentShield) { fCurrentShield = currentShield; }
	void setMaxEnergy(int maxEnergy) { fMaxEnergy = maxEnergy; }
	void setCurrentEnergy(int currentEnergy) { fCurrentEnergy = currentEnergy; }
	void setGateState(GateState gateState) { fGateState = gateState; }

	void PingStatus() { 		
		std::cout << "Owner: " << fOwner << ", Unit category: " << fUnitCat << ", ID: " << fID << ", Max HP: " << fMaxHP << ", Current HP: " << fCurrentHP << ", Max Shield: " << fMaxShield << ", Current Shield: " << fCurrentShield << ", Max Energy: " << fMaxEnergy << ", Current Energy: " << fCurrentEnergy << ", Gate State: " << fGateState << std::endl; 
	}
	void Listen(string message) { fMessage = message; }
	void Tell() { std::cout << fMessage << std::endl; }

	friend std::istream& operator>>(std::istream& aIStream, Unit& unit) {
		aIStream >> unit.fMessage;
		return aIStream;
	}

	friend std::ostream& operator<<(std::ostream& aOstream, Unit unit) {
		aOstream << unit.fMessage << std::endl;
		return aOstream;
	}

	~Unit(){}

};

