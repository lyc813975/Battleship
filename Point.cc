#include "Point.h"
#include <iostream>
using namespace std;

// 10x10 board
// row from A to J
// column form 0 to 9

Point::Point():
	row(0), column(0){
	}

Point::Point(char i, int j):
	row(int(i-'A')), column(j){
	}

int Point::getRow() const{
	return row;
}

int Point::getColumn() const{
	return column;
}

istream &operator>>(istream &is, Point &p){
	char i, j;
	is >> i >> j;
	while(i > 'J' || i < 'A' ||  j < '0' || j > '9'){
		cout << "Invalid position\n"
			<< "row: A to J\n"
			<< "column: 0 to 9\n";
		is >> i >> j;
	}	
	p.row = int(i - 'A');
	p.column = int(j - '0');
	return is;
}
