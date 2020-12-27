#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include <utility>

class AIPlayer: public Player{
	public:
		AIPlayer(const char *);
		void setShip();
		std::pair<char, int> attack();
		~AIPlayer();
	private:
};

#endif // AIPLAYER_H_ 
