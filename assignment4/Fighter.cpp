/*
 * Fighter.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include <iostream>
#include "Fighter.h"
/**
 * Constructs a Fighter object with predefined life points and max cards.
 */
Fighter::Fighter() : Player(60,6){

}
/**
 * Destructor for the Fighter class.
 */
Fighter::~Fighter(){

}
/**
 * Executes the interaction between the Fighter and a Troll enemy.
 * Applies specific game logic, such as blocking healing if certain conditions are met.
 * @param troll The Troll enemy the Fighter is interacting with.
 */
void Fighter::fightTroll(const Troll& troll){
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
 * Executes the interaction between the Fighter and a Ghost enemy.
 * Applies specific game logic, such as enabling block double effects if certain conditions are met.
 * @param ghost The Ghost enemy the Fighter is interacting with.
 */
void Fighter::fightGhost(const Ghost& ghost){
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
 * Executes the interaction between the Fighter and a Dragon enemy.
 * Applies specific game logic, such as blocking damage mitigation if certain conditions are met.
 * @param dragon The Dragon enemy the Fighter is interacting with.
 */
void Fighter::fightDragon(const Dragon& dragon){
	resetBlockEffects();
	for (const auto& card: currentCards){
			if(card.getSign() == Card::D ){
				setBlockDamageMitigation(true);
				break;

			}
		}
	processPlayerTurn(currentCards);
}
