#include "Point.h"
#include "Ship.h"
#include "Board.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>

int main(){
	Player player("me");
	AIPlayer AIplayer("CPU");
	AIplayer.setShip();
	player.setShip();
	player.setOpponentBoard(AIplayer.getAddressOfBoard());
	AIplayer.setOpponentBoard(player.getAddressOfBoard());
	AIplayer.attack();
	player.attack();
}

