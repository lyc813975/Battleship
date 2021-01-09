#include "AIPlayer.h"
#include "Player.h"
#include "Board.h"
#include "Ship.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

inline int AIPlayer::abs(int n){
	return (n > 0)? n:-1*n;
}

AIPlayer::AIPlayer(const char *playerName): Player(playerName){
	srand(time(NULL));

	solution = new int **[kShipQuantity];
	for(int i = 0; i < kShipQuantity; ++i){
		solution[i] = new int* [kBoardHeight];
		for(int j = 0; j < kBoardHeight; ++j){
			solution[i][j] = new int [kBoardWidth];
			for(int k = 0; k < kBoardWidth; ++k)
				// count need to be greater than 0
				solution[i][j][k] = 1;
		}

		for(int j = 0; j < kBoardHeight; ++j)
			for(int k = 0; k < kBoardWidth; ++k)
				count(i, ship[i]->getLength(), j, k);
	}
	
	sumSol = new int *[kBoardHeight];
	for(int i = 0; i < kBoardHeight; ++i)
		sumSol[i] = new int [kBoardWidth];
}

void AIPlayer::setShip(){
	pair<char, int> position;
	int direction;
	int setShip = 0;
	while(setShip < kShipQuantity){
		position.first = rand()%kBoardHeight + 'A';
		position.second = rand()%kBoardWidth + 1;
		direction = rand()%2;
		ship[setShip]->setLocation(position);
		ship[setShip]->setDirection(Direction(direction));
		if(board.setShip(*ship[setShip]))
			++setShip;
	}
}

pair<char, int> AIPlayer::attack(){
	int position = rand()%sum();
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j){
			position -= sumSol[i][j];
			if(position < 0){
				pair<char, int> p(i+'A', j+1);
				return p;
			}
		}
	// some error occur
	exit(-1);
}

void AIPlayer::determine(char s, pair<char, int> p){
	for(int i = 0; i < kShipQuantity; ++i){
		if(s == ship[i]->getType()[0])
			hit(i, ship[i]->getLength(), p.first-'A', p.second-1);
		else
			miss(i, ship[i]->getLength(), p.first-'A', p.second-1);
	}
}

AIPlayer::~AIPlayer(){
	for(int i = 0; i < kShipQuantity; ++i){
		for(int j = 0; j < kBoardHeight; ++j)
			delete [] solution[i][j];
		delete [] solution[i];
	}
	delete [] solution;

	for(int i = 0; i < kBoardHeight; ++i)
		delete [] sumSol[i];
	delete [] sumSol;
}

void AIPlayer::count(int ship, int length, int i, int j){
	int delta, wide;
	if(i < 0 || i >= kBoardHeight ||
			j < 0 || j >= kBoardWidth ||
			solution[ship][i][j] <= 0)
		return;

	// count way to set horizontally
	wide = 1;
	solution[ship][i][j] = 0;
	for(delta = 1; delta < length; ++delta){
		if(i+delta >= kBoardHeight || solution[ship][i+delta][j] == 0)
			break;
		++wide;
	}
	for(delta = 1; delta < length; ++delta){
		if(i-delta < 0 || solution[ship][i-delta][j] == 0)
			break;
		++wide;
	}
	if(wide > length-1)
		solution[ship][i][j] += wide-(length-1);

	// count way to set vertically
	wide = 1;
	for(delta = 1; delta < length; ++delta){
		if(j+delta >= kBoardWidth || solution[ship][i][j+delta] == 0)
			break;
		++wide;
	}
	for(delta = 1; delta < length; ++delta){
		if(j-delta < 0 || solution[ship][i][j-delta] == 0)
			break;
		++wide;
	}
	if(wide > length-1)
		solution[ship][i][j] += wide-(length-1);
}

void AIPlayer::miss(int ship, int length, int miss_i, int miss_j){
	const int kDirection = 4;
	int dx[kDirection] = {0, 0, 1, -1};
	int dy[kDirection] = {1, -1, 0, 0};
	// miss positoin set 0
	// -1 mean impossible position
	solution[ship][miss_i][miss_j] = 0;

	// count points possible way to set ship nearby miss point
	for(int delta = 1; delta < length; ++delta)
		for(int k = 0; k < kDirection; ++k)
			count(ship, length, miss_i+dx[k]*delta, miss_j+dy[k]*delta);
}

void AIPlayer::hit(int ship, int length, int hit_i, int hit_j){
	const int kDirection = 4;
	int dx[kDirection] = {0, 0, 1, -1};
	int dy[kDirection] = {1, -1, 0, 0};

	// except for the cross certened on hit position,
	// other positions set 0
	// 0 mean impossible position
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j)
			if((abs(i-hit_i) >= length || j != hit_j) &&
					(abs(j-hit_j) >= length || i != hit_i))
				solution[ship][i][j] = 0;

	// count points possible way to set ship nearby hit position
	for(int delta = 1; delta < length; ++delta)
		for(int k = 0; k < kDirection; ++k)
			count(ship, length, hit_i+dx[k]*delta, hit_j+dy[k]*delta);

	// hit position set -1
	// -1 mean hit position
	solution[ship][hit_i][hit_j] = -1;
}

int AIPlayer::sum(){
	int sum = 0;
	for(int i = 0; i < kBoardHeight; ++i)
		for(int j = 0; j < kBoardWidth; ++j){
			sumSol[i][j] = 0;
			for(int k = 0; k < kShipQuantity; ++k){
				if(solution[k][i][j] > 0)
					sumSol[i][j] += solution[k][i][j];
			}

			sum += sumSol[i][j];
		}

	return sum;
}
