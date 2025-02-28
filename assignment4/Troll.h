/*
 * Troll.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef TROLL_H_
#define TROLL_H_

#include "Enemy.h"
#include "Player.h"
#include "Card.h"


class Troll: public Enemy{
public:
	Troll();
	virtual ~Troll();
	int dealDamage() override;
	void interactWithPlayer(Player& player) override;
};

#endif /* TROLL_H_ */
