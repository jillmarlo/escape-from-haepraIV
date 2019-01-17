/************************************
*Jill Ackerman
*************************************/
#include "GameDriver.hpp" 
#include "Space.hpp"

GameDriver::GameDriver() {
	Ship *shipPtr;
	PlanetSurface *psPtr;
	PlanetSurface2 *ps2Ptr;
	PlanetSurface3 *ps3Ptr;
	StationFront *sfPtr;
	ScienceLab *labPtr;
	CrewQuarters *cqPtr;
	Hangar *hangarPtr;

	Ship ship;
	PlanetSurface planetSurface;
	PlanetSurface2 planetSurface2;
	PlanetSurface3 planetSurface3;
	StationFront stationFront;
	ScienceLab scienceLab;
	CrewQuarters crewQuarters;
	Hangar hangar;

	shipPtr = &ship;
	psPtr = &planetSurface;
	ps2Ptr = &planetSurface2;
	ps3Ptr = &planetSurface3;
	sfPtr = &stationFront;
	labPtr = &scienceLab;
	cqPtr = &crewQuarters;
	hangarPtr = &hangar;

	ship.setRight(psPtr);
	planetSurface.setLeft(shipPtr);
	planetSurface.setRight(ps2Ptr);
	planetSurface2.setLeft(psPtr);
	planetSurface2.setUp(ps3Ptr);
	planetSurface3.setRight(sfPtr);
	planetSurface3.setDown(ps2Ptr);
	stationFront.setDown(labPtr);
	stationFront.setLeft(ps3Ptr);
	stationFront.setRight(cqPtr);
	scienceLab.setUp(sfPtr);
	scienceLab.setRight(hangarPtr);
	crewQuarters.setLeft(sfPtr);
	crewQuarters.setDown(hangarPtr);
	hangar.setUp(cqPtr);
	hangar.setLeft(labPtr);

	shipPtr->description();
	shipPtr->spaceMenu();
}