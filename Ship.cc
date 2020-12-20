#include "Ship.h"
#include "Point.h"
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
			lenght = 5;
			break;
		case 'B':
			lenght = 4;
			break;
		case 'C':
			lenght = 3;
			break;
		case 'S':
		case 'P':
			lenght = 2;
			break;
	}
	hp = lenght;
}

void Ship::setDirection(Direction d){
	this->direction = d;
}

void Ship::setLocation(Point p){
	this->location = p;
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

int Ship::getLenght() const{
	return this->lenght;
}

int Ship::getHp() const{
	return this->hp;
}

Direction Ship::getDirection() const{
	return this->direction;
}

Point Ship::getLocation() const{
	return this->location;
}

std::ostream &operator<<(std::ostream &os, Ship s){
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
	for(;i < s.lenght; ++i)
		os << '-';

	return os;
}
