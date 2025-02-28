/*
 * Ghost.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef GHOST_H_
#define GHOST_H_


#include "Enemy.h"
#include "Player.h"
#include "Card.h"

class Ghost: public Enemy{
public:
	Ghost();
	virtual ~Ghost();
	int dealDamage() override;
	void interactWithPlayer(Player& player) override;
};


#endif /* GHOST_H_ */
