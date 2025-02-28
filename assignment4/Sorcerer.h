/*
 * Sorcerer.h
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#ifndef SORCERER_H_
#define SORCERER_H_

#include <iostream>

#include "Player.h"
class Sorcerer: public Player{
public:
	Sorcerer();
	virtual ~Sorcerer();
	void fightTroll(const Troll& troll)override;
	void fightGhost(const Ghost& ghost)override;
	void fightDragon(const Dragon& dragon)override;

};

#endif /* SORCERER_H_ */
