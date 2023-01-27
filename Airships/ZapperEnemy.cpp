#include "ZapperEnemy.h"
#include <iostream>

void ZapperEnemy::initializeVariables()
{
	this->damage = 1;
	this->verticalSpeed = 3.0f;
	this->spawnInterval = 20.0f;
}

void ZapperEnemy::initializeTexture()
{
	if (!this->zapperTexture.loadFromFile("Sprites/zapper.png")) { std::cout << "Error loading Zapper.png"; }

}

void ZapperEnemy::initializeSprite()
{
	this->zapperSprite.setTexture(this->zapperTexture);
}



ZapperEnemy::ZapperEnemy()
{
	this->initializeTexture();
	this->initializeSprite();
}

ZapperEnemy::~ZapperEnemy()
{
	std::cout << "Zapper spawn" << std::endl;
}

void ZapperEnemy::Update()
{
	this->zapperSprite.move(sf::Vector2f(0.0f, verticalSpeed));
}
