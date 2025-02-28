/*
 * Deck.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <vector>
#include <iostream>
class Deck{
private:


	void ensureCapacity(int capacity);
	void resize();
	std::vector<Card> cards;
public:
	Deck();
	Deck(const Deck& other); // copy constructor
	~Deck();
	Deck& operator+=(const Card& card);
	Deck& operator=(const Deck& other);
	Deck& operator-=(int X); // remove X cards from the deck
	Card operator[] (int index) const; // Access a card at position [X] from the bottom
	friend std:: ostream& operator<<(std::ostream& os, const Deck& deck);
	void addCard(const Card& card);
	void lookAtTopCards(int X)const;
	void replaceCard(int index,const Card& newCard);
	void printDeck() const;
	bool contains(const Card& card) const;
	bool isEmpty() const;
	Card DrawCard();

};

#endif /* DECK_H_ */

