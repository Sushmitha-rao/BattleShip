/*
 * opponentGrid.h
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include"Shot.h"
#include <map>
#include <vector>
#include<iostream>

using namespace std;

/**
 * \brief This class represents the opponent grid
 *
 * The data members of this class specifies the grid size
 * It also holds information about the sunken ships
 * It holds the information about the grid positions that have been shot and the shot impact
 *
 * \author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */
class opponentGrid
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
	 * This private data member represents  a vector of opponent's all sunken ships
	 */
	vector<Ship> sunkenShips;

	/**
	 * This private map holds the information about the grid positions that have been shot
	 * and the shot impact
	 */
	map<GridPosition, Shot::Impact> shots;

public:
	/**
	 * This constructor initializes the data members with default values
	 *
	 * @param: no parameters
	 */
	opponentGrid();

	/**
	 * This constructor initializes the data members with specified values
	 * @param rows: represents the number of rows of the grid
	 * @param columns: represents the number of rows of the grid
	 */
	opponentGrid(int rows, int columns);

	/**
	 * This public method gets the number of rows of the grid
	 *
	 * @param: no parameters
	 * @return The number of rows of the grid
	 */
	int getRow();

	/**
	 * This public method gets the number of columns of the grid
	 *
	 * @param: no parameters
	 * @return The number of columns of the grid
	 */
	int getColumn();

	/**
	 * This public method updates the map with the impact of a shot on the grid position
	 * @param shot: represents the shot grid position
	 * @param impact: represents the impact of shot (of type enum)
	 */
	void shotResult(const Shot &shot, Shot::Impact impact);

	/**
	 * This public getter method gets information about the grid positions that have been shot
	 * and the shot impact
	 * @return the map of all shot grid positions and the corresponding shot impact
	 */
	const map<GridPosition, Shot::Impact>& getShotsAt();
};

#endif /* OPPONENTGRID_H_ */
