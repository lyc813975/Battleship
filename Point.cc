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
	char temp;
	is >> temp >> p.column;
	while(temp > 'J' || temp < 'A' ||  p.column < 0 || p.column > 9){
		cout << "Invalid position\n"
			<< "row: A to J\n"
			<< "column: 0 to 9\n";
		is >> temp >> p.column;
	}	
	p.row = int(temp - 'A');
	return is;
}
