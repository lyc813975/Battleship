#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

Player::Player(const char *playerName){
	name = new char [strlen(playerName)+1];
	strcpy(name, playerName);

	ship = new Ship *[kShipQuantity];
	ship[0] = new Ship("Aircraft");
	ship[1] = new Ship("Battleship");
	ship[2] = new Ship("Crusier");
	ship[3] = new Ship("Submarine");
	ship[4] = new Ship("Patorl");
	
	repeat = new bool *[10];
	for(int i = 0; i < 10; ++i){
		repeat[i] = new bool [10];
		memset(repeat[i], false, 10);
	}
}

void Player::openBoard(){
	board.showAll();
}

void Player::displayBoard(){
	cout << name << endl;
	board.display();
}

bool Player::displayShip(){
	int totalHp = 0;
	cout << name << endl;
	for(int i = 0; i < kShipQuantity; ++i){
		totalHp += ship[i]->getHp();
		ship[i]->display();
	}
	return totalHp == 0;
}

void Player::setShip(){
	pair<char, int> position('\0', -1);
	int	direction = -1 , s = -1;
	int setShip = 0;
	bool set[kShipQuantity] = {false};
	while(setShip < kShipQuantity){
		this->displayBoard();
		// may add reset ship
		cout << "Choose one ship to set.\n";
		do{
			if(cin.fail()){
				cin.clear();
				cin.ignore();
			}
			for(int i = 0; i < kShipQuantity; ++i)
				if(!set[i])
					cout << i+1 << ") " << ship[i]->getType() << '\n';
			cin >> s;
		}while(s > 5 || s <= 0 || set[s-1]);
		
		cout << "Choose one point.\n";
		do{
			if(cin.fail()){
				cin.clear();
				cin.ignore();
			}
			cout <<	"[A to J] [1 to 10]\n";
			cin >> position.first >> position.second;
		}while(position.first < 'A' || position.first > 'J' ||
				position.second < 1 || position.second > 10);

		cout << "Choose direction:\n";
		do{
			if(cin.fail()){
				cin.clear();
				cin.ignore();
			}
			cout << "1) Down, 2) Right\n";
			cin >> direction;
		}while(direction > 2 || direction <= 0);

		ship[s-1]->setLocation(position);
		ship[s-1]->setDirection(Direction(direction-1));
		if(board.setShip(*ship[s-1])){
			set[s-1] = true;
			++setShip;
			cout << ship[s-1]->getType() << " success to set.\n";
		}else{
			cout << ship[s-1]->getType() << " fail to set.\n";
		}
	}
}

pair<char, int>  Player::attack(){
	pair<char, int> p;
	cout << "Choose one point to attack\n";
	do{
		if(cin.fail()){
			cin.clear();
			cin.ignore();
		}
		cout <<	"[A to J] [1 to 10]\n";
		cin >> p.first >> p.second;
		if(repeat[p.first-'A'][p.second-1])
			cout << "This point has been attacked\n";
	}while(p.first < 'A' || p.first > 'J' || p.second < 1 || p.second > 10 ||
			repeat[p.first-'A'][p.second-1]);
	repeat[p.first-'A'][p.second-1] = true;
	return p;
}

char Player::beAttcked(pair<char, int> p){
	board.showPoint(p.first, p.second);
	char s = board.getChar(p.first, p.second);
	if(s == 'O'){
		board.setChar(p.first, p.second, 'X');
		cout << "miss...\n";
	}else{
		cout << name << "'s ";
		for(int i = 0; i < kShipQuantity; ++i)
			if(s == ship[i]->getType()[0]){
				ship[i]->decreaseHp();
				cout << ship[i]->getType();
				break;
			}
		cout << " was hit!!!\n";
		board.setChar(p.first, p.second, s-'A'+'a');
	}
	return s;
}

Player::~Player(){
	for(int i = 0; i < kShipQuantity; ++i){
		delete ship[i];
	}
	for(int i = 0; i < 10; ++i)
		delete [] repeat[i];

	delete [] ship;
	delete [] name;
	delete [] repeat;
}
