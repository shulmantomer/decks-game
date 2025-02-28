/*
 * Dragon.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef DRAGON_H_
#define DRAGON_H_


#include "Enemy.h"
#include "Player.h"
#include "Card.h"
class Dragon: public Enemy{
public:
	Dragon();
	virtual ~Dragon();
	int dealDamage() override;
	void interactWithPlayer(Player& player) override;
};

#endif /* DRAGON_H_ */
