#include <iostream>
#include "Player.h"
#include "Game.h"

void Player::initializeVariables()
{
	this->horizontalVelocity = 2.0f;
	this->verticalVelocity = 3.0f;
	this->lives = 3;
	this->airCannonDelay = 30.0f;
	this->airCannonPtr = nullptr;
}

void Player::initializeTexture()
{
	if (!this->spriteTexture.loadFromFile("\Sprites/MainShip.png")) {
		std::cout << "Error loading sprite: MainShip.png";
	}
	

}

void Player::initializeSprite()
{
	this->playerSprite.setTexture(this->spriteTexture);
	this->playerSprite.setScale(sf::Vector2f(2.0f, 2.0f));

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

void Player::shoot(sf::RenderTarget* target)
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



void Player::updateInput(sf::RenderTarget* target)
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
		this->getPlayerPos();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		this->shoot(target);
	}

}


void Player::getPlayerPos()
{
	playerXPos = this->playerSprite.getPosition().x;
	playerYPos = this->playerSprite.getPosition().y;
	std::cout << "X Position: " << playerXPos << " Y Position: " << playerYPos << std::endl;

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

Player::Player()
{
	this->initializeTexture();
	this->initializeSprite();
	this->initializeVariables();

}

Player::~Player()
{
	
}

void Player::update(sf::RenderTarget* target)
{

	this->boundaryDetection(target);
	if (this->airCannonPtr != nullptr) {
		this->airCannonPtr->update();
	}
	this->updateInput(target);
	
}

