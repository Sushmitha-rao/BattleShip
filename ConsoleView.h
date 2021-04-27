/*
 * ConsoleView.h
 *
 *  Created on: Dec 6, 2019
 *      Author: Sushmitha
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include"Board.h"

/**
 *\brief This class represents the ConsoleView of the Board.
 *
 *This class access the board through it's pointer and prints the own grid and opponent's grid
 *
 *\author	Sushmitha
 * \version 1.0
 * \date DEC-2019
 */
class ConsoleView
{
private:

	/**
	 * This private data member is a pointer to the board object
	 */
	Board *board;
public:

	/**
	 * This constructor initializes the data member with board object's pointer
	 * @param board: represents a pointer to the board
	 */
	ConsoleView(Board *board);

	/**
	 * This public function prints the player's grid asnd opponent's grid
	 */
	void print();

};

#endif /* CONSOLEVIEW_H_ */
