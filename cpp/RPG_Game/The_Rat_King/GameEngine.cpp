#include "GameEngine.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <Player.h>
#include <Enemy.h>

using namespace std;


/*
	WELCOME SCREEN CALLED FIRST
	NEW OR LOAD GAME NEXT
	MAIN LOOP WRAPS COMBAT AND 
	POST COMBAT SEQUENCES
*/

Player newGame() {
	system("CLS");
	string temp;
	cout << "\n\n\n\n\n\n\n\n\n\n					Please enter a name: ";
	cin >> temp;
	Player player {temp};
	return player;
}

Enemy whichEnemy(Player player) {
	switch(player.getLevel()) {
		// name_val = "None", int level_val = 1, int xp_val = 0, int hp_val = 10, int currentHp_val = 10, int str_val = 2, int def_val = 1
		case 1: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}			
		case 2: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}
		case 3: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 4: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 5: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 6: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 7: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 8: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 9: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}		
		case 10: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}
		default: {
			Enemy enemy {"Rat", 1, 50, 10, 10, 1, 0};
			return enemy;
		}
	}
}

void combatSequence(Player player) {
	Enemy enemy = whichEnemy(player);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n				get ready for a lack luster combat experience!"<< endl;
	Sleep(2250);
	while(!player.isDead(player.getCurrHp()) && !enemy.isDead(enemy.getCurrHp())) {
		system("CLS");
		player.displayCharacter();
		Sleep(1000);
		enemy.displayCharacter();
		cout << endl;
		Sleep(1000);
		START: {
			system("CLS");
			cout << "What would you like to do? \n\n$";
			string call;
			int temp;
			cin >> call;
			cout << endl;
			if(call == "help") {temp = 1;}
			if(call == "attack") {temp = 2;}
			switch(temp) {
				case 1: {
					cout << "\nActions: \n\nattack\n" <<endl;
					Sleep(1500);
					goto START;
				}
				case 2: {
					system("CLS");
					hitType i = player.attack();
					cout << "\n\n\n\n\n\n\n\n\n\n					" <<i.hit_name << endl;
					enemy.setCurrHp(i.hit_val);
					Sleep(1500);
					break;
				}
				default: {
					cout << "unknown command" <<endl;
					Sleep(1500);
					goto START;
				}
			}	
		}
		system("CLS");
		hitType i = enemy.attack();
		cout << "\n\n\n\n\n\n\n\n\n\n					" <<enemy.getName() << ": " << i.hit_name << endl;
		player.setCurrHp(i.hit_val);
		Sleep(1500);
	}
	system("CLS");
	if(player.isDead(player.getCurrHp())) {
		cout << "How the fuck did you die?\nHere, have some health and we'll pretend you won." << endl;
		system("CLS");
		player.setCurrHp(player.getHp());
		player.displayCharacter();
		Sleep(1500);
	}
	system("CLS");
	string call;
	player.setCurrHp(player.getHp());
	cout << "Congratulation, you've killed a rat.\nWow.\nYou are the rat king.\nWant to do it again?\n\n$";
	cin >> call;
	cout <<endl;
	if(call == "yes")
		combatSequence(player);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n					Thank you for playing."<< endl;
	Sleep(2500);
}
