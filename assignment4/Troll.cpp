/*
 * Troll.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include "Troll.h"
#include "Player.h"
/**
 * Constructor for the Troll class.
 * Initializes the Troll with specific life points and damage points,
 */
Troll::Troll() :Enemy(100,5){

}
/**
 * Destructor for the Troll class.
 */
Troll::~Troll(){

}
/**
 * Calculates and returns the damage dealt by the Troll.
 *
 * @return int The amount of damage the Troll deals.
 */
int Troll::dealDamage(){
	return 5;
}
/**
 * Defines the interaction between the Troll and a Player.
 * This method can be customized to implement the specific attack patterns,
 * responses, or behaviors of the Troll when facing a player in combat.
 * 
 * @param player Reference to the Player object representing the player character.
 */
void Troll::interactWithPlayer(Player& player){
	player.fightTroll(*this);
}
