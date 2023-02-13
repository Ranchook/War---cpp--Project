#pragma once
#include "card.h"
#include "player.h"
#define NO_OF_DECK 1
#define NUM_IN_SERIAL 8

class gameEngine {

private:
	Card Cards[NO_OF_DECK*NUM_IN_SERIAL * 4];
	class playerMng {
		Player** players;
		int howManyPlayrs;
		friend class gameEngine;
	}players;

public:
	gameEngine();
	~gameEngine();
	
	friend class cashierStack;
	friend bool Card :: operator >(const Card&)const;
	friend bool Card :: operator ==(const Card&) const;
	friend void Player:: operator += (const Card);
	friend const Card* Player:: operator - (const int);

	void buildCards();
	void buildCards(int startIdx, char sign);
	void setPlayers();
	bool extructPlayer(Player * looser);
	bool turn();
	void startGame();
	void moveCardsTrashCardsToWinner(Player * winner);
};