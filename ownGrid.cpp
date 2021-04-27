/*
 * ownGrid.cpp
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#include "ownGrid.h"
#include<set>
#include<algorithm>
#include<map>

ownGrid::ownGrid()
{
	rows = 0;
	columns = 0; // TODO Auto-generated constructor stub

}

ownGrid::ownGrid(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

	//initialize the map with the pairs length/number of ships
	shipTable.insert(
	{ 5, 1 });
	shipTable.insert(
	{ 4, 2 });
	shipTable.insert(
	{ 3, 3 });
	shipTable.insert(
	{ 2, 4 });
}

int ownGrid::getRows()
{
	return rows;
}

int ownGrid::getColumns()
{
	return columns;
}

bool ownGrid::placeShip(const Ship &ship)
{

	Ship newShip = ship;

	//get the bow and stern positions of the new ship
	GridPosition bow = newShip.getBow();
	GridPosition stern = newShip.getStern();
	int length = newShip.length();

	//obtain the occupied area of the new ship
	set<GridPosition> occupiedSet = newShip.occupiedArea();

	set<GridPosition> setIntersect;

	//obtain the already existing ships
	vector<Ship> existingShips = getShips();

	map<int, int>::iterator itr;

	//find the lentgh of new ship in the map
	itr = shipTable.find(length);

	for (auto it = existingShips.begin(); it != existingShips.end(); it++)
	{
		Ship existingShip = *it;

		//obtain blocked area of the already existing ships
		set<GridPosition> BlockedArea = existingShip.BlockedArea();

		//Obtain the intersection between blocked area of already existing ships and occupied area of new ship
		set_intersection(occupiedSet.begin(), occupiedSet.end(),
				BlockedArea.begin(), BlockedArea.end(),
				std::inserter(setIntersect, setIntersect.end()));
	}

	//check if the intersection is empty
	if (setIntersect.empty())
	{
		//check if the ship is placed horizontally or vertically
		if (bow.getRow() == stern.getRow()
				|| bow.getColumn() == stern.getColumn())
		{
			//check the boundary conditions
			if (bow.getRow() <= 'A' + rows && stern.getRow() <= 'A' + rows
					&& bow.getColumn() <= columns
					&& stern.getColumn() <= columns)
			{
				//check if the number of ships is not equal to zero in the map
				if (itr->second != 0)
				{

					//decrement the number in the map
					itr->second--;

					//add the new ship to the grid
					ships.push_back(newShip);
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

	return false;
}

const vector<Ship> ownGrid::getShips()
{
	return ships;
}

Shot::Impact ownGrid::takeBlow(const Shot &shot)
{
	Shot localShot = shot;
	set<GridPosition> result;
	Shot::Impact ShotStatus;

	//Obatin the already existing ships
	vector<Ship> existingShip = getShips();


	for (auto itr = existingShip.begin(); itr != existingShip.end(); ++itr)
	{
		Ship localship = *itr;

		//Obtain the occupied area of each ship
		set<GridPosition> occupiedset = localship.occupiedArea();

		for (auto itr1 = occupiedset.begin(); itr1 != occupiedset.end(); ++itr1)
		{
			GridPosition pos = *itr1;

			//Check if the occupied position of a ship is same as the target position
			if (pos == localShot.getTargetPosition())
			{

				//Insert the position to the set of shot grid positions
				shotAt.insert(pos);

				//Obtain the intersection of occupied set of the ships and the set of shot grid positions
				set_intersection(occupiedset.begin(), occupiedset.end(),
						shotAt.begin(), shotAt.end(),
						std::inserter(result, result.end()));

				//Check if the intersection set has same size of the local ship's length
				if ((result.size() - localship.length()) == 0)
				{
					ShotStatus = Shot::SUNKEN;
					break;
				}
				else
					ShotStatus = Shot::HIT;
				break;
			}
			else
				ShotStatus = Shot::NONE;

		}
		if (ShotStatus != Shot::NONE)
			break;
	}
	return ShotStatus;
}

const set<GridPosition> ownGrid::getShotAt()
{
	return shotAt;
}
