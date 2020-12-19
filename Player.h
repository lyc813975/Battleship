#ifndef PLAYER_H_
#define PLAYER_H_

class Board;
class Ship;

class Player{
	public:
		Player();
		void setShip();
		void attack();
		~Player;
	private:
		static const char (*shipType)[5] = {"Aircraft", "BattleShip", "Cruiser", "Submarine", "Patorl"}
		static const int kShipQuantity = 5;
		Board myBoard;
		Board opponentBoard;
		Ship **ship;
};

#endif // PLAYER_H_
