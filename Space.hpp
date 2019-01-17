/************************************
*Jill Ackerman
*************************************/
#ifndef SPACE_H
#define SPACE_H
#include "Player.hpp"

/*
*The space class is abstract; its pure virtual functions are each space's map/interact/menu etc,
*but all movement functions are unchanged and simply inherited by each derived class
*/
class Space {
public:
	Space();
	Space* getUp();
	Space* getDown();
	Space* getLeft();
	Space* getRight();
	void setUp(Space*);
	void setDown(Space*);
	void setLeft(Space*);
	void setRight(Space*);
	void moveUp(Space*);
	void moveDown(Space*);
	void moveLeft(Space*);
	void moveRight(Space*);
	Space* getCurrentLoc();
	void setCurrentLoc(Space*);
	virtual void printMap() = 0;
	virtual void interact() = 0;
	virtual void spaceMenu() = 0;
	virtual void description() = 0;
protected:
	static Player player;
	Item phaser = Item("phaser");
	Item heatShield = Item("heat shield");
	Item communicator = Item("communicator");
	Item crewLog = Item("crew log");
	Item researchNotes = Item("research notes");
	Item capacitor = Item("capacitor");
	Space* currentLoc = nullptr;
	Space* up = nullptr;
	Space* down = nullptr;
	Space* left = nullptr;
	Space* right = nullptr;

};
#endif

//Header for the derived Ship class
#ifndef SHIP_H
#define SHIP_H
class Ship : public Space {
public:
	Ship();
	bool getFixed();
	void setFixed(bool);
	void printMap();
	void description();
	void spaceMenu();
	void interact();
protected:
	bool phaserAdded = false;
	bool fixed = false;
};
#endif

//Header for the derived PlanetSurface class
#ifndef PLANETSURFACE_H
#define PLANETSURFACE_H
class PlanetSurface : public Space {
public:
	PlanetSurface();
	bool const loseHealth = true;
	void printMap();
	void description();
	void spaceMenu();
	void interact();
};
#endif

//Header for the derived PlanetSurface2 class
#ifndef PLANETSURFACE2_H
#define PLANETSURFACE2_H
class PlanetSurface2 : public Space {
public:
	PlanetSurface2();
	bool const loseHealth = true;
	void printMap();
	void description();
	void spaceMenu();
	void interact();
protected:
	bool heatShieldAdded = false;
};
#endif

//Header for derived PlanetSurface3 class
#ifndef PLANETSURFACE3_H
#define PLANETSURFACE3_H
class PlanetSurface3 : public Space {
public:
	PlanetSurface3();
	bool const loseHealth = true;
	void printMap();
	void description();
	void spaceMenu();
	void interact();
};
#endif

//Header for the derived StationFront class
#ifndef STATIONFRONT_H
#define STATIONFRONT_H
class StationFront : public Space {
public:
	StationFront();
	void printMap();
	void description();
	void spaceMenu();
	void interact();
protected:
	bool communicatorAdded = false;
};
#endif

//Header for derived ScienceLab class
#ifndef SCIENCELAB_H
#define SCIENCELAB_H
class ScienceLab : public Space {
public:
	ScienceLab();
	void printMap();
	void description();
	void spaceMenu();
	void interact();
protected:
	bool notesAdded = false;
};
#endif

//Header for derived CrewQuarters class
#ifndef CREWQUARTERS_H
#define CREWQUARTERS_H
class CrewQuarters : public Space {
public:
	CrewQuarters();
	void surpriseAttack(vector<Item>&);
	void printMap();
	void description();
	void spaceMenu();
	void interact();
protected:
	bool logAdded = false;
};
#endif

//Header for derived Hangar class
#ifndef HANGAR_H
#define HANGAR_H
class Hangar : public Space {
public:
	Hangar();
	void printMap();
	void surpriseAttack(vector<Item>&);
	void description();
	void spaceMenu();
	void interact();
protected:
	bool capacitorAdded = false;
};
#endif


