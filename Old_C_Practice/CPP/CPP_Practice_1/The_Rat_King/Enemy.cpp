#include "Enemy.h"
#include <iostream>
#include <string>

using namespace std;

void Enemy::displayCharacter() {
	cout << " -------------------" << endl;
	cout << " | " << getName() << "  Level: " << getLevel() << endl;
	cout << " | "<< "HP: " << getCurrHp() << "/" << getHp() << endl;
}
