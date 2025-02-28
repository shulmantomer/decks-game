/*
 * Fighter.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef FIGHTER_H_
#define FIGHTER_H_
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include <vector>
class Fighter: public Player{
public:
	Fighter();
	virtual ~Fighter();
	void fightTroll(const Troll& troll)override;
	void fightGhost(const Ghost& ghost)override;
	void fightDragon(const Dragon& dragon)override;
};

#endif /* FIGHTER_H_ */
