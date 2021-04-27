/*
 * ConsoleView.cpp
 *
 *  Created on: Dec 6, 2019
 *      Author: Sushmitha
 */

#include "ConsoleView.h"

ConsoleView::ConsoleView(Board *board)
{
	this->board = board;
}

void ConsoleView::print()
{
	int rows = (board->getRows());
	int columns = board->getColumns();
	
	//declaration of own grid and opponent grid character arrays
	char OwnGrid[rows][columns];
	char OpponentGrid[rows][columns];
	
	//creating an object for the class GridPosition
	GridPosition pos;
	
	//local variable of row and column to hold the value of rows and columns
	//of the Ships.
	int row;
	int column;
	
	//gets the ships placed in the ownGrid
	vector<Ship> playerShips = board->getOwnGrid().getShips();

	map<GridPosition, Shot::Impact> opponentShots;
	map<GridPosition, Shot::Impact>::iterator it;

	//gets the opponent grid
	opponentGrid oppGrid = board->getOpponentGrid();

	//gets the status of shot in opponent's grid
	opponentShots = oppGrid.getShotsAt();


	//initialise the own grid with '~' character
	for (int irow = 0; irow < rows; ++irow)
	{
		for (int icolumn = 0; icolumn < columns; ++icolumn)
		{
			OwnGrid[irow][icolumn] = '~';
		}
	}

	for (int irow = 0; irow < rows; ++irow)
	{
		for (int icolumn = 0; icolumn < columns; ++icolumn)
		{
			//iterates over all the ships in the grid to get the blocked area
			for (auto itr = playerShips.begin(); itr != playerShips.end();
					++itr)
			{
				Ship ship = *itr;

				//obtains the occupied area of each ship in the grid
				set<GridPosition> shipPos = ship.occupiedArea();

				//iterates over ships occupied area to get the grid position
				for (auto itr1 = shipPos.begin(); itr1 != shipPos.end(); ++itr1)
				{
					pos = *itr1;

					//obtains the row value of the grid position
					row = (pos.getRow() - 65);

					//obtains the column value of the grid position
					column = (pos.getColumn() - 1);

					//intialises the ship occupied grid positions with # character
					OwnGrid[row][column] = '#';

				}

			}
		}
	}

	cout << "Own Grid" << endl;

	//prints the column number of the own grid
	for (int i = 1; i <= board->getColumns(); i++)
	{
		cout << "\t" << i;
	}
	cout << endl;

	for (int irow = 0; irow < board->getRows(); irow++)
	{
		//prints the row characters of the own grid
		char letter = irow + 65;
		cout << letter << "\t";
		for (int icolumn = 0; icolumn < board->getColumns(); ++icolumn)
		{
			//prints the owngrid
			cout << OwnGrid[irow][icolumn] << '\t';
		}
		cout << endl;
	}


	//prints the column number of the opponent grid
	cout << endl << "Opponent Grid" << endl;
	for (int i = 1; i <= board->getColumns(); i++)
	{
		cout << "\t" << i;
	}
	cout << endl;

	for (int irow = 0; irow < rows; ++irow)
	{
		for (int icolumn = 0; icolumn < columns; ++icolumn)
		{
			//initialize the opponentgrid
			OpponentGrid[irow][icolumn] = '~';
		}
	}

	for (int irow = 0; irow < rows; ++irow)
	{
		for (int icolumn = 0; icolumn < columns; ++icolumn)
		{

			//Concatenate the row and column to obtain the position
			string localString = char('A' + irow) + to_string(icolumn + 1);

			//Search for the position
			it = opponentShots.find(localString);

			//Check if the position has been hit, sunken or missed and
			//update the array with corresponding character
			switch (it->second)
			{
			case Shot::NONE:
				OpponentGrid[irow][icolumn] = '^';
				break;

			case Shot::HIT:
				OpponentGrid[irow][icolumn] = 'O';
				break;

			case Shot::SUNKEN:
				OpponentGrid[irow][icolumn] = 'O';
				break;
			}
		}
	}

	for (int irow = 0; irow < rows; ++irow)
	{
		//prints the row characters of the opponent grid
		char letter = irow + 65;
		cout << letter << "\t";
		for (int icolumn = 0; icolumn < columns; ++icolumn)
		{
			//prints the opponentgrid
			cout << OpponentGrid[irow][icolumn] << '\t';
		}
		cout << endl;
	}
}

