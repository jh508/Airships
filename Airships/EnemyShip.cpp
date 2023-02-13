#include "EnemyShip.h"


void EnemyShip::initializeVariables()
{
	
	this->lives = 2;
	this->verticalVelocity = 1.0f;
	this->shootCoolDown = 200.0f;
}

void EnemyShip::initializeTexture()
{
	if (!this->enemyShipTexture.loadFromFile("Sprites/EnemyShip.png")) {
		throw "Error loading textures";
	};
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

sf::Sprite EnemyShip::getEnemyShip()
{
	return this->enemyShipSprite;
}

int EnemyShip::getEnemyShipLives()
{
	return this->lives;
}

void EnemyShip::setEnemyShipLives(int newLives)
{
	this->lives += newLives;
}

void EnemyShip::shootPlayer(Player& player, std::vector<EnemyCannon*>& cannonVector)
{
	this->distanceToPlayer = sqrt(pow(this->enemyShipSprite.getPosition().x - player.getPlayer().getPosition().x, 2) +
		pow(this->enemyShipSprite.getPosition().y - player.getPlayer().getPosition().y, 2));

	if (this->distanceToPlayer < 700 && shootCoolDown <= 0) {
		EnemyCannon* enemyCannon = new EnemyCannon(this->enemyShipSprite);
		cannonVector.push_back(enemyCannon);
		this->shootCoolDown += 500.0f;
	}
	else if (this->distanceToPlayer > 300)
	{
		this->shootCoolDown--;
	}
}

bool EnemyShip::isDead(Player& player)
{
	if (this->lives <= 0)
	{
		player.setScore(1);
		return true;
	}

	return false;
}

void EnemyShip::update(Player& player, std::vector<EnemyCannon*>& cannonVector)
{
	this->enemyShipSprite.move(sf::Vector2f(0, verticalVelocity));
	this->shootPlayer(player, cannonVector);
	this->isDead(player);
}

