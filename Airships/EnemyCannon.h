#pragma once

#include "Player.h"

class EnemyCannon {
public:
	EnemyCannon(sf::Sprite& enemyShip);
	~EnemyCannon();

	void update(Player& player, float deltaTime);

	//	Getters and Setters
	sf::Sprite getSprite();

private:

	//Initialization
	void initializeTexture();
	void initializeSprite(sf::Sprite& enemyShip);
	void initializeVariables();

	sf::Sprite enemyCannonSprite;
	// Variables
	float projectileSpeed;
	float projectileLifeTime;
	sf::Vector2u direction;


	sf::Texture enemyCannonTexture;
};