/*
 * Board.h
 *
 *  Created on: Dec 6, 2019
 *      Author: Sushmitha
 */

#ifndef BOARD_H_
#define BOARD_H_
#include"ownGrid.h"
#include"opponentGrid.h"

/**
 *\brief This class represents the Board which models the game from one player's perspective
 *
 *It specifies the size of player's and opponent's grid
 *It provides access to the grids through public getter functions
 *
 *
 *\author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */
class Board
{
private:

	/**
	 * This private data member represents the number of rows of the board
	 */
	int rows;

	/**
	 * This private data member represents the number of columns of the board
	 */
	int columns;

	/**
	 * This private data member represents the object of player's grid
	 */
	ownGrid OwnGrid;

	/**
	 * This private data member represents the object of opponent's grid
	 */
	opponentGrid OpponentGrid;
public:

	/**
	 * This constructor sets the size of player's and opponent's grid
	 * @param rows: represents total number of rows of board
	 * @param columns:represents total number of columns of board
	 */
	Board(int rows, int columns);

	/**
	 * This public method gets the number of rows of the board
	 *
	 * @param: no parameters
	 * @return The number of rows of the board
	 */
	int getRows();

	/**
	 * This public method gets the number of columns of the board
	 *
	 * @param: no parameters
	 * @return The number of columns of the board
	 */
	int getColumns();

	/**
	 * This public getter function returns the own grid object
	 *
	 * @param: no parameters
	 * @return the player's grid object
	 */
	ownGrid& getOwnGrid();

	/**
	 * This public getter function returns the opponent grid object
	 *
	 * @param: no parameters
	 * @return the opponent's grid object
	 */
	opponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
