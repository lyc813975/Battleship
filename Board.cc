#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "AnsiPrint.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

Board::Board(){
	board = new char* [kBoardHeight];
	for(int i = 0; i < kBoardHeight; ++i)
		board[i] = new char [kBoardWidth];
	init();
}

void Board::init(){
	for(int i = 0; i < kBoardHeight; ++i)
		// The charO represnt initial state
		memset(board[i], 'O', kBoardWidth);
}

char& Board::operator[](Point p){
	return board[p.getRow()][p.getColumn()];
}

char Board::operator[](Point p) const{
	return board[p.getRow()][p.getColumn()];
}

bool Board::setShip(Ship ship){
	// The start position of ship need to be in boad
	Point str = ship.getLocation();
	if(!isInside(str))
		return false;

	int str_i = str.getRow(), str_j = str.getColumn();
	
	if(ship.getDirection() == Down){
		// The end position of ship need, too
		if(!isInside(str_i+ship.getLenght(), str_j))
			return false;
		// Betweem start and end, Three need to be blank without other ships
		for(int i = str_i; i < str_i+ship.getLenght(); ++i)
			if(board[i][str_j] != 'O')
				return false;

		for(int i = str_i; i < str_i+ship.getLenght(); ++i)
			board[i][str_j] = ship.getType();
	}else{
		// The end position of ship need, too
		if(!isInside(str_i, str_j+ship.getLenght()))
			return false;
		// Betweem start and end, Three need to be blank without other ships
		for(int j = str_j; j < str_j+ship.getLenght(); ++j)
			if(board[str_i][j] != 'O')
				return false;

		for(int j = str_j; j < str_j+ship.getLenght(); ++j)
			board[str_i][j] = ship.getType();
	}
	return true;
}

void Board::displayBoard(){
	color font;
	for(int i = 0; i < kBoardHeight; ++i){
		cout << setw(3) << char('A'+i);
		for(int j = 0; j < kBoardWidth; ++j){
			switch(board[i][j]){
				// Aircraft carrier
				case 'A':
					font = green;
					break;
				// Battleship
				case 'B':
					font = yellow;
					break;
				// Cruiser
				case 'C':
					font = pink;
					break;
				// Submarine
				case 'S':
					font = cyan;
					break;
				// Patorl boat
				case 'P':
					font = nochange;
					break;
				// missed
				case 'X':
					font = red;
					break;
				// ...
				default:
					font = black;
					break;
			}
			AnsiPrint(' ', nochange, blue, false, false);
			AnsiPrint(board[i][j], font, blue, false, false);
			AnsiPrint(' ', nochange, blue, false, false);
		}
		cout << '\n';
	}
	cout << "  ";
	for(int i = 0; i < 10; ++i)
		cout << setw(3) << i;
	cout << "\n";
}

Board::~Board(){
	for(int i = 0; i < kBoardHeight; ++i)
		delete [] board[i];
	delete [] board;
}

bool Board::isInside(Point p){
	int i = p.getRow();
	int j = p.getColumn();
	if(i >= 0 && j >= 0 && i < kBoardHeight && j < kBoardWidth)
		return true;
	return false;
}

bool Board::isInside(int i, int j){
	if(i >= 0 && j >= 0 && i < kBoardHeight && j < kBoardWidth)
		return true;
	return false;
}
