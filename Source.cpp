#include "gameEngine.h"
#include <iostream>
#include <ctime>

//#define FINISHED_OPERATOR1 
//#define FINISHED_OPERATOR2
//#define FINISHED_OPERATOR3
//#define FINISHED_OPERATOR4

/*
opertaor 1: += adding card to player.hand
operator 2: - substract x cards from player.hand to trash (return last card)
operator 3: > if card.value > (other)card.value
operator 4: == if card.value = (other)card.value
operator 5 (using operator 1): adding all cards from player[i].trash to player.trash
*/

using namespace std;
void main() {
	srand(std::time(nullptr)); // use current time as seed for random generator

	gameEngine g;
#ifdef FINISHED_OPERATOR1
	g.startGame();
#endif


}