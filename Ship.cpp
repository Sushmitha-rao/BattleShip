/*
 * Ship.cpp
 *
 *  Created on: Dec 4, 2019
 *      Author: Sushmitha
 */

#include "Ship.h"

Ship::Ship(const GridPosition &bow, const GridPosition &stern)
{
	this->bow = bow;
	this->stern = stern;
}

bool Ship::isValid()
{
	if (bow.isValid() && stern.isValid())
	{
		//check if the ship is placed horizontally and the length is within the specified range
		if ((bow.getRow() == stern.getRow())
				&& (bow.getColumn() < stern.getColumn()) && length() >= 2
				&& length() <= 5)
			return true;

		//check if the ship is placed vertically and the length is within the specified range
		else if ((bow.getColumn() == stern.getColumn())
				&& (bow.getRow() < stern.getRow()) && length() >= 2
				&& length() <= 5)
			return true;
	}
	return false;
}

GridPosition Ship::getBow()
{
	return this->bow;
}

GridPosition Ship::getStern()
{
	return this->stern;
}

int Ship::length()
{
	int length = 0;
	length = occupiedArea().size();
	return length;

}

const std::set<GridPosition> Ship::occupiedArea()
{
	set<GridPosition> OccupiedSet;
	string OccupiedString;
	int orientation;

	//check if the ship is placed from left to right or viceversa
	if (bow < stern)
	{
		orientation = 1;
	}
	else
		orientation = 0;

	switch (orientation)
	{
	case 1:
		if ((bow.getRow() == stern.getRow()))
		{
			for (int column = bow.getColumn(); column <= stern.getColumn();
					column++)
			{
				//concatenation of row and column values
				OccupiedString = bow.getRow() + std::to_string(column);

				//insert the occupied grid position to the set
				OccupiedSet.insert(OccupiedString);
			}
		}

		else if ((bow.getColumn() == stern.getColumn()))
		{
			for (char row = bow.getRow(); row <= stern.getRow(); row++)
			{
				//concatenation of row and column values
				OccupiedString = row + std::to_string(stern.getColumn());

				//insert the occupied grid position to the set
				OccupiedSet.insert(OccupiedString);
			}
		}
		break;

	case 0:
		if ((bow.getRow() == stern.getRow()))
		{
			for (int column = stern.getColumn(); column <= bow.getColumn();
					column++)
			{
				//concatenation of row and column values
				OccupiedString = bow.getRow() + std::to_string(column);

				//insert the occupied grid position to the set
				OccupiedSet.insert(OccupiedString);
			}
		}

		else if ((bow.getColumn() == stern.getColumn()))
		{
			for (char row = stern.getRow(); row <= bow.getRow(); row++)
			{
				//concatenation of row and column values
				OccupiedString = row + std::to_string(stern.getColumn());

				//insert the occupied grid position to the set
				OccupiedSet.insert(OccupiedString);
			}
		}
		break;
	}

	return OccupiedSet;

}

const std::set<GridPosition> Ship::BlockedArea()
{
	set<GridPosition> BlockedSet;

	//Obatin the occupied area of the ship
	set<GridPosition> OccupiedSet = Ship::occupiedArea();

	set<GridPosition>::iterator itr;

	GridPosition pos;
	char row;
	int column;

	//traverse through the occupied set to access each occupied position
	for (itr = OccupiedSet.begin(); itr != OccupiedSet.end(); itr++)
	{
		BlockedSet.insert(*itr);
		string BlockedPosition;
		pos = *itr;
		row = pos.getRow();
		column = pos.getColumn();

		//Obatin all 8 positions surrounding the given position
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{

				char row_char = char(row + i);

				//Check if the traversed position is valid or not
				if (row_char >= 'A' && row_char <= 'Z' && (column + j) >= 1)
				{
					BlockedPosition = row_char + std::to_string(column + j);

					//insert the blocked grid position to the set
					BlockedSet.insert(BlockedPosition);
				}
			}
		}
	}

	return BlockedSet;
}

