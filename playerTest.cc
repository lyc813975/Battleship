#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>

int main(){
	Player player;
	AIPlayer AIplayer;
	AIplayer.setShip();
	player.setShip();
	player.setOpponentBoard(AIplayer.getAddressofBoard());
	AIplayer.setOpponentBoard(player.getAddressofBoard());
	AIplayer.attack();
	player.attack();
}

