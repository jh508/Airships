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


