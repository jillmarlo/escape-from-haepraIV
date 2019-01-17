/************************************
*Jill Ackerman
*Final Project
*************************************/
#include "Space.hpp"
#include "GameDriver.hpp"
#include "Player.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Space::Space() {
}

Player Space::player;

Space* Space::getUp() {
	return up;
}

void Space::setUp(Space* ptr) {
	up = ptr;
}

Space* Space::getDown() {
	return down;
}

void Space::setDown(Space* ptr) {
	down = ptr;
}

Space* Space::getLeft() {
	return left;
}

void Space::setLeft(Space* ptr) {
	left = ptr;
}

Space* Space::getRight() {
	return right;
}

void Space::setRight(Space* ptr) {
	right = ptr;
}

//Moves currentloc pointer to one space above
void Space::moveUp(Space* cl) {
	cl = getUp();
	cl->description();
	cl->spaceMenu();
}

//Moves currentloc pointer to one space below
void Space::moveDown(Space* cl) {
	cl = getDown();
	cl->description();
	cl->spaceMenu();
}

//Moves currentloc pointer to one space to the left
void Space::moveLeft(Space* cl) {
	cl = getLeft();
	cl->description();
	cl->spaceMenu();
}

//Moves currentloc pointer to one space to the right
void Space::moveRight(Space* cl) {
	cl = getRight();
	cl->description();
	cl->spaceMenu();
}

Space* Space::getCurrentLoc() {
	return currentLoc;
}

void Space::setCurrentLoc(Space* cl) {
	currentLoc = cl;
}

Ship::Ship() {
}

void Ship::setFixed(bool val) {
	fixed = val;
}

bool Ship::getFixed() {
	return fixed;
}

//Prints the map with current location as ship
void Ship::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    | X |     |     |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

//Prints map and descirbes the current location via the console
void Ship::description() {
	printMap();
	cout << "You are on the Nova class ship 'The Artemis,' at its crash site on an unexplored "
		"micro planet.  The ship is small, and has major damage on its hull from the crash. "
		<< endl;
}

//Ship's interact function; changes based on whether player has the capacitor item
void Ship::interact() {
	if (fixed == false) {
		cout << "You try to boot up the communication console, but it's unresponsive.  "
			"Maybe if you could find an alternate power source you could repair it..." << endl;
	}
	else {
		cout << "You fixed the communication console and were able to contact your superiors.  Help is "
			"on the way." << endl;
		player.setHasWon(true);
	}
}

//Menu for the Ship location
void Ship::spaceMenu() {
	int input = 0;
	while (input != 1) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to leave the ship" << endl;
		cout << "Press 2 to add phaser gun to pack" << endl;
		cout << "Press 3 to to send SOS/try to contact Io moon base" << endl;
		cin >> input;

		if (input == 1) {
			moveRight(currentLoc);
		}
		else if (input == 2) {
			if (phaserAdded == true) {
				cout << "Phaser already added" << endl;
			}
			else {
				if (player.getInventory().size() < 3) {
					cout << "Phaser added to inventory" << endl;
					player.addToInventory(player.getInventory(), phaser);
					phaserAdded = true;
				}
				else {
					cout << "Inventory is full" << endl;
				}
			}
		}
		else if (input == 3) {
			interact();
		}
	}
}

PlanetSurface::PlanetSurface() {
}

//Prints the map with current location as PlanetSurface
void PlanetSurface::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |  X  |     |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void PlanetSurface::description() {
	printMap();
	player.updateHealth();
	cout << "Inventory: " << endl;
	player.printInv(player.getInventory());
	cout << "You are on the surface of the unknown micro planet.  The surrounding terrain is bleak, "
		"and appears harsh.  The surface is dark orange, and deep, cavernous cracks dot the "
		"immediate area." << endl;
}

void PlanetSurface::interact() {
	cout << "You remove your helmet and feel a burning sensation all over your exposed skin" << endl;
	player.setHealth(0);
}

void PlanetSurface::spaceMenu() {
	int input = 0;
	while ((input != 2) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to enter the Artemis" << endl;
		cout << "Press 2 to explore to your right" << endl;
		cout << "Press 3 check health" << endl;
		cout << "Press 4 to remove helmet" << endl;
		cin >> input;

		if (input == 1) {
			moveLeft(currentLoc);
		}
		else if (input == 2) {
			moveRight(currentLoc);
		}
		else if (input == 3) {
			cout << "Health is: " << player.getHealth() << endl;
		}
		else if (input == 4) {
			interact();
		}
	}
}

