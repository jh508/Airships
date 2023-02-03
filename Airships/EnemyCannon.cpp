#include "EnemyCannon.h"
#include <iostream>

void EnemyCannon::initializeVariables()
{

}

void EnemyCannon::initializeTexture()
{
	if (!this->enemyCannonTexture.loadFromFile("Sprites/EnemyAirCannon.png")) {
		std::cout << "Error loading EnemyAirCannon.png" << std::endl;
	}
}

void EnemyCannon::initializeSprite()
{
	this->enemyCannonSprite.setTexture(this->enemyCannonTexture);
}


EnemyCannon::EnemyCannon()
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();
}

EnemyCannon::~EnemyCannon()
{
}

void EnemyCannon::update()
{
	
}

