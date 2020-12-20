#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "Player.h"
#include <iostream>

int main(){
	Board board;
	Ship a('A');
	a.setLocation(Point('A', 1));
	a.setDirection(Down);
	Ship b('B');
	b.setLocation(Point('B', 1));
	b.setDirection(Down);
	Ship c('C');
	c.setLocation(Point('C', 1));
	c.setDirection(Down);
	Ship s('S');
	s.setLocation(Point('S', 1));
	s.setDirection(Down);
	Ship p('P');
	p.setLocation(Point('P', 1));
	p.setDirection(Down);
	board.setShip(a);
	board.setShip(b);
	board.setShip(c);
	board.setShip(s);
	board.setShip(p);
	board.display();
	Player player(board);
	player.setShip();
	player.attack();
}

