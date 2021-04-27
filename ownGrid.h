/*
 * ownGrid.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include"Shot.h"
#include <vector>
#include<iostream>
#include<map>

using namespace std;

/**
 * \brief This class represents the player's grid
 *
 * The data members of this class specifies the grid size
 * It also holds information about the placed  ships
 * It holds the data about number of ships of given length that can be placed
 * This class provides public method to place ship on the grid
 *
 * \author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */
class ownGrid
{
private:
	/**
	 * This private data member represents the number of rows in the grid
	 */
	int rows;

	/**
	 * This private data member represents the number of columns in the grid
	 */
	int columns;

	/**
	 * This private data member is a vector of all placed ships
	 */
	vector<Ship> ships;

	/**
	 * This private data member is a map that holds the data about number of ships of given length that can be placed
	 */
	map<int, int> shipTable;

	/**
	 * This private data member represents the set of positions that has been hit
	 */
	set<GridPosition>shotAt;

public:

	/**
	 * This default constructor initializes the number of rowa and columns values to default values
	 *
	 * @param: no parameters
	 */
	ownGrid();

	/**
	 * This constructor initializes the number of rows and columns values to specified values
	 *
	 * @param row: represents number of rows of the grid
	 * @param column:represents number of columns of the grid
	 */

	ownGrid(int rows, int columns);

	/**
	 * This public method gets the number of rows of the grid
	 *
	 * @param: no parameters
	 * @return The number of rows of the grid
	 */
	int getRows();

	/**
	 * This public method gets the number of columns of the grid
	 *
	 * @param: no parameters
	 * @return The number of columns of the grid
	 */
	int getColumns();

	/**
	 * This public method checks if the ship can be placed on the ship
	 *
	 * @param ship: represents the ship to be placed
	 * @return true if the ship is placed on the grid
	 * @return true if the ship is not placed on the grid
	 */
	bool placeShip(const Ship &ship);

	/**
	 * This public method gets the vector of placed ships
	 *
	 * @param: no parameters
	 * @return the vector of placed ships
	 */
	const vector<Ship> getShips();

	/**
	 * This public method takes the target position from the opponent ande returns the status of the shot
	 *
	 * @param shot: represents the position to be shot
	 * @return the status of the shot
	 */
	Shot::Impact takeBlow(const Shot& shot);

	/**
	 * This public method gets the set of all grid positions that are shot
	 *
	 * @param No parameters
	 * @return the set of all grid positions that are shot
	 */
	const set<GridPosition>getShotAt();

};

#endif /* OWNGRID_H_ */
