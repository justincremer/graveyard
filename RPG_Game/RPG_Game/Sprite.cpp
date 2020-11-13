#include "Sprite.h"
#include <string>

using namespace std;

Sprite::Sprite(string name_val, int level_val, int xp_val, int hp_val, int currentHp_val, int str_val, int def_val)
	: name{name_val}, level{level_val}, experience{xp_val}, health{hp_val}, currentHealth{currentHp_val}, strength{str_val}, defence{def_val} {}
	
string Sprite::getName() {return name;}
int Sprite::getLevel() {return level;}
int Sprite::getXp() {return experience;}
int Sprite::getHp() {return health;}
int Sprite::getCurrHp() {return currentHealth;} 
void Sprite::setCurrHp(int i) {
	if(currentHealth - i > 0)
		currentHealth -= i;
	else
		currentHealth = 0;}
int Sprite::getStr() {return strength;}
int Sprite::getDef() {return defence;} 

void Sprite::setName(string i) {name = i;} 
//int  Sprite::attack();
//int  Sprite::defend();
bool Sprite::isDead(int i) {return i <= 0 ? true : false;} // takes health as an input