#ifndef PLAYER_H_
#define PLAYER_H_

#include "Board.h"
#include "Ship.h"

class Player{
	public:
		Player(Board &);
		void setShip();
		void attack();
		~Player();
	private:
		static const int kShipQuantity = 5;
		char **shipType;
		Board myBoard;
		Board &opponentBoard;
		Ship **ship;
};

#endif // PLAYER_H_
