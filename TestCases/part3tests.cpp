/*
 * part3tests.cpp
 *
 *  Created on: Dec 7, 2019
 *      Author: Sushmitha
 */

#include <iostream>
#include <stdlib.h>
#include"Ship.h"
#include "Board.h"
#include "ConsoleView.h"
#include "GridPosition.h"
#include "OpponentGrid.h"
#include "OwnGrid.h"
#include<set>

void assertTrue2(bool condition, string failedMessage)
{
	if (!condition)
	{
		cout << failedMessage << endl;
	}
}

void part3tests()
{
	Board myBoard(10, 10);

	ConsoleView viewBoard(&myBoard);

	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "A2" }, GridPosition
	{ "A5" } }), "Cannot place ship horizontally"); //Length = 4
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "C3" }, GridPosition
	{ "G3" } }), "Cannot place ship vertically"); //Length = 5
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "G8" }, GridPosition
	{ "J8" } }), "Cannot place a ship of length 4"); //Length = 4
	assertTrue2(!myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "J4" }, GridPosition
	{ "J1" } }), "Cannot place this ship"); //Length = 4
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "E6" }, GridPosition
	{ "G6" } }), "Cannot place this ship"); //Length = 3
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "B8" }, GridPosition
	{ "B9" } }), "Cannot place this ship"); //Length = 2
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "I1" }, GridPosition
	{ "I3" } }), "Cannot place this ship"); //Length = 3
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "D1" }, GridPosition
	{ "F1" } }), "Cannot place this ship"); //Length = 3
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "J6" }, GridPosition
	{ "J5" } }), "Cannot place this ship"); //Length = 2
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "D9" }, GridPosition
	{ "E9" } }), "Cannot place this ship"); //Length = 2
	assertTrue2(myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "H10" }, GridPosition
	{ "I10" } }), "Cannot place this ship"); //Length = 2
	assertTrue2(!myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "C5" }, GridPosition
	{ "C6" } }), "Can place this ship"); //Length = 2
	assertTrue2(!myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "H2" }, GridPosition
	{ "H4" } }), "Can place the ship in blocked area");
	assertTrue2(!myBoard.getOwnGrid().placeShip(Ship
	{ GridPosition
	{ "A8" }, GridPosition
	{ "A11" } }), "Can place this illegal ship"); //Length = 2



	assertTrue2(myBoard.getOwnGrid().takeBlow(GridPosition
	{ "B1" }) == Shot::NONE, "This blow is a hit");
	assertTrue2(myBoard.getOwnGrid().takeBlow(GridPosition
	{ "E6" }) == Shot::HIT, "This blow is not a HIT");
	assertTrue2(myBoard.getOwnGrid().takeBlow(GridPosition
	{ "F6" }) == Shot::HIT, "This blow is not a HIT");
	assertTrue2(myBoard.getOwnGrid().takeBlow(GridPosition
		{ "G6" }) == Shot::SUNKEN, "This blow is not a HIT");

	myBoard.getOpponentGrid().shotResult(GridPosition
	{ "G5" }, Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition
	{ "D2" }, Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition
	{ "A1" }, Shot::HIT);
	myBoard.getOpponentGrid().shotResult(GridPosition
	{ "F5" }, Shot::SUNKEN);
	myBoard.getOpponentGrid().shotResult(GridPosition
	{ "G6" }, Shot::NONE);


	viewBoard.print();

}

