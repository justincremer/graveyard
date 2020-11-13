#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.h"

class Enemy : public Sprite {
public:
	void displayCharacter();
	
	using Sprite::Sprite;
};

#endif // ENEMY_H
