/*
 * Ship.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

/**
 *\brief This class represents a Ship
 *
 *This class has data members to represent the positions of bow and stern of a ship
 *This  class checks the validity of ship's positions and
 *It provides the occupied and blocked areas of ship through it's public methods
 *
 *\author	Sushmitha
 *\version  1.0
 *\date     DEC-2019
 */

class Ship
{

private:

	/**
	 * This private data member represents the grid position of bow of the ship
	 */
	GridPosition bow;

	/**
	 * This private data member represents the grid position of stern of the ship
	 */
	GridPosition stern;

public:

	/**
	 * This constructor initializes the bow and stern values of the ship
	 *
	 * @param bow: Represents the grid position occupied by bow
	 * @param stern: Represents the grid position occupied by stern
	 */
	Ship(const GridPosition &bow, const GridPosition &stern);

	/**
	 * This public function checks if the grid positions for bow and stern are valid,
	 * whether the ship is positioned horizontally or vertically and
	 * whether the length is between 2 and 5
	 *
	 * @param : no parameters
	 * @return true if the above conditions are satisfied
	 * @return false if the above conditions are not satisfied
	 */
	bool isValid();

	/**
	 * This public getter function gets the grid position occupied by bow of the ship
	 *
	 * @param : no parameters
	 * @return The grid position value of the bow
	 */
	GridPosition getBow();

	/**
	 * This public getter function gets the grid position occupied by stern of the ship
	 *
	 * @param : no parameters
	 * @return The grid position value of the stern
	 */
	GridPosition getStern();

	/**
	 * This public function gets length of the ship
	 *
	 * @param : no parameters
	 * @return The length of the ship
	 */
	int length();

	/**
	 * This public function gets all grid positions occupied by the ship
	 *
	 * @param : no parameters
	 * @return A set of all grid positions occupied by the ship
	 */
	const std::set<GridPosition> occupiedArea();

	/**
	 * This public function gets all grid positions blocked by the ship
	 *
	 * @param : no parameters
	 * @return A set of all grid positions blocked by the ship
	 */
	const std::set<GridPosition> BlockedArea();
};

#endif /* SHIP_H_ */
