/*
 * Player.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */
#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <iostream>
#include <vector>


#include "Card.h"
#include "Deck.h"
class Enemy;
class Troll;
class Ghost;
class Dragon;
class Player{
protected:
	int lifePoints;
	int maxlifePoints=lifePoints;
	int maxCards;
	int damageMitigation=0;
	bool blockHeal =false;
	bool blockDamageMitigation = false;
	bool blockDouble= false;
	std::vector<Card> currentCards;
	int calaculatedamage=0;
	int healAmount=0;


public:

	Player(int lifePoints,int maxCards);
	virtual ~Player();
	int getLifePoints() const;
	void setLifePoints(int points);
	int getMaxCards() const;
	void applydamage(int damage);
	void heal(int amount);
	void setdamage(int mitigation);
	virtual void processPlayerTurn(const std::vector<Card>& playedCard);
	void setBlockHeal(bool block);
	void setBlockDamageMitigation(bool block);
	void setBlockDouble(bool block);
	void resetBlockEffects();
	void setCurrentCards(const std::vector<Card>& cards);
	virtual void fightTroll(const Troll& troll)=0;
	virtual void fightGhost(const Ghost& ghost)=0;
	virtual void fightDragon(const Dragon& dragon)=0;
	void clearCurrentCards();
	int getDamageMitigation();
	int getCalculateDamage() const;
	void resetCalculateDamage();
	void setHealAmount(int healAmount);
	int getHealAmount();


};
#endif  /* PLAYER_H_ */
