#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>

int main(){
	//Board board;
	//Ship a('A');
	//a.setLocation('A', 0);
	//a.setDirection(Down);
	//Ship b('B');
	//b.setLocation('A', 1);
	//b.setDirection(Down);
	//Ship c('C');
	//c.setLocation('A', 2);
	//c.setDirection(Down);
	//Ship s('S');
	//s.setLocation('A', 3);
	//s.setDirection(Down);
	//Ship p('P');
	//p.setLocation('A', 4);
	//p.setDirection(Down);
	//board.setShip(a);
	//board.setShip(b);
	//board.setShip(c);
	//board.setShip(s);
	//board.setShip(p);
	//board.display();
	//Player player;
	//player.setOpponentBoard(&board);
	Player player;
	AIPlayer AIplayer;
	AIplayer.setShip();
	player.setShip();
	player.setOpponentBoard(AIplayer.getAddressofBoard());
	AIplayer.setOpponentBoard(player.getAddressofBoard());
	AIplayer.attack();
	player.attack();
}

