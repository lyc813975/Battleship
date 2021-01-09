#include "Ship.h"
#include <iostream>
#include <utility>
#include <cstring>
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

Ship::Ship(const char *t){
	type = new char [strlen(t)+1];
	strcpy(type, t);

	switch(type[0]){
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

void Ship::setLocation(pair<char, int> p){
	this->location = p;
}

void Ship::decreaseHp(){
	if(hp > 0)
		--hp;
}

char *Ship::getType() const{
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


pair<char, int> Ship::getLocation() const{
	return this-> location;
}

void Ship::display() const{
	cout << '\t' << type << ": ";
	int i;
	for(i = 0; i < hp; ++i)
		cout << '*';
	for(;i < length; ++i)
		cout << '-';
	cout << '\n';
}

Ship::~Ship(){
	delete [] type;
}
