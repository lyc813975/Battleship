#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "AnsiPrint.h"
#include <iostream>
#include <cctype>
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

char Board::getChar(int i, int j) const{
	return board[i][j];
}

void Board::setChar(int i, int j, char c){
	 board[i][j] = c;
}

bool Board::setShip(Ship ship){
	// The start position of ship need to be in boad
	int str_i = ship.getLocationI();
	int str_j = ship.getLocationJ();
	if(!isInside(str_i, str_j))
		return false;

	if(ship.getDirection() == Down){
		// The end position of ship need, too
		if(!isInside(str_i+ship.getLenght()-1, str_j))
			return false;
		// Betweem start and end, Three need to be blank without other ships
		for(int i = str_i; i < str_i+ship.getLenght(); ++i)
			if(board[i][str_j] != 'O')
				return false;

		for(int i = str_i; i < str_i+ship.getLenght(); ++i)
			board[i][str_j] = ship.getType();
	}else{
		// The end position of ship need, too
		if(!isInside(str_i, str_j+ship.getLenght()-1))
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

void Board::showPoint(int i, int j){
	hide[i][j] = false;
}

void Board::showAll(){
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j)
			hide[i][j] = false;
}

void Board::display(){
	color font;
	for(int i = 0; i < kBoardHeight; ++i){
		cout << setw(3) << char('A'+i);
		for(int j = 0; j < kBoardWidth; ++j){
			AnsiPrint(' ', nochange, blue, false, false);
			if(hide[i][j]){
				AnsiPrint('?', red, blue, false, false);
			}else if(board[i][j] == 'X'){
				font = red;
			}else if(board[i][j] == 'O'){
				font = nochange;
			}else if(isupper(board[i][j])){
				font = green;
			}else{
				font = black;
			}
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
	for(int i = 0; i < kBoardHeight; ++i){
		delete [] hide[i];
		delete [] board[i];
	}
	delete [] board;
	delete [] hide;
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
