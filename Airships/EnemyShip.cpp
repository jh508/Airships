#include "EnemyShip.h"
#include <iostream>

void EnemyShip::initializeVariables()
{
	
	this->lives = 2;
	this->verticalVelocity = 1.0f;
	this->shootCoolDown = 200.0f;
}

void EnemyShip::initializeTexture()
{
	this->enemyShipTexture.loadFromFile("Sprites/EnemyShip.png");
}

void EnemyShip::initializeSprite(float xPos)
{
	this->enemyShipSprite.setTexture(this->enemyShipTexture);
	this->enemyShipSprite.setScale(sf::Vector2f(1.5, 1.5));
	this->enemyShipSprite.setPosition(xPos, 0);
	
}


EnemyShip::EnemyShip(float xPos)
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite(xPos);
}

EnemyShip::~EnemyShip()
{
	
}

void EnemyShip::shootPlayer(Player& player)
{
	distanceToPlayer = sqrt(pow(this->enemyShipSprite.getPosition().x - player.playerSprite.getPosition().x, 2) + 
		pow(this->enemyShipSprite.getPosition().y - player.playerSprite.getPosition().y, 2));

	if (distanceToPlayer < 400.0f && this->shootCoolDown <= 0)
	{
		AirCannon enemyProjectile;

		enemyProjectile.airCannonSprite.setPosition(sf::Vector2f(this->enemyShipSprite.getPosition()));
	}
	

}

void EnemyShip::update(Player& player)
{
	this->enemyShipSprite.move(sf::Vector2f(0, verticalVelocity));
	shootPlayer(player);
}

