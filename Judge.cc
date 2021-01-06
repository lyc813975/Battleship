#include "Judge.h"
#include "Player.h"
#include "AIPlayer.h"
#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

Judge::Judge(const char *name1, const char *name2): player1(name1), player2(name2){
	player1Name = new char [strlen(name1)+1];
	strcpy(player1Name, name1);
	player2Name = new char [strlen(name2)+1];
	strcpy(player2Name, name2);
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
	pair<char, int> position;
	char ship;
	while(true){
		while(!end){
			player2.displayBoard();
			position = player1.attack();
			cout << player1Name << " attack "<< position.first << ' ' << position.second << '\n';
			// return the ship in the postion
			ship = player2.beAttcked(position);
			// return if the sum of the hp of the ships is equal to 0
			end = player2.displayShip();
			if(ship == 'O'){
				cout << "miss...\n";
				break;
			}
		}
		if(end){
			cout << player1Name <<  " win\n";//player1 win
			break;
		}
		cout << "==============================================================\n";
		while(!end){
			player1.displayBoard();
			position = player2.attack();
			cout << player2Name << " attack "<< position.first << ' ' << position.second << '\n';
			// return the ship in the postion
			ship = player1.beAttcked(position);
			// return if the sum of the hp of the ships is equal to 0
			end = player1.displayShip();
			if(!end)
				player2.determine(ship, position);

			if(ship == 'O'){
				cout << "miss...\n";
				break;
				// AI determine the conversion of the possibility
			}
			// AI determine the conversion of the possibility
		}
		if(end){
			cout << player2Name << "  win\n";//player2 win
			break;
		}
		cout << "==============================================================\n";
	}
}

Judge::~Judge(){
	delete player1Name;
	delete player2Name;
}
