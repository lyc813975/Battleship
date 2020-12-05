#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point{
	public:
		Point();
		Point(char, int);
		int getRow() const;
		int getColumn() const;
	private:
		int row;
		int column;
	friend std::istream &operator>>(std::istream &, Point &);
};

#endif // POINT_H_
