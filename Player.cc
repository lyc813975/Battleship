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
    	d = -1, s = -1;
		cout << "Choose one ship to set.\n";
		while(s > 5 || s <= 0){
			for(int i = 0; i < kShipQuantity; ++i)
				if(!set[i])
					cout << i+1 << ") " << shipType[i] << '\n';
			cin >> s;
		}
		myBoard.display();
		cout << "Choose one point.\n";
		cin >> p;
		while(d > 2 || s <= 0){
			cout << "Choose direction:\n"
				<< "1) Down, 2) Right\n";
			cin >> d;
		}

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
	bool hit = true;
	while(hit){
		Point p;
		opponentBoard.display();
		cout << "Choose one point to attack\n";
		cin >> p;
		/*
		 * if(miss)
		 *     hit = false;
		 */
	}
}

Player::~Player(){
	for(int i = 0; i < kShipQuantity; ++i)
		delete ship[i];
	delete ship;
}
