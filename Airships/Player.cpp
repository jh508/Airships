#include <iostream>
#include "Player.h"
#include "Game.h"

void Player::initializeVariables()
{
	this->horizontalVelocity = 2.0f;
	this->starterPos = sf::Vector2f(400, 400);
	this->verticalVelocity = 3.0f;
	this->lives = 3;
	this->score = 0;
	this->airCannonDelay = 30.0f;
	this->airCannonPtr = nullptr;
}

void Player::initializeTexture()
{
	if (!this->spriteTextureFull.loadFromFile("Sprites/MainShip.png")) {
		throw "Error loading textures";
	}
	if (!this->spriteTextureSlight.loadFromFile("Sprites/MainShipSlightDamage.png")) {
		throw "Error loading textures";
	}
	if (!this->spriteTextureLow.loadFromFile("Sprites/MainShipLow.png")) {
		throw "Error loading textures";
	}
}

void Player::initializeSprite()
{
	this->playerSprite.setTexture(this->spriteTextureFull);
	this->playerSprite.setScale(sf::Vector2f(2.0f, 2.0f));
	this->playerSprite.setPosition(starterPos);

}

Player::Player()
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();

}

Player::~Player()
{
	
}

void Player::moveUp()
{
	this->playerSprite.move(sf::Vector2f(0.0f, -verticalVelocity));
}

void Player::moveDown()
{
	this->playerSprite.move(sf::Vector2f(0.0f, verticalVelocity));
}

void Player::moveRight()
{
	this->playerSprite.move(sf::Vector2f(horizontalVelocity, 0.0f));
}

void Player::moveLeft()
{
	this->playerSprite.move(sf::Vector2f(-horizontalVelocity, 0.0f));
}

void Player::shoot()
{
	if (this->airCannonDelay <= 0) {
		AirCannon* airCannonPtr = new AirCannon();
		airCannonPtr->airCannonSprite.setPosition(this->playerSprite.getPosition().x + 25, this->playerSprite.getPosition().y);
		airCannonProjectiles.push_back(airCannonPtr);
		airCannonDelay += 30;
	}
	else {
		airCannonDelay--;
	}
}

sf::Vector2f Player::getStarterPos()
{
	return this->starterPos;
}

bool Player::isDead()
{
	if (this->lives <= 0) { return true; }

	return false;
}

void Player::updateTexture()
{
	if (this->lives == 2) {
		this->playerSprite.setTexture(this->spriteTextureSlight);
	}
	if(this->lives == 1) {
		this->playerSprite.setTexture(this->spriteTextureLow);
	}
}



void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->moveUp();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->moveLeft();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->moveDown();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->moveRight();
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->shoot();
	}
}


void Player::boundaryDetection(sf::RenderTarget* target)
{

	//LEFT
	if (this->playerSprite.getPosition().x <= 0.0f) {
		this->playerSprite.setPosition(sf::Vector2f(0.0f, this->playerSprite.getPosition().y));
	}

	//RIGHT
	else if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= target->getSize().x) {
		this->playerSprite.setPosition(target->getSize().x - this->playerSprite.getGlobalBounds().width, this->playerSprite.getGlobalBounds().top);
	}

	//TOP
	if (this->playerSprite.getPosition().y <= 0.0f) {
		this->playerSprite.setPosition(sf::Vector2f(this->playerSprite.getPosition().x, 0.0f));
	}

	//BOTTOM
	else if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= target->getSize().y) {
		this->playerSprite.setPosition(this->playerSprite.getPosition().x, target->getSize().y - this->playerSprite.getGlobalBounds().height);
	}


}

void Player::update(sf::RenderTarget* target)
{
	this->boundaryDetection(target);
	if (this->airCannonPtr != nullptr) {
		this->airCannonPtr->update();
	}
	this->updateInput();
	this->updateTexture();
	
}

