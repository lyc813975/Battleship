#include "Judge.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>
using namespace std;

Judge::Judge(): player1("you"), player2("CPU"){
}

void Judge::start(){
	player1.openBoard();
	bool cheat;
	cout << "open CPU's board?\n"
		<< "0: no, 1: yes\n";
	cin >> cheat;
	if(cheat)
		player2.openBoard();
	player1.setShip();
	player1.displayBoard();
	player2.setShip();
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
