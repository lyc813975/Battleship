#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include "Point.h"
#include <iostream>
using namespace std;

Player::Player(Board &b): opponentBoard(b){
	shipType = new char *[kShipQuantity]{
		"Aircraft", "BattleShip", "Crusier", "Submarine", "Patrol"};
	ship = new Ship *[kShipQuantity];
	for(int i = 0; i < kShipQuantity; ++i)
		ship[i] = new Ship(shipType[i][0]);
	myBoard.showAll();
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

		ship[s-1]->setLocation(Point(row, column));
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
	Point p;
	bool hit;
	char row;
	int column;
	do{
		opponentBoard.display();
		cout << "Choose one point to attack\n";
		do{
	    	cout <<	"[A to J] [0 to 9]\n";
			cin >> row >> column;
		}while(row < 'A' || row > 'J' || column < 0 || column > 9);
		p = Point(row, column);
		opponentBoard.showPoint(p);
		if(opponentBoard[p] == 'O'){
			opponentBoard[p] = 'X';
			hit = false;
			cout << "hit!!!\n";
		}else{
			hit = true;
			cout << "miss...\n";
		}
	}while(hit);
}

Player::~Player(){
	for(int i = 0; i < kShipQuantity; ++i)
		delete ship[i];
	delete ship;
}
