#ifndef GAMEENGINE_H
#define GAMEENGINE_H
#include <Player.h>
#include <Enemy.h>

void welcomeScreen();		// DO LATER 1
Player newGame();
void loadGame();			// DO LATER 3 
void saveGame();			// DO LATER 2
void mainLoop();			// NOT DONE	3
Enemy whichEnemy(Player player); 
void combatSequence(Player player);		// NOT DONE 1
void postCombatSequence();	// NOT DONE 2

#endif