PlanetSurface2::PlanetSurface2() {
}

//Prints the map with current location as PlanetSurface2
void PlanetSurface2::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |  X  |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void PlanetSurface2::description() {
	printMap();
	player.updateHealth();
	cout << "Debris from your ship is scattered about.  High winds blow orange dust and obscure "
		"your sight.  You tread carefully around the fissures in the terrain, and notice in the distance "
		"some rocks that seem to have been intentioanlly cleared to make a path." << endl;
}

void PlanetSurface2::interact() {
	int input;
	cout << "You look through the debris; nothing seems salvageable except part of the heat shield.  "
		"Would you like to add the heat shield part to inventory?  Press 1 for yes or 2 for no" << endl;
	cin >> input;
	if (input == 1) {
		if (heatShieldAdded == true) {
			cout << "Heat shield part already added" << endl;
		}
		else {
			if (player.getInventory().size() < 3) {
				cout << "Heat shield part added to inventory" << endl;
				player.addToInventory(player.getInventory(), heatShield);
				heatShieldAdded = true;
			}
			else {
				cout << "Can't carry more items" << endl;
			}
		}	
	}
	else if (input == 2) {
		cout << "You leave the heat shield part on the ground" << endl;
	}
}

void PlanetSurface2::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to move closer to ship" << endl;
		cout << "Press 2 to explore only clear path" << endl;
		cout << "Press 3 to check health" << endl;
		cout << "Press 4 to inspect debris" << endl;
		cin >> input;

		if (input == 1) {
			moveLeft(currentLoc);
		}
		else if (input == 2) {
			moveUp(currentLoc);
		}
		else if (input == 3) {
			cout << "Health is: " << player.getHealth() << endl;
		}
		else if (input == 4) {
			interact();
		}
	}
}

PlanetSurface3::PlanetSurface3() {
}

//Prints the map with current location as PlanetSurface3
void PlanetSurface3::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |  X  |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |     |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void PlanetSurface3::description() {
	printMap();
	player.updateHealth();
	cout << "There is what looks to be a terrestrial station not far from your current position, "
		"well hidden by some towering rocks.  It seems quiet, possibly unmanned." << endl;
}

void PlanetSurface3::interact() {
	cout << "You hide behind some large rocks and watch the station.  You don't see any people or craft" << endl;
}

void PlanetSurface3::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to return to area closer to ship" << endl;
		cout << "Press 2 to enter terrestrial station" << endl;
		cout << "Press 3 to check health" << endl;
		cout << "Press 4 to to hide and watch for movement on the station " << endl;
		cin >> input;

		if (input == 1) {
			moveDown(currentLoc);
		}
		else if (input == 2) {
			moveRight(currentLoc);
		}
		else if (input == 3) {
			cout << "Health is: " << player.getHealth() << endl;
		}
		else if (input == 4) {
			interact();
		}
	}
}

StationFront::StationFront() {
}

//Prints the map with current location as StationFront
void StationFront::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |  X  |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |     |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void StationFront::description() {
	printMap();
	cout << "The front room of the station is deserted; the only audible sound is the outside wind.  "
		"The front room contains an antechamber, a non-functioning command console, and various doors." << endl;
}

void StationFront::interact() {
	int input;
	cout << "You dust off the console - it appears to still function, though most things require a passcode" << endl;
	cout << "Not far from the console you see what looks to be a communicator" << endl;
	cout << "Would you like to add communicator to inventory? Press 1 for yes or 2 for no" << endl;
	cin >> input;
	if (input == 1) {
		if (communicatorAdded == true) {
			cout << "Communicator already added" << endl;
		}
		else {
			if (player.getInventory().size() < 3) {
				cout << "Communicator added to inventory" << endl;
				player.addToInventory(player.getInventory(), communicator);
				player.setHasComm(true);
				communicatorAdded = true;
			}
			else {
				cout << "Can't carry more items" << endl;
			}
		}
	}
	else if (input == 2) {
		cout << "You leave the communicator" << endl;
	}
}

