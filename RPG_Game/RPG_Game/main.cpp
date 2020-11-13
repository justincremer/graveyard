#include <iostream>
#include <string>
#include <windows.h> //system("CLS"), Sleep(time) <-ms
#include <stdlib.h> //rand()
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main() {
	Player player{"justin"};
	Enemy enemy{"Boar", 1, 0, 10, 10, 1};
	while(1) {
		system("CLS");
		enemy.setCurrHp((player.getStr()));
		player.setCurrHp((enemy.getStr()));
		player.displayCharacter();
		enemy.displayCharacter();
		cout <<  endl;
		if(player.getCurrHp() == 0 || enemy.getCurrHp() == 0)
			break;
		Sleep(1000);	
	}
	
	return 0;
}