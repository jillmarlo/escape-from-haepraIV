/************************************
*Jill Ackerman
*************************************/
#include "Player.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Player::Player() {
	health = 20;
}

int Player::getHealth() {
	return health;
}

void Player::setHealth(int val) {
	health = val;
}

void Player::setHasWon(bool val) {
	hasWon = val;
}

bool Player::getHasWon() {
	return hasWon;
}

bool Player::getHasComm() {
	return hasCommunicator;
}

void Player::setHasComm(bool val) {
	hasCommunicator = val;
}

void Player::updateHealth() {
	health -= 1;
	if (health == 0) {
		cout << "You lost too much blood and lost consciousness." << endl;
		cout << "Game Over" << endl;
	}
}

void Player::printInv(vector<Item>& inv) {
	for (Item& item : inv) {
		cout << item.getName() << endl;
	}
}


void Player::addToInventory(vector<Item>& inv, Item& item) {
	inv.push_back(item);
}

void Player::removeFromInventory(vector<Item>& inv) {
	int input;
	if (inv.size() != 0) {
		cout << "Which item would you like to drop? Enter 1, 2, or 3" << endl;
		for (Item& item : inv) {
			cout << item.getName() << endl;
		}
		cin >> input;
		if ((input > inv.size()) || (input < 1)) {
			cout << "Item does not exist, try again" << endl;
			return;
		}
		else {
			cout << "Dropping " << inv.at(input - 1).getName() << endl;
			inv.erase(inv.begin() + (input - 1));
			cout << "Inventory now contains: " << endl;
			printInv(inventory);
		}
	}
}

vector<Item>& Player::getInventory() {
	return inventory;
}

Item::Item(string st) {
	name = st;
}

string Item::getName() {
	return name;
}