/*
 * Enemy.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef ENEMY_H_
#define ENEMY_H_

#include <stdio.h>
#include <iostream>

#include "Card.h"
#include "Deck.h"
class Player;
class Enemy{
protected:
	int lifePoints;
	int damagePoints;
public:
	Enemy(int lifePoints, int damagePoints);
	virtual ~Enemy();
	virtual int dealDamage() = 0;
	int getLifePoints() const;
	void setLifePoints(int points);
	int getDamagePoints() const;
	void setDamagePoints(int points);
	virtual void interactWithPlayer(Player& player) = 0;
	void applydamage(int damage);

};


#endif /* ENEMY_H_ */
