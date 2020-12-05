#include "Ship.h"

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
}

void Ship::setDirection(Direction d){
	this->direction = d;
}

void Ship::setLocation(Point p){
	this->location = p;
}

char Ship::getType() const{
	return this->type;
}

int Ship::getLenght() const{
	return this->lenght;
}

Direction Ship::getDirection() const{
	return this->direction;
}

Point Ship::getLocation() const{
	return this->location;
}
