#include "AIPlayer.h"
#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

AIPlayer::AIPlayer(){
	shipType = new char *[kShipQuantity];
	for(int i = 0; i < kShipQuantity; ++i)
		shipType[i] = new char [16];
	strcpy(shipType[0],	"Aircraft");
	strcpy(shipType[1],	"Battleship");
	strcpy(shipType[2],	"Crusier");
	strcpy(shipType[3],	"Submarine");
	strcpy(shipType[4],	"Patorl");
	ship = new Ship *[kShipQuantity];
	for(int i = 0; i < kShipQuantity; ++i)
		ship[i] = new Ship(shipType[i][0]);
}

Board *AIPlayer::getAddressofBoard(){
	return &myBoard;
}

void AIPlayer::setOpponentBoard(Board *b){
	opponentBoard = b;
}

void AIPlayer::setShip(){
	int row, column, direction;
	int setShip = 0;
	while(setShip < kShipQuantity){
		row = rand()%10 + 'A';
		column = rand()%10;
		direction = rand()%2;
		ship[setShip]->setLocation(row, column);
		ship[setShip]->setDirection(Direction(direction));
		if(myBoard.setShip(*ship[setShip]))
			++setShip;
	}
}

void AIPlayer::attack(){
	bool hit;
	int row, column;
	do{
		row = rand()%10;
		column = rand()%10;
		opponentBoard->showPoint(row, column);
		if(opponentBoard->getChar(row, column) == 'O'){
			opponentBoard->setChar(row, column, 'X');
			hit = false;
		}else{
			hit = true;
		}
	}while(hit);
}

AIPlayer::~AIPlayer(){
	for(int i = 0; i < kShipQuantity; ++i)
		delete ship[i];
	delete ship;
}
