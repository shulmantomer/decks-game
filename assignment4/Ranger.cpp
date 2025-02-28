/*
 * Ranger.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include <iostream>
#include "Ranger.h"
/**
 * Constructs a Ranger object with predefined life points and max cards.
 */

Ranger::Ranger() : Player(50,7){

}
/**
 * Destructor for the Ranger class.
 */

Ranger::~Ranger(){

}

/**
 * Executes the interaction between the Ranger and a Troll enemy.
 * Applies specific game logic, such as blocking healing if certain conditions are met.
 * @param troll The Troll enemy the Ranger is interacting with.
 */

void Ranger::fightTroll(const Troll& troll){
	bool blockS=false, blockC=false;
	resetBlockEffects();
	for (const auto& card: currentCards){
		if(card.getSign() == Card::S ){
			blockS=true;
				}
		if(card.getSign()== Card::C){
			blockC=true;
				}

		if (blockC && blockS){
			setBlockDouble(true);
			break;
			}

		}

	processPlayerTurn(currentCards);
}
/**
 * Executes the interaction between the Ranger and a Ghost enemy.
 * Applies specific game logic, such as enabling block double effects if certain conditions are met.
 * @param ghost The Ghost enemy the Ranger is interacting with.
 */

void Ranger::fightGhost(const Ghost& ghost){
	resetBlockEffects();
		for (const auto& card: currentCards){
				if(card.getSign() == Card::D ){
					setBlockDamageMitigation(true);
					break;

				}
			}
		processPlayerTurn(currentCards);
}
/**
 * Executes the interaction between the Ranger and a Dragon enemy.
 * Applies specific game logic, such as blocking damage mitigation if certain conditions are met.
 * @param dragon The Dragon enemy the Ranger is interacting with.
 */

void Ranger::fightDragon(const Dragon& dragon){
	resetBlockEffects();
		for (const auto& card: currentCards){
				if(card.getSign() == Card::H ){
					setBlockHeal(true);
					break;

				}
			}
		processPlayerTurn(currentCards);
}
