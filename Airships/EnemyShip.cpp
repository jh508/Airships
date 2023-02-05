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

void EnemyShip::shootPlayer(Player& player, std::vector<EnemyCannon*>& cannonVector)
{
	this->distanceToPlayer = sqrt(pow(this->enemyShipSprite.getPosition().x - player.playerSprite.getPosition().x, 2) +
		pow(this->enemyShipSprite.getPosition().y - player.playerSprite.getPosition().y, 2));

	if (this->distanceToPlayer < 700 && shootCoolDown <= 0) {
		EnemyCannon* enemyCannon = new EnemyCannon(this->enemyShipSprite);
		cannonVector.push_back(enemyCannon);
		std::cout << "Size: " << cannonVector.size() << std::endl;
		this->shootCoolDown += 500.0f;
	}
	else if (this->distanceToPlayer > 300)
	{
		this->shootCoolDown--;
	}
	
	

}

bool EnemyShip::isDead()
{
	if (this->lives <= 0)
	{
		return true;
	}

	return false;
}

void EnemyShip::update(Player& player, std::vector<EnemyCannon*>& cannonVector)
{
	this->enemyShipSprite.move(sf::Vector2f(0, verticalVelocity));
	this->shootPlayer(player, cannonVector);
	this->isDead();
}

