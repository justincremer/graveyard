#include <stdio.h>
#include "GameEngine.h"
#include "Player.h"
#include "Enemy.h"

int main(int argc, char **argv)
{
	Player player = newGame();
	Enemy enemy = whichEnemy(player);
	//combatSequence(player);
	displayPlayerAndEnemy(player, enemy);
}
