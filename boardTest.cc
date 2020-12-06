#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>

int main(){
	Board board;
	board.displayBoard();
	std::cout << '\n';

	board[Point('A', 0)] = 'A';
	board[Point('B', 0)] = 'B';
	board[Point('C', 0)] = 'C';
	board[Point('D', 0)] = 'S';
	board[Point('E', 0)] = 'P';
	board[Point('F', 0)] = 'X';
	board.displayBoard();
	std::cout << '\n';

	Ship a('A');
	a.setLocation(Point('C', 1));
	a.setDirection(Down);
	Ship c('C');
	c.setLocation(Point('C', 3));
	c.setDirection(Right);
	Ship s('S');
	s.setLocation(Point('D', 9));
	s.setDirection(Right);
	Ship b('B');
	b.setLocation(Point('B', 4));
	b.setDirection(Down);
	if(board.setShip(a))
		std::cout << "\tAircarft carrier successed to set.\n";
	else
		std::cout << "\tAircarft carrier failed to set.\n";
	if(board.setShip(c))
		std::cout << "\tCruiser successed to set.\n";
	else
		std::cout << "\tCrusier failed to set.\n";
	if(board.setShip(b))
		std::cout << "\tBattleship successed to set.\n";
	else
		std::cout << "\tBattleship failed to set\n";
	if(board.setShip(s))
		std::cout << "\tSubmarine successed to set.\n";
	else
		std::cout << "\tSubmarine failed to set\n";

	board.displayBoard();
	std::cout << std::endl;
}
