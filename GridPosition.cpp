/*
 * GridPosition.cpp
 *
 *  Created on: Dec 2, 2019
 *      Author: Sushmitha
 */

#include "GridPosition.h"

GridPosition::GridPosition()
{
	this->row = 'A';
	this->column = 1;
}

GridPosition::GridPosition(char row, int column)
{
	this->row = row;
	this->column = column;
}

GridPosition::GridPosition(string Position)
{
	int length = 0;
	string strTemp;
	length = Position.length();
	row = Position.at(0);
	strTemp = Position.substr(1, length);
	column = stoi(strTemp);
}

bool GridPosition::isValid()
{
	if ((row >= 'A' && row <= 'Z') && column > 0)
		return true;

	else
		return false;

}

char GridPosition::getRow()
{
	return this->row;
}

int GridPosition::getColumn()
{
	return this->column;
}

GridPosition::operator string()
{
	string Pos;

	//string concatenation
	Pos = row + to_string(column);
	return Pos;
}

bool GridPosition::operator ==(GridPosition other) const
{
	if (this->row == other.row && this->column == other.column)
		return true;
	else
		return false;
}

bool GridPosition::operator <(GridPosition other) const
{
	if (this->row < other.row)
		return true;
	else if ((this->row == other.row) && (this->column < other.column))
		return true;
	else
		return false;
}

