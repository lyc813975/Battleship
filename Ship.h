#ifndef SHIP_H_
#define SHIP_H_
#include <utility>

enum Direction {Down = 0, Right};

class Ship{
	public:
		Ship(const char *);
		void setLocation(std::pair<char, int>);
		void setDirection(Direction);
		void decreaseHp();
		char *getType() const;
		int getLength() const;
		int getHp() const;
		Direction getDirection() const;
		std::pair<char, int> getLocation() const;
		void display() const;
		~Ship();
	private:
		char *type;
		int length;
		int hp;
		std::pair<char, int> location;
		Direction direction;
};

#endif // SHIP_H_
