#include "Ship.h"
#include <iostream>
using namespace std;

/*
 *
 * A: Aircraft carrier holds 5 blocks
 * B: Battleship holds 4 blocks
 * C: Cruiser holds 3 blocks
 * S: Submarine holds 2 blocks
 * P: Patorl boat bolds 2 blocks
 *
 */

Ship::Ship():type(' '){
}

Ship::Ship(char t):type(t){
	switch(type){
		case 'A':
			length = 5;
			break;
		case 'B':
			length = 4;
			break;
		case 'C':
			length = 3;
			break;
		case 'S':
		case 'P':
			length = 2;
			break;
	}
	hp = length;
}

void Ship::setDirection(Direction d){
	this->direction = d;
}

void Ship::setLocation(char i, int j){
	this->row = i;
	this->column = j;
}

void Ship::decreaseHp(){
	if(hp > 0)
		--hp;
}

char Ship::getType() const{
	return this->type;
}

int Ship::getLength() const{
	return this->length;
}

int Ship::getHp() const{
	return this->hp;
}

Direction Ship::getDirection() const{
	return this->direction;
}

char Ship::getRow() const{
	return this->row;
}

int Ship::getColumn() const{
	return this->column;
}

void Ship::display() const{
	cout << '\t';
	switch(type){
		case 'A':
			cout << "Aircraft: ";
			break;
		case 'B':
			cout << "Battleship: ";
			break;
		case 'C':
			cout << "Cruiser: ";
			break;
		case 'S':
			cout << "Submarine: ";
			break;
		case 'P':
			cout << "Patorl: ";
			break;
	}

	int i;
	for(i = 0; i < hp; ++i)
		cout << '*';
	for(;i < length; ++i)
		cout << '-';
	cout << '\n';
}
