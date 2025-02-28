/*
 * Sorcerer.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */
#include <iostream>
#include "Sorcerer.h"
/**
 * Constructs a Sorcerer object with predefined life points and max cards.
 */

Sorcerer::Sorcerer() : Player(40,8){

}
/**
 * Destructor for the Sorcerer class.
 */

Sorcerer::~Sorcerer(){

}
/**
 * Executes the interaction between the Sorcerer and a Troll enemy.
 * Applies specific game logic, such as blocking healing if certain conditions are met.
 * @param troll The Troll enemy the Sorcerer is interacting with.
 */

void Sorcerer::fightTroll(const Troll& troll){
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
 * Executes the interaction between the Sorcerer and a Ghost enemy.
 * Applies specific game logic, such as enabling block double effects if certain conditions are met.
 * @param ghost The Ghost enemy the Sorcerer is interacting with.
 */

void Sorcerer::fightGhost(const Ghost& ghost){
	resetBlockEffects();
		for (const auto& card: currentCards){
				if(card.getSign() == Card::H ){
					setBlockHeal(true);
					break;

				}
			}
		processPlayerTurn(currentCards);
}
/**
 * Executes the interaction between the Sorcerer and a Dragon enemy.
 * Applies specific game logic, such as blocking damage mitigation if certain conditions are met.
 * @param dragon The Dragon enemy the Sorcerer is interacting with.
 */

void Sorcerer::fightDragon(const Dragon& dragon){
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
