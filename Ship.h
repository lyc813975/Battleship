#ifndef SHIP_H_
#define SHIP_H_

#include <iostream>

enum Direction {Down = 0, Right};
class Point;

class Ship{
	public:
		Ship();
		Ship(char);
		void setLocation(Point);
		void setDirection(Direction);
		void setHp(int);
		void decreaseHp();
		char getType() const;
		int getLenght() const;
		int getHp() const;
		Point getLocation() const;
		Direction getDirection() const;
		friend std::ostream &operator<<(std::ostream &, Ship);
	private:
		const char type;
		int lenght;
		int hp
		Point location;
		Direction direction;
};

#endif // SHIP_H_
