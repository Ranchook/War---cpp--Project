#include "CashierStack.h"

#include <iostream>
using namespace std;

// Constructor
CashierStack::CashierStack() {
    head = nullptr; // Initialize the head pointer to null
    numInDeck = 0;  // Initialize the number of items in the deck to 0
}

// Destructor
CashierStack::~CashierStack()
{
	// Loop through the stack and delete each item
	while (head) {
		stackItem* tmp = head;
		head = head->next;
		delete tmp;
	}
	numInDeck = 0; // Reset the number of items in the deck to 0
}

// Get the number of items in the deck
int CashierStack::getNumInDeck() const
{
	return numInDeck;
}

// Get the top card in the deck without removing it
const Card * CashierStack::getTopDeck() const
{
	return head->card;
}

// Pop the top card from the deck
const Card* CashierStack::pop() {
    stackItem* tmp = head;
    if (head) { 
        const Card* res = head->card; // Get the card from the top item
        head = head->next; // Move the head to the next item
        delete tmp; // Delete the old head
        numInDeck--; // Decrease the count of items in the deck
        return res; // Return the card
    }
    return nullptr; // Return null if the deck is empty
}

// Push a new card onto the deck
void CashierStack::push(const Card* c) {
    stackItem* newItem = new stackItem;
    newItem->card = c; 		// Set the card for the new item
    newItem->next = head; 	// Point the new item to the current head
    head = newItem; 		// Set the new item as the head
    numInDeck++; 		// Increase the count of items in the deck
}

void CashierStack::shuffle() {
    	// Shuffle the deck 200 times
	for (int i = 0; i < 200; i++) {
		int random_variable = std::rand(); // Generate a random number
		shuffleNitem(rand()%(numInDeck)); // Shuffle a random number of items
	}
}

// Reset the deck
void CashierStack::reset()
{
	head = nullptr; // Reset the head pointer to null
	numInDeck = 0; // Reset the number of items in the deck to 0
}

// Shuffle a specified number of items in the deck
void CashierStack::shuffleNitem(int n)
{
	CashierStack tmp; // Temporary stack for shuffling
	
	// Move 'n' items from the current stack to the temporary stack
	while (n>1 && head) { 
		tmp.push(pop()); 
		n--;
	}
	const Card* c = pop(); // Pop one item from the current stack

	// Move items back from the temporary stack to the current stack
	while (tmp.head) {
		push(tmp.pop());
	}
	push(c);  // Push the one item back to the current stack
}
