#include "AIPlayer.h"
#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

AIPlayer::AIPlayer(): Player(){
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
}
