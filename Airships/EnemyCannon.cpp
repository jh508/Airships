#include "EnemyCannon.h"
#include <iostream>

void EnemyCannon::initializeVariables()
{
	this->projectileLifeTime = 100.0f;
	this->projectileSpeed = 0.5f;
}

void EnemyCannon::initializeTexture()
{
	if (!this->enemyCannonTexture.loadFromFile("Sprites/EnemyAirCannon.png")) {
		std::cout << "Error loading EnemyAirCannon.png" << std::endl;
	}
}

void EnemyCannon::initializeSprite(sf::Sprite& enemyShip)
{
	this->enemyCannonSprite.setTexture(this->enemyCannonTexture);
	this->enemyCannonSprite.setPosition(enemyShip.getPosition());
}


EnemyCannon::EnemyCannon(sf::Sprite& enemyShip)
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite(enemyShip);
}

EnemyCannon::~EnemyCannon()
{
	std::cout << "This should delete" << std::endl;
}



void EnemyCannon::update(Player& player, float deltaTime)
{
	this->enemyCannonSprite.move(sf::Vector2f(0, 300 * deltaTime));
	
}

