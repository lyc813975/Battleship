#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include <utility>

class AIPlayer: public Player{
	public:
		inline int abs(int);
		AIPlayer(const char *);
		void setShip();
		std::pair<char, int> attack();
		void determine(char, std::pair<char, int>);
		~AIPlayer();
	private:
		void count(int, int, int, int);
		void miss(int, int, int, int);
		void hit(int, int, int, int);
		int sum();
		static const int kBoardHeight = 10;
		static const int kBoardWidth = 10;
		int ***solution;
		int **sumSol;
};

#endif // AIPLAYER_H_ 
