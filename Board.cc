#include "Ship.h"
#include "Board.h"
#include "AnsiPrint.h"
#include <iostream>
#include <cctype>
#include <utility>
#include <iomanip>
using namespace std;

Board::Board(){
	board = new char* [kBoardHeight];
	hide = new bool* [kBoardHeight];
	for(int i = 0; i < kBoardHeight; ++i){
		board[i] = new char [kBoardWidth];
		hide[i] = new bool [kBoardWidth];
	}
	init();
}

void Board::init(){
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j){
			// The char O represnt initial state
			board[i][j] = 'O';
			hide[i][j] = true;
		}
}

char Board::getChar(int i, char j) const{
	return board[i-kRowStart][j-kColumnStart];
}

void Board::setChar(int i, char j, char c){
	 board[i-kRowStart][j-kColumnStart] = c;
}

bool Board::setShip(Ship &ship){
	// The start position of ship need to be in boad
	int str_i = int((ship.getLocation()).first - kRowStart);
	int str_j = (ship.getLocation().second) - kColumnStart;
	if(!isInside(str_i, str_j))
		return false;

	if(ship.getDirection() == Down){
		// The end position of ship need, too
		if(!isInside(str_i+ship.getLength()-1, str_j))
			return false;
		// Betweem start and end, Three need to be blank without other ships
		for(int i = str_i; i < str_i+ship.getLength(); ++i)
			if(board[i][str_j] != 'O')
				return false;

		for(int i = str_i; i < str_i+ship.getLength(); ++i)
			board[i][str_j] = ship.getType()[0];
	}else{
		// The end position of ship need, too
		if(!isInside(str_i, str_j+ship.getLength()-1))
			return false;
		// Betweem start and end, Three need to be blank without other ships
		for(int j = str_j; j < str_j+ship.getLength(); ++j)
			if(board[str_i][j] != 'O')
				return false;

		for(int j = str_j; j < str_j+ship.getLength(); ++j)
			board[str_i][j] = ship.getType()[0];
	}
	return true;
}

void Board::showPoint(int i, char j){
	hide[i-kRowStart][j-kColumnStart] = false;
}

void Board::showAll(){
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j)
			hide[i][j] = false;
}

void Board::display(){
	for(int i = 0; i < kBoardHeight; ++i){
		cout << '\t';
		cout << setw(3) << char(kRowStart+i);
		for(int j = 0; j < kBoardWidth; ++j){
			AnsiPrint(' ', nochange, blue, false, false);
			// unknown and blank are white
			if(hide[i][j])
				AnsiPrint('?', white, blue, false, false);
			else if(board[i][j] == 'O')
				AnsiPrint(board[i][j], white, blue, false, false);
			// hit is black
			else if(islower(board[i][j]))
				AnsiPrint(board[i][j], black, blue, false, false);
			// miss is red
			else if(board[i][j] == 'X')
				AnsiPrint(board[i][j], red, blue, false, false);
			// ship is green
			else
				AnsiPrint(board[i][j], green, blue, false, false);

			AnsiPrint(' ', nochange, blue, false, false);
		}
		cout << '\n';
	}
	cout << '\t';
	cout << "  ";
	for(int i = 0; i < 10; ++i)
		cout << setw(3) << i+kColumnStart;
	cout << "\n";
}

Board::~Board(){
	for(int i = 0; i < kBoardHeight; ++i){
		// only if AI win 
		// Error:free(): invalid next size(fast)
		// why????
		//	delete hide[i];
		//	delete board[i];
	}
	delete board;
	delete hide;
}

bool Board::isInside(int i, int j){
	if(i >= 0 && j >= 0 && i < kBoardHeight && j < kBoardWidth)
		return true;
	return false;
}
