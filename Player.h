#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include "Ship.h"

class Player{
	public:
		Player(const char *);
		Board *getAddressofBoard();
		void setOpponentBoard(Board *);
		void displayBoard();
		bool displayShip();
		void setShip();
		void attack();
		~Player();
	protected:
		static const int kShipQuantity = 5;
		char **shipType;
		char *name;
		Board myBoard;
		Board *opponentBoard;
		Ship **ship;
};

#endif // PLAYER_H_
