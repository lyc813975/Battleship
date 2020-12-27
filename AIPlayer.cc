#include "AIPlayer.h"
#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

AIPlayer::AIPlayer(const char *playerName): Player(playerName){
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
	char temp;
	int row, column;
	do{
		row = rand()%10;
		column = rand()%10;
		opponentBoard->showPoint(row, column);
		temp = opponentBoard->getChar(row, column);
		if(temp == 'O'){
			opponentBoard->setChar(row, column, 'X');
			hit = false;
		}else{
			opponentBoard->setChar(row-'A', column, temp-'A'+'a');
			hit = true;
		}
	}while(hit);
}

AIPlayer::~AIPlayer(){
}
