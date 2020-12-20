#ifndef POINT_H_
#define POINT_H_

class Point{
	public:
		Point();
		Point(char, int);
		int getRow() const;
		int getColumn() const;
	private:
		int row;
		int column;
};

#endif // POINT_H_
