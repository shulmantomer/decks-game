/*
 * Hand.cpp
 *
 *  Created on: 6 Mar 2024
 *      Author: isetomer
 */

#include "Hand.h"
#include <iostream>
#include <sstream>

/**
 * Hand default constructor.
 * Initializes an empty hand of cards.
 */
Hand::Hand(){

}
/**
 * Hand destructor.
 * Cleans up the hand's resources.
 */
Hand::~Hand(){

}

/**
 * Adds a card to the hand.
 * Inserts the card at the beginning of the hand for easy access.
 * @param card The card to add to the hand.
 */
void Hand::addCard(const Card& card){
	cards.insert(cards.begin(),card);
}

/**
 * Removes a card from the hand by its index.
 * @param index The index of the card to remove from the hand.
 */
void Hand::removeCard(int index){
	if(index>=0 && index<cards.size()){
		cards.erase(cards.begin()+index);
	}
}

/**
 * Retrieves a card from the hand by its index.
 * @param index The index of the card to retrieve.
 * @param cardOut The card retrieved from the hand.
 * @return True if the card was successfully retrieved, false otherwise.
 */
bool Hand::getCard(int index, Card& cardOut)const{
	if(index>=0 && index<cards.size()){
		cardOut = cards[index];
		return true;
	}
	return false;
}

/**
 * Checks if a set of cards is a valid set according to the game rules.
 * A valid set can be a single card, or multiple cards of the same rank.
 * Special consideration is given to Ace (A) as it can be used once in a set.
 * @param set The set of cards to validate.
 * @return True if the set is valid, false otherwise.
 */
bool Hand::isValidSet(const std:: vector<Card>& set){// need to implement it
	if(set.size()==1)
		return true;
	int aceCount=0;
	Card::Rank firstRank = set[0].getRank();
	int totalValue=0;

	for(const Card& card : set){
		if(card.getRank() == Card::A){
			aceCount++;


			if (aceCount>1)
			return false;
		}
		else {
			if(firstRank != card.getRank()){
				return false;

			}
			totalValue+=card.getValue();
		}
	}
	if (totalValue - aceCount<=10)
		return true;
	else
		return false;

}
/**
 * Prints the hand to standard output.
 * Iterates through the hand and prints each card followed by a space.
 */
void Hand::printHand(){
	for(const Card& card : cards){
		std::cout<<card<<" ";
	}
	std::cout<<std::endl;
}
/**
 * Checks if a specific card is present in the hand.
 * @param card The card to search for in the hand.
 * @return True if the card is found, false otherwise.
 */
bool Hand::contains(const Card& card) const {
    for (const auto& handCard : cards) {
        if (handCard == card){
        	return true;
        }
    }
    return false;
}
/**
 * Removes a set of chosen cards from the hand.
 * Iterates through the hand and removes cards that match those in the chosen set.
 * @param chosenCards The set of cards to remove from the hand.
 */
void Hand::removeCards(const std::vector<Card>& chosenCards) {
    std::vector<Card> updatedHand;
    bool found;

    for (const auto& cardInHand : cards) {
        found = false;
        for (const auto& chosenCard : chosenCards) {
            if (cardInHand == chosenCard) { // Assuming you have operator== implemented in Card
                found = true;
                break; // Break if we find a match, no need to check further
            }
        }
        if (!found) {
            // If the card was not found in chosenCards, keep it in the hand
            updatedHand.push_back(cardInHand);
        }
    }

    // Replace the old hand with the updated one
    cards = updatedHand;
}





