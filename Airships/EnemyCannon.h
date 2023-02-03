#pragma once

#include "Player.h"

class EnemyCannon {

	EnemyCannon();
	~EnemyCannon();

	void update();

	sf::Sprite enemyCannonSprite;


private:

	//Initialization
	void initializeTexture();
	void initializeSprite();
	void initializeVariables();

	// Variables
	float projectileSpeed;


	sf::Texture enemyCannonTexture;
};