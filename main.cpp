/*! \mainpage
 * This is simulation of BattleShip game
 */
// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include"Ship.h"
#include "Board.h"
#include "ConsoleView.h"
#include "GridPosition.h"
#include "OpponentGrid.h"
#include "OwnGrid.h"
// Add more standard header files as required
// #include <string>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

void part1tests();
void part2tests();
void part3tests();

// Main program
int main(void)
{
	// TODO: Add your program code here
	cout << "BattleShip started." << endl << endl;

	Board myBoard(10, 10);

	Board board(10, 10);
	Ship ship1(GridPosition("B2"), GridPosition("B4"));
	Ship ship2(GridPosition("D4"), GridPosition("G4"));
	Ship ship3(GridPosition("F6"), GridPosition("F9"));
	board.getOwnGrid().placeShip(ship1);
	board.getOwnGrid().placeShip(ship2);
	board.getOwnGrid().placeShip(ship3);

	ConsoleView view(&board);
	view.print();

	part1tests();
	part2tests();
	part3tests();

	return 0;
}

//void assertTrue(bool condition, string failedMessage) {
//	if (!condition) {
//		cout << failedMessage << endl;
//	}
//	else{
//		cout << "Working!" << endl;
//	}
//}
//
//void part2tests(){
//	Board myBoard(10, 10);
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B2"},GridPosition{"B5"}}),
//			"Cannot place ship horizontally");//Length = 4
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E4"},GridPosition{"I4"}}),
//			"Cannot place ship vertically");//Length = 5
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"B7"},GridPosition{"D7"}}),
//			"Cannot place a ship of length 5");//Length = 3
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"A10"},GridPosition{"D10"}}),
//				"Cannot place a ship of length 5");//Length = 4
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E1"},GridPosition{"H1"}}),
//				"Cannot place this ship");//Length = 4
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E6"},GridPosition{"G6"}}),
//			"Cannot place this ship");//Length = 3
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F8"},GridPosition{"G8"}}),
//			"Can place this ship");//Length = 3
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"J8"},GridPosition{"J10"}}),
//			"Cannot place this ship");//Length = 3
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F10"},GridPosition{"G10"}}),
//			"Can place this ship");//Length = 3
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"H6"},GridPosition{"H7"}}),
//				"Cannot place this ship");//Length = 2
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"J1"},GridPosition{"J2"}}),
//				"Cannot place this ship");//Length = 2
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"H10"},GridPosition{"I10"}}),
//				"Can place this ship");//Length = 2
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"J1"},GridPosition{"J3"}}),
//				"Can place the ship in blocked area");
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"J6"},GridPosition{"I6"}}),
//					"Can place the ship in blocked area");//Length = 2
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"C8"},GridPosition{"C7"}}),
//					"Cannot place the ship of length 2");//Length = 2
//	assertTrue(!myBoard.getOwnGrid().placeShip(Ship{GridPosition{"E1"},GridPosition{"D1"}}),
//						"Can place this illegal ship");//Length = 2
//	assertTrue(myBoard.getOwnGrid().placeShip(Ship{GridPosition{"F1"},GridPosition{"D1"}}),
//						"Can place the ship in blocked area");//Length = 2
//
//	ConsoleView viewBoard(&myBoard);
//	viewBoard.print();
//}
