#include "Player.h"
#include "AirCannon.h"
#include <iostream>

void AirCannon::initializeTexture()
{
	this->airCannonTexture.loadFromFile("Sprites/zapper.png");
}

void AirCannon::initializeSprite()
{
	this->airCannonSprite.setTexture(this->airCannonTexture);
}

void AirCannon::initializeVariables()
{
	this->projectileSpeed = 3.0f;
}


AirCannon::AirCannon()
{
	this->initializeTexture();
	this->initializeSprite();
	this->initializeVariables();
}

AirCannon::~AirCannon()
{
	std::cout << "Deleted" << std::endl;
}


void AirCannon::update()
{
	this->airCannonSprite.move(sf::Vector2f(0.0f, -1.0f));
}