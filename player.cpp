#include "player.h"
#include <iostream>
#include <cstring>

int Player::player_Num = 1;


Player::Player(const char* n)
{
	char c[2];
	_itoa(player_Num, c, 10);
	char name[9] = "player ";
	strcat(name, c);
	player_Num++;
	
	if (name)
		setName(name);
}

Player::~Player()
{
#ifdef DEBUG
	cout << "\n Kill Player: " << name;
#endif // DEBUG
	delete[] name;
}

void Player::setName(const char*n) {
	int size = strlen(n) + 1;
	name = new char[size];
	strcpy_s(name, size, n);
}


const Card* Player::getTopTrash() {
	return trash.getTopDeck();
}

char * Player::getName() const
{
	return name;
}

void Player::operator+=(const Card c)
{
	Card *temp = new Card;
	temp->setCard(c.getSign(), c.getValue());
	this->hand.push(temp);
}

const Card * Player::operator-(const int n)
{
	if (n == 3 && (hand.getNumInDeck() + trash.getNumInDeck())< 3)
		return nullptr;

	for (int i = 0; i < n; i++)
		{
		if (hand.getNumInDeck() == 0)
		{
			if (trash.getNumInDeck() == 0)
				return nullptr;

			while (trash.getNumInDeck() > 0)
				hand.push(trash.pop());
			hand.shuffle();
			trash.reset();
		}
		if (i == (n - 1))
		{
			const Card* temp = hand.pop();
			trash.push(temp);
			return temp;
		}
		trash.push(hand.pop());
	}
}

void Player::operator+(Player &loser)
{
	if (this->getName() != loser.getName())
	{
		while (loser.trash.getNumInDeck() > 0)
		{
			const Card *temp = new Card;
			temp = loser.trash.pop();
			this->operator+=(*temp);
		}
	}
}

void Player::shuffleHand()
{
	hand.shuffle();
}


