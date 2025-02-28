/*
 * Ghost.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */

#include "Ghost.h"
/**
 * Constructor for the Ghost class.
 * Initializes the Ghost with specific life points and damage points,
 */

Ghost::Ghost():Enemy(50,15){

}
/**
 * Destructor for the Ghost class.
 */

Ghost::~Ghost(){

}
/**
 * Calculates and returns the damage dealt by the Ghost.
 *
 * @return int The amount of damage the Ghost deals.
 */

int Ghost::dealDamage(){
	return 15;
}
/**
 * Defines the interaction between the Ghost and a Player.
 * This method can be customized to implement the specific attack patterns,
 * responses, or behaviors of the Ghost when facing a player in combat.
 * 
 * @param player Reference to the Player object representing the player character.
 */

void Ghost::interactWithPlayer(Player& player){
	player.fightGhost(*this);
}
