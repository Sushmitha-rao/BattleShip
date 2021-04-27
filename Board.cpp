/*
 * Board.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: Sushmitha
 */

#include "Board.h"

Board::Board(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
	OwnGrid = ownGrid(rows, columns);
	OpponentGrid = opponentGrid(rows, columns);
}

int Board::getRows()
{
	return rows;
}

int Board::getColumns()
{
	return columns;
}

ownGrid& Board::getOwnGrid()
{
	return OwnGrid;
}

opponentGrid& Board::getOpponentGrid()
{
	return OpponentGrid;
}

