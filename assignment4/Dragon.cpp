/*
 * Dragon.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#include "Dragon.h"
/**
 * Constructor for the Dragon class.
 * Initializes the Dragon with specific life points and damage points,
 */

Dragon::Dragon():Enemy(75,10){

}
/**
 * Destructor for the Dragon class.
 */

Dragon::~Dragon(){

}
/**
 * Calculates and returns the damage dealt by the Dragon.
 *
 * @return int The amount of damage the Dragon deals.
 */

int Dragon::dealDamage() {
	return 10;
}
/**
 * Defines the interaction between the Dragon and a Player.
 * This method can be customized to implement the specific attack patterns,
 * responses, or behaviors of the Dragon when facing a player in combat.
 * 
 * @param player Reference to the Player object representing the player character.
 */

void Dragon::interactWithPlayer(Player& player){
	player.fightDragon(*this);
}
