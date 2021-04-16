#ifndef PLAYER_H
#define PLAYER_H

#include "Sprite.h"

class Player : public Sprite {
private:
	int xpCap;
public:
	void setLevel();
	void setXp(int i);
	void setHp(int i); 
	void setStr(int i); 
	void setDef(int i);
	
	void levelUp(int i); // takes current level as input
	void rest(); // input for set health
	void displayCharacter();
	
	using Sprite::Sprite;
};

#endif // PLAYER_H