void StationFront::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to exit the station to the planet surface" << endl;
		cout << "Press 2 to enter door below you" << endl;
		cout << "Press 3 to enter door to the right " << endl;
		cout << "Press 4 to inspect the command console" << endl;
		cin >> input;

		if (input == 1) {
			moveLeft(currentLoc);
		}
		else if (input == 2) {
			moveDown(currentLoc);
		}
		else if (input == 3) {
			moveRight(currentLoc);
		}
		else if (input == 4) {
			interact();
		}
	}
}

ScienceLab::ScienceLab() {
}

//Prints the map with current location as ScienceLab
void ScienceLab::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |     |  X  |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

//Descirbes the Science Lab
void ScienceLab::description() {
	printMap();
	cout << "This room appears to be a science lab or research space.  Various high-tech looking equipment "
		"populates the room, and there are sealed containers and research notes strewn about a center table."
		<< endl;
}

void ScienceLab::interact() {
	int input;
	cout << "You look around the lab, though there doesn't seem to be much here aside from notes on the tables" << endl;
	cout << "Would you like to add reaearch notes to your inventory? Press 1 for yes or 2 for no" << endl;
	cin >> input;

	if (input == 1) {
		if (notesAdded == true) {
			cout << "Research notes already added" << endl;
		}
		else {
			if (player.getInventory().size() < 3) {
				cout << "Research notes added to inventory" << endl;
				player.addToInventory(player.getInventory(), researchNotes);
				notesAdded = true;
			}
			else {
				int input;
				cout << "Can't carry more items" << endl;
				cout << "Would you like to drop an item? Press 1 for yes or 2 for no" << endl;
				cin >> input;
				if (input == 1) {
					player.removeFromInventory(player.getInventory());
					player.printInv(player.getInventory());
				}
			}
		}
	}
	else if (input == 2) {
		cout << "You leave the notes on the table" << endl;
	}
}

void ScienceLab::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to enter the door to the right" << endl;
		cout << "Press 2 to return to station front" << endl;
		cout << "Press 3 to inspect lab equipment " << endl;
		cin >> input;

		if (input == 1) {
			if (player.getHasComm() == false) {
				cout << "The door remains close; a warning displays on the door console that only authorized "
					"personnel may enter this room." << endl;
				return;
			}
			else {
				moveRight(currentLoc);
			}
		}
		else if (input == 2) {
			moveUp(currentLoc);
		}
		else if (input == 3) {
			interact();
		}
	}
}

CrewQuarters::CrewQuarters() {
}

//Prints the map with current location as CrewQuarters
void CrewQuarters::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |  X  |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |     |     |     |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void CrewQuarters::surpriseAttack(vector<Item>& inv) {
	cout << endl;
	cout << "From the corner of your eye you see something approaching - you turn to see a grotesque, humanoid "
		"figure coming toward you.  It has black eyes and gray, dead-looking skin.  It starts rushing toward"
		" you to attack, long teeth bared!" << endl;
	if (inv.size() > 0) {
		for (Item& item : inv) {
			if (item.getName() == "phaser") {
				int chance = rand() % 2 + 1;
				if (chance == 1) {
					cout << "You pull out your phaser quickly and attack! The alien collapses and dies" << endl;
				}
				else if (chance == 2) {
					cout << "You didn't grab your phaser fast enough! The alien kills you!" << endl;
					cout << "Game Over" << endl;
					return;
				}
			}
		}
	}
	else {
		cout << "You have no protection; the alien kills you!" << endl;
		cout << "Game Over" << endl;
		return;
	}
}

void CrewQuarters::description() {
	printMap();
	cout << "This room appears to be crew quarters.  Small beds line the walls, and a few personal effects "
		"can be seen.  Everything looks to have been undisturbed for some time." << endl;
	int chance = rand() % 4 + 1;
	if (chance == 4) {
		surpriseAttack(player.getInventory());
	}
}

