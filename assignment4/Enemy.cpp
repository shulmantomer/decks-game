/*
 * Enemy.cpp
 *
 *  Created on: 5 Mar 2024
 *      Author: isetomer
 */


#include "Enemy.h"
/**
 * Constructor for the Enemy class, initializing the enemy with specified life points and damage points.
 * @param lifePoints The initial life points of the enemy.
 * @param damagePoints The initial damage points of the enemy.
 */
Enemy::Enemy(int lifePoints, int damagePoints)
: lifePoints(lifePoints),damagePoints(damagePoints){}
/**
 * Destructor for the Enemy class.
 */
Enemy::~Enemy() {}
/**
 * Gets the current life points of the enemy.
 * @return The current life points of the enemy.
 */
int Enemy::getLifePoints() const{
	return lifePoints;
}
/**
 * Sets the life points of the enemy.
 * @param points The new life points value for the enemy.
 */
void Enemy::setLifePoints(int points){
	lifePoints = points;
}
/**
 * Gets the current damage points of the enemy.
 * @return The current damage points of the enemy.
 */
int Enemy::getDamagePoints() const{
	return damagePoints;
}
/**
 * Sets the damage points of the enemy.
 * @param points The new damage points value for the enemy.
 */
void Enemy::setDamagePoints(int points){
	damagePoints = points;
}
/**
 * Applies damage to the enemy, reducing its life points.
 * Ensures that the life points do not drop below zero.
 * @param damage The amount of damage to apply to the enemy.
 */
void Enemy::applydamage(int damage){
	lifePoints-=damage;
	if (lifePoints<0)
		lifePoints=0;
}
