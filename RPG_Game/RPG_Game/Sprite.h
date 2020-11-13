#ifndef SPRITE_H
#define SPRITE_H

#include <string>

using namespace std;

class Sprite {
protected:
	string name;
	int level;
	int experience;
	int health;
	int currentHealth;
	int strength;
	int defence;
	
public:
	void setName(string i);
	string getName();
	int getLevel();
	int getXp();
	int getHp();
	int getCurrHp();
	void setCurrHp(int i); // where i is damage taken
	int getStr();
	int getDef();	
	// COMBAT FUNCTIONS
	bool isDead(int i);
	int attack();
	int defend();  
	// DEFAULT CONSTRUCTOR
	Sprite(string name_val = "None", int level_val = 1, int xp_val = 0, int hp_val = 10, int currentHp_val = 10, int str_val = 2, int def_val = 1);
};



#endif // SPRITE_H
