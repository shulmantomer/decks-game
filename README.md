# Decks Game

A turn-based fantasy combat game written in C++, where the player chooses a hero class and battles a series of enemies using a card-driven action system.

The project demonstrates core object-oriented design principles in C++: inheritance, polymorphism, the Visitor pattern for combat resolution, and manual memory management.

## Features

- **Three playable character classes**, each with distinct combat behavior:
  - **Fighter** — high HP melee combatant
  - **Sorcerer** — magic-based attacker
  - **Ranger** — balanced ranged combatant
- **Three enemy types**, each interacting differently with player classes:
  - **Troll**
  - **Ghost**
  - **Dragon**
- **Card-based action system** with a shuffled `Deck`, a player `Hand`, and per-turn card selection
- **Visitor-pattern combat resolution** — every player class implements `fightTroll`, `fightGhost`, and `fightDragon` polymorphically
- **Game state management** centralized in `GameManager`

## Project Structure

```
assignment4/
├── Card.{h,cpp}          # Single card representation
├── Deck.{h,cpp}          # Shuffled draw pile
├── Hand.{h,cpp}          # Cards currently held by the player
├── Player.{h,cpp}        # Abstract base class for all player characters
├── Fighter.{h,cpp}       # Player subclass
├── Sorcerer.{h,cpp}      # Player subclass
├── Ranger.{h,cpp}        # Player subclass
├── Enemy.{h,cpp}         # Abstract base class for all enemies
├── Troll.{h,cpp}         # Enemy subclass
├── Ghost.{h,cpp}         # Enemy subclass
├── Dragon.{h,cpp}        # Enemy subclass
├── GameManager.{h,cpp}   # Game loop and state controller
└── Makefile              # Build configuration
```

## Build

Requirements:
- A C++ compiler with C++11 support (`g++` recommended)
- `make`

To build the project:

```bash
cd assignment4
make
```

This produces an executable named `Decks_game`.

To clean build artifacts:

```bash
make clean
```

## Run

From inside the `assignment4` directory:

```bash
./Decks_game
```

You will be prompted to choose a character class, then play through the game by selecting cards from your hand each turn.

## Design Notes

- **Inheritance hierarchy** — `Player` and `Enemy` are abstract base classes; concrete classes override virtual combat methods.
- **Visitor pattern** — combat between a player and an enemy is dispatched through `fightTroll` / `fightGhost` / `fightDragon` overrides on the player, allowing the correct interaction to be selected based on both participants' concrete types.
- **State flags** on `Player` (heal block, damage mitigation, double damage) support status-effect cards that influence subsequent turns.

## Author

Tomer Shulman — coursework project, March 2024.
