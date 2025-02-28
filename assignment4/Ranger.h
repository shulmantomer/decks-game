/*
 * Ranger.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef RANGER_H_
#define RANGER_H_

#include <iostream>

#include "Player.h"
class Ranger: public Player{
public:
	Ranger();
	virtual ~Ranger();
	void fightTroll(const Troll& troll)override;
	void fightGhost(const Ghost& ghost)override;
	void fightDragon(const Dragon& dragon)override;
};

#endif /* RANGER_H_ */
