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
		void setHp(int);
		void decreaseHp();
		char getType() const;
		int getLength() const;
		int getHp() const;
		int getLocationI() const;
		int getLocationJ() const;
		Direction getDirection() const;
		friend std::ostream &operator<<(std::ostream &, Ship);
	private:
		const char type;
		int length;
		int hp;
		int location_i;
		int location_j;
		Direction direction;
};

#endif // SHIP_H_
