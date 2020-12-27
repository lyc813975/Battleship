#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"
#include "Board.h"
#include "Ship.h"

class AIPlayer: public Player{
	public:
		AIPlayer();
		virtual void setShip();
		virtual void attack();
		virtual ~AIPlayer();
	private:
};

#endif // AIPLAYER_H_
