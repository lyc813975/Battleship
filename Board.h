#ifndef BOARD_H_
#define BOARD_H_

class Ship;

class Board{
	public:
		Board();
		void init();
		char getChar(int, char) const;
		void setChar(int, char, char);
		bool setShip(Ship);
		void showPoint(int, char);
		void showAll();
		void display();
		~Board();

	private:
		bool isInside(int, int);
		const static int kBoardHeight = 10;
		const static int kBoardWidth = 10;
		const static int kColumnStart = 1;
		const static char kRowStart = 'A';
		char **board;
		bool **hide;
};

#endif // BOARD_H_
