#ifndef SHIP_H_
#define SHIP_H_

#include "Point.h"

enum Direction {Down = 0, Right};

class Ship{
	public:
		Ship();
		Ship(char);
		void setLocation(Point);
		void setDirection(Direction);
		char getType() const;
		int getLenght() const;
		Point getLocation() const;
		Direction getDirection() const;
	private:
		const char type;
		int lenght;
		Point location;
		Direction direction;
};

#endif // SHIP_H_
