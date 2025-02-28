/*
 * Card.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include "Card.h"
#include <stdio.h>
#include <iostream>
/**
 * Calculates the value of a card based on its rank.
 * 
 * @param rank The rank of the card.
 * @return The numerical value associated with the card's rank.
 */
int Card:: calculatevalue(Rank rank){
	switch (rank){
	case A: return 1;
	case TWO: return 2;
	case THREE: return 3;
	case FOUR: return 4;
	case FIVE: return 5;
	case SIX: return 6;
	case SEVEN: return 7;
	case EIGHT: return 8;
	case NINE: return 9;
	case T: return 10;
	case J: return 10;
	case Q: return 15;
	case K: return 20;
	default: return 0;
	}
}

/**
 * Default constructor that initializes a card with the rank of Ace and the sign of Clubs.
 */
Card:: Card() :rank(A),sign(C),value(calculatevalue(A)){}

/**
 * Constructor that initializes a card with a specified rank and sign.
 * 
 * @param rank The rank of the card.
 * @param sign The sign of the card.
 */
Card:: Card(Rank rank, Sign sign) : rank(rank), sign (sign),value(calculatevalue(rank)){}


/**
 * Returns the rank of the card.
 * 
 * @return The rank of the card.
 */
Card:: Rank Card:: getRank() const{
	return rank;
}
/**
 * Returns the sign of the card.
 * 
 * @return The sign of the card.
 */
Card:: Sign Card:: getSign() const{
	return sign;
}
/**
 * Returns the value of the card.
 * 
 * @return The value of the card.
 */
int Card:: getValue() const{
	return value;
}

/**
 * Sets the rank of the card and updates its value accordingly.
 * 
 * @param newRank The new rank to be set for the card.
 */
void Card:: setRank(Rank newRank){
	rank =newRank;
	value = calculatevalue(rank);
}

/**
 * Sets the sign of the card.
 * 
 * @param newSign The new sign to be set for the card.
 */
void Card:: setSign(Sign newSign){
	sign = newSign;
}

/**
 * Assignment operator that copies the rank, sign, and value from another card.
 * 
 * @param other The card to copy from.
 * @return A reference to the modified card.
 */
Card& Card::operator=(const Card& other){
	if (this!=&other){
		rank = other.rank;
		sign = other.sign;
		value =other.value;
	}
	return *this;
}



/**
 * Converts a sign enum to its corresponding character representation.
 * 
 * @param sign The sign enum to convert.
 * @return The character representation of the sign.
 */
char Card::signtoChar(Sign sign){
	switch (sign){
	case C: return 'C';
	case D: return 'D';
	case H: return 'H';
	default: return 'S';

	}
}
/**
 * Converts a rank enum to its corresponding character representation.
 * 
 * @param rank The rank enum to convert.
 * @return The character representation of the rank.
 */
char Card::ranktoChar(Rank rank){
	switch(rank){
	case A: return 'A';
	case TWO: return '2';
	case THREE: return '3';
	case FOUR: return '4';
	case FIVE: return '5';
	case SIX: return '6';
	case SEVEN: return '7';
	case EIGHT: return '8';
	case NINE: return '9';
	case T: return 'T';
	case J: return 'J';
	case Q: return 'Q';
	default: return 'K';

	}
}

/**
 * Equality operator that compares two cards based on their rank and sign.
 * 
 * @param lhs The left-hand side card.
 * @param rhs The right-hand side card.
 * @return True if both cards have the same rank and sign, false otherwise.
 */
bool operator==(const Card& lhs,const Card& rhs){
	return lhs.getRank()==rhs.getRank() && lhs.getSign()==rhs.getSign();
}

/**
 * Inequality operator that compares two cards based on their rank and sign.
 * 
 * @param lhs The left-hand side card.
 * @param rhs The right-hand side card.
 * @return True if the cards have different ranks or signs, false otherwise.
 */
bool operator!=(const Card& lhs,const Card& rhs){
	return !(lhs==rhs);
}

/**
 * Less than operator that orders cards first by rank then by sign.
 * 
 * @param lhs The left-hand side card.
 * @param rhs The right-hand side card.
 * @return True if lhs is less than rhs based on rank and then sign, false otherwise.
 */
bool operator<(const Card& lhs,const Card& rhs){
	if (lhs.getRank()==rhs.getRank()){
		return lhs.getSign() < rhs.getSign();
	}
	return lhs.getRank()< rhs.getRank();
}

/**
 * Less than or equal operator that checks if one card is less than or equal to another.
 * 
 * @param lhs The left-hand side card for comparison.
 * @param rhs The right-hand side card for comparison.
 * @return True if the left-hand side card is less than or equal to the right-hand side card, false otherwise.
 */
bool operator<=(const Card& lhs,const Card& rhs){
	return lhs< rhs || lhs ==rhs;
}
/**
 * Greater than operator that checks if one card is greater than another.
 * 
 * This function is implemented by checking if the left-hand side card is not less than or equal to the right-hand side card.
 * 
 * @param lhs The left-hand side card for comparison.
 * @param rhs The right-hand side card for comparison.
 * @return True if the left-hand side card is greater than the right-hand side card, false otherwise.
 */
bool operator>(const Card& lhs,const Card& rhs){
	return !(lhs<= rhs);
}
/**
 * Greater than or equal operator that checks if one card is greater than or equal to another.
 * 
 * This function is implemented by checking if the left-hand side card is not less than the right-hand side card.
 * 
 * @param lhs The left-hand side card for comparison.
 * @param rhs The right-hand side card for comparison.
 * @return True if the left-hand side card is greater than or equal to the right-hand side card, false otherwise.
 */
bool operator>=(const Card& lhs,const Card& rhs){
	return !(lhs<rhs);
}
/**
 * Stream insertion operator that outputs a card's details to a stream. 
 * This operator allows cards to be printed to the standard output or any other output stream using the '<<' operator.
 * It uses the card's sign and rank to construct a two-character string representation of the card.
 * @param os The output stream to which the card's details are to be sent.
 * @param card The card whose details are to be outputted.
 * @return A reference to the output stream to support chain calling of the operator.
 */
std::ostream& operator<<(std::ostream& os, const Card& card){
	char signChar=Card::signtoChar(card.getSign());
	char rankChar = Card::ranktoChar(card.getRank());
	os<< rankChar<<signChar;
	return os;
}
/**
 * Parses a card from its string representation.
 * 
 * @param input The string representation of the card (e.g., "AS" for Ace of Spades).
 * @return The card corresponding to the input string.
 */
Card Card::parseCardFromInput(const char* input){
	Rank rank;
	Sign sign;
	switch(input[0]){
	case 'A': rank=A; break;
	case '2': rank=TWO; break;
	case '3': rank=THREE; break;
	case '4': rank=FOUR; break;
	case '5': rank=FIVE; break;
	case '6': rank=SIX; break;
	case '7': rank=SEVEN; break;
	case '8': rank=EIGHT; break;
	case '9': rank=NINE; break;
	case 'T': rank=T; break;
	case 'J': rank=J; break;
	case 'Q': rank=Q; break;
	case 'K': rank=K; break;

	}
	switch(input[1]){
	case 'D': sign=D;break;
	case 'H': sign=H;break;
	case 'S': sign=S;break;
	case 'C': sign=C;break;
	}
	return Card(rank,sign);

}



