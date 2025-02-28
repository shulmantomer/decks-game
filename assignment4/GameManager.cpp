/*
 * GameManager.cpp
 *
 *  Created on: 6 Mar 2024
 *      Author: isetomer
 */

#include"GameManager.h"
#include <iostream>
#include <sstream>

/**
 * Constructs a GameManager object initializing the deck, players, and hand.
 */
GameManager::GameManager() : deck(new Deck()), player(nullptr), enemy(nullptr), hand(new Hand()) {
    // Initialization moved to initializer list
}
/**
 * Destructs the GameManager object, releasing allocated resources.
 */
GameManager::~GameManager(){
	delete deck;
	delete player;
	delete enemy;
	delete hand;
	deck =nullptr;
	player=nullptr;
	enemy=nullptr;
	hand=nullptr;
}
/**
 * Initializes the deck with cards inputted by the user until "00" is entered.
 */
void GameManager::initiliazeDeck(){
	std::string input;
	std::cout<<"Initialize deck\n";
	int count=0;
	while(true){
		std::cin>>input;
		if (input =="00")
			break;

		deck->addCard(Card::parseCardFromInput(input.c_str()));

		}

	}
/**
 * Allows the user to choose characters for the player and the enemy.
 */
void GameManager::chooseCharacters() {
    int playerChoice, enemyChoice;
    std::cout << "Choose player character:\n(1) Fighter (2) Sorcerer (3) Ranger\n";
    std::cin >> playerChoice;
    try {
        switch (playerChoice) {
            case 1: player = new Fighter(); break;
            case 2: player = new Sorcerer(); break;
            case 3: player = new Ranger(); break;
            default: std::cerr << "Invalid player choice" << std::endl; return;
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory Error " << e.what() << std::endl;
        // Properly handle the error, like exiting the function or application
        delete player; // Cleanup if player was already allocated
        player = nullptr; // Ensure the pointer is null after deletion
        return;
    }

    std::cout << "Choose enemy character:\n(1) Troll (2) Ghost (3) Dragon\n";
    std::cin >> enemyChoice;
    try {
        switch (enemyChoice) {
            case 1: enemy = new Troll(); break;
            case 2: enemy = new Ghost(); break;
            case 3: enemy = new Dragon(); break;
            default: std::cerr << "Invalid enemy choice" << std::endl; return;
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory Error " << e.what() << std::endl;
        // Properly handle the error, like cleaning up already created objects
        delete enemy; // Cleanup if player was already allocated
        enemy = nullptr; // Ensure the pointer is null after deletion
        return; // Example of exiting the function
    }

    std::cout << "Player health: " << player->getLifePoints() << std::endl;
    std::cout << "Enemy health: " << enemy->getLifePoints() << std::endl;
}
/**
 * Manages the card set input process during the game.
 */
void GameManager::handleCardSetInput() {
    int initialHandSize = player->getMaxCards();
    for (int i = initialHandSize-1; i>=0; --i){
    	   Card card = deck->DrawCard();
    	   hand->addCard(card);
    }
    std::cout << "Player hand\n";
    hand->printHand();
    std::cout << "Insert card set to play\n";
    while (true) {


        std::string inputLine;
        char c;
        std::cin.clear(); // Clear any error flags that might be set.
        while (std::cin.peek() == '\n' || std::cin.peek() == '\r') {
                std::cin.get(); // Consume the newline character if it's next in the buffer
            }

        std::getline(std::cin, inputLine); // choosing set
        if (inputLine == "exit") {
                break; // Exit the game loop
        }

        std::istringstream iss(inputLine);
        std::string cardStr;
        std::vector<Card> chosenCards;
        while (iss >> cardStr) {
            Card card = Card::parseCardFromInput(cardStr.c_str());
            if (hand->contains(card)) {
                chosenCards.push_back(card);
                hand->removeCards(chosenCards);
            }
        }
        if (chosenCards.empty() || !hand->isValidSet(chosenCards)) {
            std::cout << "Card set is not valid\n";
            std::cout << "Insert card set to play\n";
            continue;
        }

        player->setCurrentCards(chosenCards);
        enemy->interactWithPlayer(*player);
        int enemyDamage = enemy->dealDamage()-player->getDamageMitigation();
        int DamagetoEnemy = player->getCalculateDamage();
        int damageDealt= enemy->getLifePoints();
        enemy->applydamage(DamagetoEnemy);
        player->applydamage(enemyDamage);
        damageDealt-=DamagetoEnemy;
        std::cout << "Player dealt " <<DamagetoEnemy<<" points of damage\n"; // Placeholder, you might want to calculate actual damage
        if (enemy->getLifePoints() <= 0) {
                    std::cout << "Player won\n";
                    break;
                }
        if(player->getHealAmount()>0){
        	 std::cout << "Player healed " << player->getHealAmount() << " points of damage\n";
        }
        std::cout << "Player took " << std::max(0,enemyDamage) << " points of damage\n";
        if (player->getLifePoints() <= 0) {
            std::cout << "Player lost\n";
            break;
        }

        if( deck->isEmpty()){
        	std::cout<<"Deck ran out\n";
            break;

        }
        std::cout << "Player health: " << player->getLifePoints() << "\n";

        std::cout << "Enemy health: " << enemy->getLifePoints() << "\n";
        // Draw up to two new cards to replenish the hand but do not exceed initial hand size.
        for (int i = 0; i < 2 && hand->size() < initialHandSize ; ++i) {

            Card newCard = deck->DrawCard();
            hand->addCard(newCard);
        }


        std::cout << "Player hand\n";
        hand->printHand();
        std::cout << "Insert card set to play\n";
    }
}
/**
 * Initializes the game by setting up the deck and selecting characters.
 */
void GameManager::initiliazeGame(){
	initiliazeDeck();
	chooseCharacters();
	handleCardSetInput();



}
/**
 * Main function to execute the game.
 */
int main() {
	try {
	    // Assume initializeGame() is a function that sets up the game,
	    // including the creation of decks and loading of cards which might allocate memory.
		GameManager gamemanager;
	    gamemanager.initiliazeGame();
	} catch (const std::bad_alloc& e) {
	    std::cerr << "Memory Error" << e.what() << std::endl;
	    // Handle the memory allocation failure, e.g., by cleaning up resources, logging the error, and terminating the program.
	    return EXIT_FAILURE;
	} catch (const std::exception& e) {
	    // This catches other types of standard exceptions
	    std::cerr << "Memory Error " << e.what() << std::endl;
	    return EXIT_FAILURE;
	} catch (...) {
	    // This catches any other types of exceptions
	    std::cerr << "Memory Error" << std::endl;
	    return EXIT_FAILURE;
	}
}




