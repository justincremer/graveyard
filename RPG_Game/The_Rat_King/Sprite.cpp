#include "Sprite.h"
#include <string>
#include <stdlib.h>

using namespace std;

Sprite::Sprite(string name_val, int level_val, int xp_val, int hp_val, int currentHp_val, int str_val, int def_val)
	: name{name_val}, level{level_val}, experience{xp_val}, health{hp_val}, currentHealth{currentHp_val}, strength{str_val}, defence{def_val} {}
	
string Sprite::getName() {return name;}
int Sprite::getLevel() {return level;}
int Sprite::getXp() {return experience;}
int Sprite::getHp() {return health;}
int Sprite::getCurrHp() {return currentHealth;} 
void Sprite::setCurrHp(int i) {  //// FIX THIS ////
	if(currentHealth - i > 0)
		currentHealth -= i;
	else
		currentHealth = 0;}
int Sprite::getStr() {return strength;}
int Sprite::getDef() {return defence;} 

void Sprite::setName(string i) {name = i;}

hitType Sprite::attack() {
	int result = rand() % 100 + 1; // 1 - 100
	if(result <= 20)
		return {"Miss", 0};
	else if(result <= 45)
		return {"Weak hit", strength * 2 / 3};
	else if(result <= 80)
		return {"Hit", strength};
	else
		return {"Critical", strength * 3 / 2};
}

bool Sprite::isDead(int i) {return i <= 0 ? true : false;} // takes health as an input
