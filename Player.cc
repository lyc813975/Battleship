#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
#include <cstring>
using namespace std;

Player::Player(){
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
	myBoard.showAll();
}

Board *Player::getAddressofBoard(){
	return &myBoard;
}

void Player::setOpponentBoard(Board *b){
	opponentBoard = b;
}

void Player::setShip(){
	char row;
    int	d, s, column;
	int setShip = 0;
	bool set[kShipQuantity] = {false};
	while(setShip < kShipQuantity){
		myBoard.display();
		/* input flush or something mey need 
		 * when input error occur
		 */

		cout << "Choose one ship to set.\n";
		do{
			for(int i = 0; i < kShipQuantity; ++i)
				if(!set[i])
					cout << i+1 << ") " << shipType[i] << '\n';
			cin >> s;
		}while(s > 5 || s <= 0 || set[s-1]);
		cout << "Choose one point.\n";
		do{
	    	cout <<	"[A to J] [0 to 9]\n";
			cin >> row >> column;
		}while(row < 'A' || row > 'J' || column < 0 || column > 9);
		cout << "Choose direction:\n";
		do{
			cout << "1) Down, 2) Right\n";
			cin >> d;
		}while(d > 2 || s <= 0);

		ship[s-1]->setLocation(row, column);
		ship[s-1]->setDirection(Direction(d-1));
		if(myBoard.setShip(*ship[s-1])){
			set[s-1] = true;
			++setShip;
			cout << shipType[s-1] << " success to set.\n";
		}else{
			cout << shipType[s-1] << " fail to set.\n";
		}
	}
}

void Player::attack(){
	bool hit;
	char row;
	int column;
	do{
		opponentBoard->display();
		cout << "Choose one point to attack\n";
		do{
	    	cout <<	"[A to J] [0 to 9]\n";
			cin >> row >> column;
		}while(row < 'A' || row > 'J' || column < 0 || column > 9);
		opponentBoard->showPoint(row-'A', column);
		if(opponentBoard->getChar(row-'A', column) == 'O'){
			opponentBoard->setChar(row-'A', column, 'X');
			hit = false;
			cout << "miss...\n";
		}else{
			hit = true;
			cout << "hit!!!\n";
		}
	}while(hit);
}

Player::~Player(){
	for(int i = 0; i < kShipQuantity; ++i)
		delete ship[i];
	delete ship;
}