void CrewQuarters::interact() {
	int input;
	cout << "It appears that the crew left in a hurry; the beds are unmade. You find what looks to be a "
		"personal log from a crew member." << endl;
	cout << "Press 1 to read the log, 2 to put the log in inventory, or 3 to do nothing." << endl;
	cin >> input;
	if (input == 1) {

	}
	else if (input == 2) {
		if (logAdded == true) {
			cout << "Crew log already added" << endl;
		}
		else {
			if (player.getInventory().size() < 3) {
				cout << "Crew log added to inventory" << endl;
				player.addToInventory(player.getInventory(), crewLog);
				logAdded = true;
			}
			else {
				int input;
				cout << "Can't carry more items" << endl;
				cout << "Would you like to drop an item? Press 1 for yes or 2 for no" << endl;
				cin >> input;
				if (input == 1) {
					player.removeFromInventory(player.getInventory());
				}
			}
		}
	}
	else if (input == 3) {
		cout << "You leave the log on a bedside table." << endl;
	}
}

void CrewQuarters::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to enter the door below you" << endl;
		cout << "Press 2 to return to the station front" << endl;
		cout << "Press 3 to inspect crew quarters " << endl;
		cin >> input;
		if (input == 1) {
			if (player.getHasComm() == false) {
				cout << "The door remains closed; a warning displays on the door console that only authorized "
					"personnel may enter this room." << endl;
			}
			else {
				moveDown(currentLoc);
			}
		}
		else if (input == 2) {
			moveLeft(currentLoc);
		}
		else if (input == 3) {
			interact();
		}
	}
}

Hangar::Hangar() {
}

//Prints the map with current location as Hanger
void Hangar::printMap() {
	cout << "              +-----+-----+-----+" << endl;
	cout << "              |     |     |     |" << endl;
	cout << "	      +-----+-----+-----+" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << "    |   |     |     |     |  X  |" << endl;
	cout << "    +---+-----+-----+-----+-----+" << endl;
	cout << endl;
}

void Hangar::surpriseAttack(vector<Item>& inv) {
	cout << endl;
	cout << "From the corner of your eye you see something approaching - you turn to see a grotesque, humanoid "
		"figure coming toward you.  It has black eyes and gray, dead-looking skin.  It starts rushing toward"
		" you to attack, long teeth bared!" << endl;
	if (inv.size() > 0) {
		for (Item& item : inv) {
			if (item.getName() == "phaser") {
				int chance = rand() % 2 + 1;
				if (chance == 1) {
					cout << "You pull out your phaser quickly and attack! The alien collapses and dies" << endl;
				}
				else if (chance == 2) {
					cout << "You didn't grab your phaser fast enough! The alien kills you!" << endl;
					cout << "Game Over" << endl;
					return;
				}
			}
		}
	}
	else {
		cout << "You have no protection; the alien kills you!" << endl;
		cout << "Game Over" << endl;
		return;
	}
}

void Hangar::description() {
	printMap();
	cout << "This large room is a hangar - there are no space capable vessels, but some terrestrial vehicles "
		"are present, some with wheels and some with tank-like treads.  Storage banks sit in the far corner." << endl;
	int chance = rand() % 4 + 1;
	if (chance == 4) {
		surpriseAttack(player.getInventory());
	}
}

void Hangar::interact() {
	int input;
	cout << "You cross the hangar and search the storage lockers.  You find a small power capacitor - this just might "
		"allow you to fix the Artemis comm." << endl;
	cout << "Would you like to take the power capacitor? Press 1 for yes or 2 for no" << endl;
	cin >> input;
	if (input == 1) {
		if (capacitorAdded == true) {
			cout << "Capacitor already added" << endl;
		}
		else {
			if (player.getInventory().size() < 3) {
				cout << "Capacitor added to inventory" << endl;
				player.addToInventory(player.getInventory(), capacitor);
				capacitorAdded = true;
			}
			else {
				int input;
				cout << "Can't carry more items" << endl;
				cout << "Would you like to drop an item? Press 1 for yes or 2 for no" << endl;
				cin >> input;
				if (input == 1) {
					player.removeFromInventory(player.getInventory());
				}
			}
		}
	}
	else if (input == 2) {
		cout << "You leave the capacitor in the locker." << endl;
	}
}

void Hangar::spaceMenu() {
	int input = 0;
	while ((input != 1) && (input != 2)) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to return to crew quarters" << endl;
		cout << "Press 2 to return to Science Lab" << endl;
		cout << "Press 3 to to inspect hangar " << endl;
		cin >> input;

		if (input == 1) {
			moveUp(currentLoc);
		}
		else if (input == 2) {
			moveLeft(currentLoc);
		}
		else if (input == 3) {
			interact();
		}
	}
}