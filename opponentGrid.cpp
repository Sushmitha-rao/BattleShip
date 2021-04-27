/*
 * opponentGrid.cpp
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#include "opponentGrid.h"

opponentGrid::opponentGrid()
{
	this->rows = 1;
	this->columns = 1;

}

opponentGrid::opponentGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;
}

int opponentGrid::getRow()
{
	return rows;
}

int opponentGrid::getColumn()
{
	return columns;
}

void opponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
	Shot localShot = shot;

	//Update the map with shot grid position and the shot impact
	shots.insert(
	{ localShot.getTargetPosition(), impact });
}

const map<GridPosition, Shot::Impact>& opponentGrid::getShotsAt()
{
	return shots;
}
