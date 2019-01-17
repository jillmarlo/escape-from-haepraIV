/************************************
*Jill Ackerman
*************************************/
#include <vector>
#include <string>
using std::string;
using std::vector;

//Header/definition of the simple Item class
#ifndef ITEM_H
#define ITEM_H

class Item {
protected:
	string name;
public:
	Item(string);
	string getName();
};
#endif

//Header/definition of the player class; each player has health and a
//vector inventory as well as funcions related to health/inventory
#ifndef PLAYER_H
#define PLAYER_H
class Player {
protected: 
	vector<Item> inventory;
	int health;
	bool hasCommunicator = false;
	bool hasWon = false;
public:
	Player();
	vector<Item>& getInventory();
	void printInv(vector<Item>&);
	void updateHealth();
	bool getHasWon();
	void setHasWon(bool);
	bool getHasComm();
	void setHasComm(bool);
	void addToInventory(vector<Item>&, Item&);
	void removeFromInventory(vector<Item>&);
	int getHealth();
	void setHealth(int);
};
#endif



