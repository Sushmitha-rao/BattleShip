/*
 * GridPosition.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Sushmitha
 */

#ifndef GRIDPOSITION_H_   // Header für die Standard-IO-Objekte (z.B. cout, cin)
#define GRIDPOSITION_H_

#include "iostream"
#include "string.h"
//#include "stdlib.h"
using namespace std;

/**
 * \brief This class represents a position on the grid
 *
 * The Grid position can be set either by passing the values of rows and columns
 * or  by passing a string to constructor
 * This class checks for the the validity of the position
 *  It also provides the getter functions for the given position
 *
 * \author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */

class GridPosition
{
private:

	/**
	 * This data member represents the row value of the given position
	 */
	char row;

	/**
	 * This data member represents the column value of the given position
	 */
	int column;

public:

	/**
	 * This default constructor initializes the row and column values to default values
	 *
	 * @param: no parameters
	 */
	GridPosition();

	/**
	 * This constructor initializes the row and column values to specified values
	 *
	 * @param row: represents row of the position
	 * @param column:represents column of the position
	 */
	GridPosition(char row, int column);

	/**
	 * This constructor takes the position as a string and
	 * assigns row and column with corresponding values
	 *
	 * @param Position: represents the grid position value as a string
	 */
	GridPosition(string Position);

	/**
	 * This public function checks if the given position is valid or not
	 *
	 * @param : no parameters
	 *
	 * @return true if the grid position is valid
	 * @return false if the grid position is not valid
	 */
	bool isValid();

	/**
	 * This public getter function gets the row value of position
	 *
	 * @param : no parameters
	 *
	 * @return The row value of grid position
	 */
	char getRow();

	/**
	 * This public getter function gets the column value of position
	 *
	 * @param : no parameters
	 *
	 * @return The column value of grid position
	 */
	int getColumn();

	/**
	 * std::string is overloaded to obtain the concatenation of row and column
	 */
	operator string();

	/**
	 * The == operator is overloaded to check if two grid positions are equal
	 *
	 * @param : no parameters
	 *
	 * @return true if the two grid positions are equal
	 * @return false if the two grid positions are not equal
	 */
	bool operator==(GridPosition other) const;

	/**
	 * The < operator is overloaded so that a set of grid positions can be formed
	 * and this operator overloading is also used to
	 * compare the bow and stern values of a ship
	 *
	 * @param : no parameters
	 *
	 * @return true if the first position is less than the second one
	 * @return false if the first position is not less than the second one
	 */
	bool operator<(GridPosition other) const;
};

#endif /* GRIDPOSITION_H_ */
