#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <Player.h>
#include <Enemy.h>

void welcomeScreen();		// DO LATER 1
Player newGame();
void loadGame();			// DO LATER 3 
void saveGame();			// DO LATER 2
void mainLoop();			// NOT DONE	2
Enemy whichEnemy(Player player); 
void combatSequence(Player player);		// EDIT 1 // SPLIT INTO PLAYERTURN() ENEMYTURN()
void postCombatSequence();	// NOT DONE 1
void displayPlayerAndEnemy(Player player, Enemy enemy);

#endif

