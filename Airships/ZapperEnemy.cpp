#include "ZapperEnemy.h"
#include <iostream>

void ZapperEnemy::initializeVariables()
{
	
}

void ZapperEnemy::initializeTexture()
{
	this->zapperTexture.loadFromFile("Sprites/zapper.png");
}

void ZapperEnemy::initializeSprite()
{
	this->zapperSprite.setTexture(this->zapperTexture);
	this->zapperSprite.setOrigin(sf::Vector2f(-400, -600));
}

ZapperEnemy::ZapperEnemy()
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();
}

ZapperEnemy::~ZapperEnemy()
{

}

void ZapperEnemy::update()
{
	this->zapperSprite.move(sf::Vector2f(0.0f, -2.0f));
}


