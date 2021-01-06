#ifndef JUDGE_H_
#define JUDGE_H_
#include "Player.h"
#include "AIPlayer.h"

class Judge{
	public:
		Judge(const char *, const char *);
		void start();
		void oneGame();
		~Judge();
	private:
		char *player1Name;
		char *player2Name;
		Player player1;
		AIPlayer player2;
};

#endif // JUDGE_H_
