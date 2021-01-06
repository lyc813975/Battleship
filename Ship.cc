#include "Ship.h"
#include <iostream>

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
	this->location_i = i - 'A';
	this->location_j = j;
}

void Ship::setHp(int h){
	this->hp = h;
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

int Ship::getLocationI() const{
	return this->location_i;
}

int Ship::getLocationJ() const{
	return this->location_j;
}

std::ostream &operator<<(std::ostream &os, Ship s){
	os << '\t';
	switch(s.type){
		case 'A':
			os << "Aircraft: ";
			break;
		case 'B':
			os << "Battleship: ";
			break;
		case 'C':
			os << "Cruiser: ";
			break;
		case 'S':
			os << "Submarine: ";
			break;
		case 'P':
			os << "Patorl: ";
			break;
	}

	int i;
	for(i = 0; i < s.hp; ++i)
		os << '*';
	for(;i < s.length; ++i)
		os << '-';

	return os;
}
