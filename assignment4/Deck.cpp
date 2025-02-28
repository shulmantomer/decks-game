/*
 * Deck.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include "Deck.h"
#include <iostream>

/**
 * Deck default constructor.
 * Initializes an empty deck.
 */
Deck::Deck() {}

/**
 * Copy constructor.
 * Creates a new deck that is a copy of an existing deck.
 * @param other The deck to copy from.
 */Deck::Deck(const Deck& other) : cards(other.cards) {}

/**
 * Destructor.
 * Cleans up the deck's resources. Not explicitly needed as std::vector manages its own memory.
 */
Deck::~Deck() {}

/**
 * Adds a card to the deck.
 * @param card The card to be added to the deck.
 * @return A reference to the current deck to allow chaining.
 */
Deck& Deck::operator+=(const Card& card) {
    cards.push_back(card);
    return *this;
}

/**
 * Assigns one deck to another.
 * Replaces the current deck's contents with those of another deck.
 * @param other The deck to assign from.
 * @return A reference to the current deck.
 */
Deck& Deck::operator=(const Deck& other) {
    if (this != &other) {
        cards = other.cards;
    }
    return *this;
}
/**
 * Removes a specified number of cards from the top of the deck.
 * @param X The number of cards to remove.
 * @return A reference to the current deck.
 */
Deck& Deck::operator-=(int X) {
    while (X-- > 0 && !cards.empty()) {
        cards.pop_back(); // Assumes top of the deck is the end of the vector
    }
    return *this;
}

/**
 * Provides access to a card in the deck by its index.
 * @param index The index of the card to access, where 0 is the bottom of the deck.
 * @return The card at the specified index. Returns a default-constructed Card if the index is invalid.
 */
Card Deck::operator[](int index) const {
    if (index < 0 || index >= cards.size()) {
        std::cout << "Invalid index" << std::endl;
        return Card(); // Return a default-constructed Card in case of invalid index
    }
    return cards[index]; // Direct access as std::vector supports it
}

/**
 * Prints the deck to an output stream.
 * @param os The output stream to print to.
 * @param deck The deck to be printed.
 * @return A reference to the output stream.
 */std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    os << '[';
    for (size_t i = 0; i < deck.cards.size(); i++) {
        os << deck.cards[i];
        if (i < deck.cards.size() - 1) {
            os << ", ";
        }
    }
    os << ']';
    return os;
}

/**
 * Prints the deck to standard output.
 * Iterates through the deck and prints each card.
 */
void Deck::printDeck() const{
	for (int i=cards.size()-1;i>=0;i--){
		std::cout<<cards[i]<< " ";
	}
	std::cout<<std::endl;
}
/**
 * Checks if a specific card is present in the deck.
 * @param card The card to search for.
 * @return True if the card is found, false otherwise.
 */
bool Deck::contains(const Card& card) const{
	for (const auto& currentCard : cards){
		if (currentCard== card)
			return true;

	}
	return false;
}
/**
 * Adds a card to the deck.
 * @param card The card to be added.
 */
void Deck::addCard(const Card& card) {
    cards.push_back(card); // Reuse the += operator for adding a card
}

/**
 * Looks at the top X cards of the deck.
 * Prints the top X cards to standard output.
 * @param X The number of cards to look at from the top of the deck.
 */
void Deck::lookAtTopCards(int X) const {
    int count = 0;
    for (auto it = cards.rbegin(); it != cards.rend() && count < X; ++it, ++count) {
        std::cout << *it << std::endl;
    }
}
/**
 * Replaces a card at a specific index in the deck.
 * @param index The index of the card to replace.
 * @param newCard The new card to place at the specified index.
 */
void Deck::replaceCard(int index, const Card& newCard) {
    if (index < 0 || index >= cards.size()) {
        std::cout << "Invalid index" << std::endl;
    } else {
        cards[index] = newCard; // Direct assignment thanks to std::vector
    }
}

/**
 * Checks if the deck is empty.
 * @return True if the deck is empty, false otherwise.
 */
bool Deck::isEmpty()const{
	return cards.empty();
}
/**
 * Draws a card from the top of the deck.
 * Removes the top card from the deck and returns it.
 * @return The drawn card. Returns a default-constructed Card if the deck is empty.
 */
Card Deck::DrawCard(){
	if(!cards.empty()){
		Card drawnCard= cards.front();
		cards.erase(cards.begin());
		return drawnCard;
	}
	else
		return {};

}
