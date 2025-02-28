/*
 * Player.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */



#include <iostream>
#include "Player.h"

/**
 * Constructs a Player object with specified life points and max cards allowed.
 * @param lifePoints The initial life points of the player.
 * @param maxCards The maximum number of cards the player can hold.
 */
Player::Player(int lifePoints, int maxCards):
lifePoints(lifePoints),maxCards(maxCards){

}
/**
 * Default destructor for the Player class.
 */
Player::~Player(){}
/**
 * Retrieves the current life points of the player.
 * @return The current life points of the player.
 */
int Player::getLifePoints() const{
	return lifePoints;
}

/**
 * Sets the life points of the player to a specified value.
 * @param points The new life points value. Cannot exceed the maximum life points.
 */
void Player::setLifePoints(int points){
	if(points>maxlifePoints)
		lifePoints =maxlifePoints;
	else
		lifePoints = points;
}

/**
 * Retrieves the maximum number of cards the player can hold.
 * @return The maximum number of cards.
 */
int Player::getMaxCards() const{
	return maxCards;
}

/**
 * Sets the current cards in the player's hand.
 * @param cards A vector containing the new set of cards.
 */
void Player::setCurrentCards(const std::vector <Card>& cards){
	currentCards = cards;
}

/**
 * Processes the player's turn based on the set of played cards.
 * Calculates damage, healing, and damage mitigation based on the cards' effects.
 * @param playedCards A vector containing the cards played by the player.
 */
void Player::processPlayerTurn(const std::vector<Card>& playedCards) {
	resetCalculateDamage();
	int totalSetDamage = 0;
    int healAmount = 0;
    int damageMitigation = 0;
    bool hasClover = false, hasLeaf = false, hasD=false,hasH=false;

    for (const auto& card : playedCards) {
        int cardValue = card.getValue();
        switch (card.getSign()) {
			case Card::H:
				hasH = true;
				break;
			case Card::D:
				hasD = true;
				break;
            case Card::C:
                hasClover = true;
                break;
            case Card::S:
                hasLeaf = true;
                break;
        }

        totalSetDamage += cardValue;

    }

    if (!blockHeal && hasH) healAmount += totalSetDamage;
    if (!blockDamageMitigation && hasD) damageMitigation += totalSetDamage;

    if (hasClover && hasLeaf && !blockDouble) {
        totalSetDamage *= 2;
        if (healAmount > 0)
        	healAmount *= 2;
        if (damageMitigation > 0)
        	damageMitigation *= 2;
    }
    if (healAmount > 0)
    	heal(healAmount);
    if (damageMitigation > 0)
    	setdamage(damageMitigation);
    calaculatedamage= totalSetDamage;
    setHealAmount(healAmount);
}

/**
 * Sets the healing amount for the player.
 * @param heal The amount to be healed.
 */
void Player::setHealAmount(int heal){
	healAmount=heal;
}

/**
 * Retrieves the healing amount for the player.
 * @return The healing amount.
 */
int Player::getHealAmount(){
	return healAmount;
}

/**
 * Applies damage to the player, adjusting the life points accordingly.
 * @param damage The amount of damage to apply.
 */
void Player::applydamage(int damage){
	if (damage<0)
		damage=0;
	lifePoints-=damage;
	if(lifePoints<0)
		lifePoints=0;
	damageMitigation=0;
}
/**
 * Heals the player by a specified amount, adding to the life points.
 * @param amount The amount to heal.
 */
void Player::heal(int amount){
	lifePoints+=amount;
}
/**
 * Sets the damage mitigation for the player.
 * @param mitigation The amount of damage mitigation.
 */
void Player::setdamage(int mitigation){
	damageMitigation = mitigation;
}
/**
 * Enables or disables healing block for the player.
 * @param block Whether to block healing.
 */
void Player::setBlockHeal(bool block){
	blockHeal =block;
}
/**
 * Enables or disables damage mitigation block for the player.
 * @param block Whether to block damage mitigation.
 */
void Player::setBlockDamageMitigation(bool block){
	blockDamageMitigation = block;
}
/**
 * Enables or disables double effect block for the player.
 * @param block Whether to block double effects.
 */
void Player::setBlockDouble(bool block){
	blockDouble =block;
}

/**
 * Resets the block effects for the player, allowing healing, damage mitigation, and double effects.
 */
void Player::resetBlockEffects(){
	blockHeal = false;
	blockDamageMitigation = false;
	blockDouble=false;
}
/**
 * Clears the current cards in the player's hand.
 */
void Player::clearCurrentCards(){
	currentCards.clear();
}

/**
 * Retrieves the current damage mitigation value for the player.
 * @return The damage mitigation value.
 */
int Player::getDamageMitigation(){
	if(damageMitigation<=0)
		damageMitigation=0;
	return damageMitigation;
}
/**
 * Retrieves the calculated damage for the player.
 * @return The calculated damage.
 */
int Player::getCalculateDamage() const{
	return calaculatedamage;
}
/**
 * Resets the calculated damage for the player to zero.
 */
void Player::resetCalculateDamage(){
	calaculatedamage=0;
}
