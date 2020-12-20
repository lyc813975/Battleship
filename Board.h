#ifndef BOARD_H_
#define BOARD_H_

class Ship;
class Point;

class Board{
	public:
		Board();
		void init();
		char& operator[](Point);
		char operator[](Point) const;
		bool setShip(Ship);
		void showPoint(Point);
		void showAll();
		void display();
		~Board();

	private:
		bool isInside(Point);
		bool isInside(int, int);
		const static int kBoardHeight = 10;
		const static int kBoardWidth = 10;
		char **board;
		bool **hide;
};

#endif // BOARD_H_
