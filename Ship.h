#ifndef SHIP_H_
#define SHIP_H_

#include <iostream>

enum Direction {Down = 0, Right};

class Ship{
	public:
		Ship();
		Ship(char);
		void setLocation(char, int);
		void setDirection(Direction);
		void decreaseHp();
		char getType() const;
		int getLength() const;
		int getHp() const;
		char getRow() const;
		int getColumn() const;
		Direction getDirection() const;
		void display() const;
	private:
		const char type;
		int length;
		int hp;
		char row;
		int column;
		Direction direction;
};

#endif // SHIP_H_
