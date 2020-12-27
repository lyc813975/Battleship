#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"
#include "Board.h"
#include "Ship.h"

class AIPlayer: public Player{
	public:
		AIPlayer(const char *);
		void setShip();
		void attack();
		~AIPlayer();
	private:
};

#endif // AIPLAYER_H_ 
