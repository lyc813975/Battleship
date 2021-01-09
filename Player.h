#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include "Ship.h"
#include <utility>

class Player{
	public:
		Player(const char *);
		void openBoard();
		void displayBoard();
		bool displayShip();
		void setShip();
		std::pair<char, int> attack();
		char beAttcked(std::pair<char, int>);
		~Player();
	protected:
		static const int kShipQuantity = 5;
		char *name;
		bool **repeat;
		Board board;
		Ship **ship;
};

#endif // PLAYER_H_
