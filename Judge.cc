#include "Judge.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>
using namespace std;

Judge::Judge(): player1("you"), player2("CPU"){
}

void Judge::start(){
	player1.openBoard();
	player2.openBoard();
	player1.setShip();
	player1.displayBoard();
	player2.setShip();
	player1.setOpponentBoard(player2.getAddressOfBoard());
	player2.setOpponentBoard(player1.getAddressOfBoard());
}

void Judge::oneGame(){
	bool end = false;
	while(true){
		player2.displayBoard();
		player2.displayShip();
		while(!end && player2.beAttcked(player1.attack())){
			player2.displayBoard();
			end = player2.displayShip();
		}
		if(end){
			cout << "player1 win\n";//player1 win
			break;
		}
		player1.displayBoard();
		player1.displayShip();
		while(!end && player1.beAttcked(player2.attack())){
			player1.displayBoard();
			end = player1.displayShip();
		}
		if(end){
			cout << "player2 win\n";//player1 win
			break;
		}
	}
}

Judge::~Judge(){
}
