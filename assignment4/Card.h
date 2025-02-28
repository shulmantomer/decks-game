/*
 * Card.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#ifndef CARD_H_
#define CARD_H_
#include <stdio.h>
#include <iostream>
class Card{
public:
	enum Rank{
		A=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,T,J,Q,K
	};
	enum Sign{
		D,H,S,C
	};
private:
	Rank rank;
	Sign sign;
	int value;
	static int calculatevalue(Rank rank);


public:
	Card(); // default constructor
	Card(Rank rank, Sign sign);

	Rank getRank() const;
	Sign getSign() const;
	int getValue() const;
	void setRank(Rank newRank);
	void setSign (Sign newSign);
	Card& operator=(const Card& other);
	static char signtoChar(Sign sign);
	static char ranktoChar(Rank rank);
	friend bool operator==(const Card& lhs,const Card& rhs);
	friend bool operator!=(const Card& lhs,const Card& rhs);
	friend bool operator<(const Card& lhs,const Card& rhs);
	friend bool operator<=(const Card& lhs,const Card& rhs);
	friend bool operator>(const Card& lhs,const Card& rhs);
	friend bool operator>=(const Card& lhs,const Card& rhs);
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
	static Card parseCardFromInput(const char* input);
};



#endif /* CARD_H_ */

