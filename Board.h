#ifndef BOARD_H_
#define BOARD_H_

class Ship;
class Point;

class Board{
	public:
		Board();
		void init();
		bool setChar(Point, char);
		bool setShip(Ship);
		void displayBoard();
		~Board();

	private:
		bool isInside(Point);
		bool isInside(int, int);
		const static int kBoardHeight = 10;
		const static int kBoardWidth = 10;
		char **board;
};

#endif // BOARD_H_
