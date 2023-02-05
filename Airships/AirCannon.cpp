#include "Player.h"
#include "AirCannon.h"
#include <iostream>

void AirCannon::initializeTexture()
{
	if (!this->airCannonTexture.loadFromFile("Sprites/airCannon.png")) {
		throw "Error loading textures";
	}
}

void AirCannon::initializeSprite()
{
	this->airCannonSprite.setTexture(this->airCannonTexture);
}

void AirCannon::initializeVariables()
{
	this->projectileSpeed = 2.5f;
}


AirCannon::AirCannon()
{
	this->initializeTexture();
	this->initializeSprite();
	this->initializeVariables();
}

AirCannon::~AirCannon()
{
	
}


void AirCannon::update()
{
	this->airCannonSprite.move(sf::Vector2f(0.0f, -projectileSpeed));
}


