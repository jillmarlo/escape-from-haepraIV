/************************************
*Jill Ackerman
*************************************/

#include "GameDriver.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;

//Main only gives a description of the theme/goal and instantiates a new instance
//of GameDriver to start the game
int main() {
	srand(time(NULL));
	cout << "You are a space traveler who, due to a malfunction, has crash landed on a nearby planet.  "
		"Your ship is damaged beyond repair, though it's possible that if you get a new power supply "
		"you could get the ship's communicator working and request a rescue.  You were injured in the crash "
		"though, so you are losing blood by the minute." << endl;
	GameDriver driver;
}