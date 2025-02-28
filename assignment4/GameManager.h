/*
 * GameManager.h
 *
 *  Created on: 6 Mar 2024
 *      Author: isetomer
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Enemy.h"
#include "Hand.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"
#include "Troll.h"
#include "Ghost.h"
#include "Dragon.h"
class GameManager{
private:
	Deck* deck;
	Player* player = nullptr;
	Enemy* enemy=nullptr;
	Hand* hand=nullptr;

public:
	GameManager();
	virtual ~GameManager();
	void initiliazeDeck();
	void initiliazeGame();
	void chooseCharacters();
	void handleCardSetInput();
	std::vector<Card> parseCards(const std::string& inputLine);
	//void applyCardEffects(const std::vector <Card>& cards );
};


#endif /* GAMEMANAGER_H_ */
