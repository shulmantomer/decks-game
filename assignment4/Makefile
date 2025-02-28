Decks_game: Card.o Deck.o Dragon.o Enemy.o Fighter.o GameManager.o Ghost.o Hand.o Player.o Ranger.o Sorcerer.o Troll.o
	g++ Card.o Deck.o Dragon.o Enemy.o Fighter.o GameManager.o Ghost.o Hand.o Player.o Ranger.o Sorcerer.o Troll.o -o Decks_game
	
Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp

Dragon.o: Dragon.cpp Dragon.h Enemy.h
	g++ -c Dragon.cpp

Enemy.o: Enemy.cpp Enemy.h
	g++ -c Enemy.cpp

Fighter.o: Fighter.cpp Fighter.h Player.h
	g++ -c Fighter.cpp

GameManager.o: GameManager.cpp GameManager.h Player.h Enemy.h Deck.h Hand.h
	g++ -c GameManager.cpp

Ghost.o: Ghost.cpp Ghost.h Enemy.h
	g++ -c Ghost.cpp

Hand.o: Hand.cpp Hand.h Card.h Deck.h
	g++ -c Hand.cpp

Player.o: Player.cpp Player.h Card.h Deck.h
	g++ -c Player.cpp

Ranger.o: Ranger.cpp Ranger.h Player.h
	g++ -c Ranger.cpp

Sorcerer.o: Sorcerer.cpp Sorcerer.h Player.h
	g++ -c Sorcerer.cpp

Troll.o: Troll.cpp Troll.h Enemy.h
	g++ -c Troll.cpp

clean:
	rm -f *.o Decks_game