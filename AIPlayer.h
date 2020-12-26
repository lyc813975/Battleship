#ifndef AIPAYER_H_
#define AIPLAYER_H_

#include "Board.h"
#include "Ship.h"

class AIPlayer{
	public:
		AIPlayer();
		Board *getAddressofBoard();
		void setOpponentBoard(Board *);
		void setShip();
		void attack();
		~AIPlayer();
	private:
		static const int kShipQuantity = 5;
		char **shipType;
		Board myBoard;
		Board *opponentBoard;
		Ship **ship;
};

#endif // AIPLAYER_H_
