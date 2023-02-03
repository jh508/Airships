#pragma once

#include "Player.h"

class EnemyCannon {
public:
	EnemyCannon(sf::Sprite& enemyShip);
	~EnemyCannon();

	void update(Player& player, float deltaTime);

	sf::Sprite enemyCannonSprite;


private:

	//Initialization
	void initializeTexture();
	void initializeSprite(sf::Sprite& enemyShip);
	void initializeVariables();


	// Variables
	float projectileSpeed;
	float projectileLifeTime;
	sf::Vector2u direction;


	sf::Texture enemyCannonTexture;
};