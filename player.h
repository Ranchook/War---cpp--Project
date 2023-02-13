#pragma once
#include "CashierStack.h"
#include "Card.h"
#include <iostream>
using namespace std;
class Player {

private:
	char* name;
	CashierStack hand, trash;

public:
	void setName(const char* name);
	static int player_Num;
	const Card* getTopDeck(); // you never used it
	const Card* getTopTrash();
	char* getName()const;
	void operator += (const Card);
	const Card * operator - (const int);
	void operator+(Player&);
	void shuffleHand();
	Player(const char* name = NULL);
	~Player();
};