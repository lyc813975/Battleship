#ifndef JUDGE_H_
#define JUDGE_H_
#include "Player.h"
#include "AIPlayer.h"

class Judge{
	public:
		Judge();
		void start();
		void oneGame();
		~Judge();
	private:
		Player player1;
		AIPlayer player2;
};

#endif // JUDGE_H_
