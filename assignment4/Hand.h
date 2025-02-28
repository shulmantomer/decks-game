/*
 * Hand.h
 *
 *  Created on: 6 Mar 2024
 *      Author: isetomer
 */

#ifndef HAND_H_
#define HAND_H_

#include "Card.h"
#include "Deck.h"
#include <vector>
#include <iostream>

class Hand{
private:
	std::vector <Card> cards;
public:
	Hand();
	~Hand();
	size_t size() const{
		return cards.size();
	}
	bool contains(const Card& card) const;
	bool getCard(int index, Card& cardOut)const;
	void addCard(const Card& card);
	void removeCard(int index);
	bool isValidSet(const std::vector<Card>& set);
	void printHand();
	void removeCards(const std::vector<Card>& chosenCards);
};

#endif /* HAND_H_ */
