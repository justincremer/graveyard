#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

void Player::setLevel() {level++;}
void Player::setXp(int i) {experience += i;}
void Player::setHp(int i) {
	if(i > 0) {
		if(currentHealth + i <= health)
			currentHealth += i;
		else
			currentHealth = health;	
	}
	else {
		if(currentHealth + i <= 0)
			currentHealth = 0;
		else 
			currentHealth += i;	
	}
}
void Player::setStr(int i) {strength += i;}
void Player::setDef(int i) {defence += i;}
/*
void Player::levelUp() {
	if(level < 20) {
		
	}
}
*/
void Player::rest() {
	if(currentHealth + health / 10 > health) 
		currentHealth = health;
	else
		currentHealth += health / 10;
}
void Player::displayCharacter() {
	cout << " -------------------" << endl;
	cout << " | " << getName() << "  Level: " << getLevel() << endl;
	cout << " | XP: " << getXp() << "  HP: " << getCurrHp() << "/" << getHp() << endl;
	cout << " | STR: " << getStr() << "  DEF: " << getDef() << "\n" <<endl;
}

