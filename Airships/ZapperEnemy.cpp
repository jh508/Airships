#include "ZapperEnemy.h"
#include <iostream>

void ZapperEnemy::initializeVariables()
{
	
}

void ZapperEnemy::initializeTexture()
{
	this->zapperTexture.loadFromFile("Sprites/zapper.png");
}

void ZapperEnemy::initializeSprite(float xPos)
{
	this->zapperSprite.setTexture(this->zapperTexture);
	this->zapperSprite.setPosition(sf::Vector2f(xPos, 800));
}

ZapperEnemy::ZapperEnemy()
{

}

ZapperEnemy::ZapperEnemy(float x)
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite(x);
}

ZapperEnemy::~ZapperEnemy()
{
	
}

void ZapperEnemy::update()
{
	this->zapperSprite.move(sf::Vector2f(0.0, -2.0));
}




