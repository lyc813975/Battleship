#include "Player.h"
#include "board.h"
#include "Ship.h"
#include <iostream>
using namespace std;

Player::Player():{
	ship = new Ship*[kShipQuantity];
	for(int i = 0; i < kShipQuantity; ++i)
		ship[i] = new Ship(shipType[i][0]);
}

void Player::setShip(){
	Point p;
    int	d, s;
	int setShip = 0;
	bool set[kShipQuantity] = {false};
	while(setShip < kShipQuantity){
    	d = -1;
		cout << "Choose one ship to set.\n";
		do{
			for(int i = 0; i < kShipQuantity; ++i)
				if(!set[i])
					cout << i+1 << ") " << shipType[i] << '\n';
			cin >> s;
		}while(s > 5 || s <= 0 || set[s-1]);
		myBoard.display();
		cout << "Choose one point.\n";
		cin >> p;
		cout << "Choose direction:\n"
		do{
			cout << "1) Down, 2) Right\n";
			cin >> d;
		}while(d > 2 || s <= 0);

		ship[s-1].setLocation(p);
		ship[s-1].setDirection(Direction(d-1));
		if(myBoard.setShip(ship[s-1])){
			set[s-1] = true;
			++setShip;
			cout << shipType[s-1] " success to set.\n";
		}else{
			cout << shipType[s-1] " fail to set.\n";
		}
	}
}

void Player::attack(){
	bool hit;
	do{
		Point p;
		opponentBoard.display();
		cout << "Choose one point to attack\n";
		cin >> p;
		opponentBoard.showPoint(p);
		if(opponentBoard[p] == 'O'){
			opponentBoard[p] = 'X';
			hit = false;
		}else{
			hit = true;
		}
	}while(hit);
}

Player::~Player(){
	for(int i = 0; i < kShipQuantity; ++i)
		delete ship[i];
	delete ship;
}
