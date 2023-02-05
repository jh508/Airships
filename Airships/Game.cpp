#include "Game.h"
#include <iostream>

void Game::initializeVariables()
{
	this->airCannonPtr = nullptr;
	this->gamewindow = nullptr;
	this->zapperSpawnTimer = 20.0f;
	this->enemyShipSpawnTimer = 100.0f;
}

void Game::initializeTexture()
{
	this->worldTexture.loadFromFile("Sprites/background.png");
}

void Game::initializeSprite()
{
	this->worldBackground.setTexture(this->worldTexture);
}

void Game::initializeWindow()
{
	this->gamewindow = new sf::RenderWindow(sf::VideoMode(800, 800), "Game");
	this->gamewindow->setFramerateLimit(144);
}

bool Game::collisionIntersect()
{
	for (int i = 0; i < zapperArray.size(); i++) {
		if (this->player.playerSprite.getGlobalBounds().intersects(zapperArray[i]->zapperSprite.getGlobalBounds())) {
			delete zapperArray[i];
			zapperArray.erase(zapperArray.begin() + i);
			this->player.lives -= 1;
			return true;
		}
	}

	for (int i = 0; i < this->enemyCannonArray.size(); i++) {
		if (this->player.playerSprite.getGlobalBounds().intersects(this->enemyCannonArray[i]->enemyCannonSprite.getGlobalBounds())) {
			delete this->enemyCannonArray[i];
			this->enemyCannonArray.erase(this->enemyCannonArray.begin() + i);
			this->player.lives -= 1;
			return true;
		}
	}

	for (int i = 0; i < this->enemyShipArray.size(); i++)
	{
		for (int j = 0; j < this->player.airCannonProjectiles.size(); j++)
		{
			if (this->enemyShipArray[i]->enemyShipSprite.getGlobalBounds().intersects(this->player.airCannonProjectiles[j]->airCannonSprite.getGlobalBounds()) && !this->enemyShipArray[i]->isDead(this->player)) {
				delete this->player.airCannonProjectiles[j];
				this->player.airCannonProjectiles.erase(this->player.airCannonProjectiles.begin() + j);
				this->enemyShipArray[i]->lives--;
			}
		}
	}

	return false;

}

void Game::spawnZapper()
{
	if (this->zapperArray.size() < 3 && zapperSpawnTimer <= 0)
	{
		this->zapperRandomXPos = rand() % 700;
		ZapperEnemy* zapperEnemy = new ZapperEnemy(this->zapperRandomXPos);
		this->zapperArray.push_back(zapperEnemy);
		zapperSpawnTimer = 300.0f;
	}
	else {
		zapperSpawnTimer--;
	}
}

void Game::spawnEnemyShip()
{
	if (this->enemyShipArray.size() < 5 && this->enemyShipSpawnTimer <= 0) {
		this->enemyShipRandomXPos = rand() % 700;
		EnemyShip* enemyShip = new EnemyShip(this->enemyShipRandomXPos);
		this->enemyShipArray.push_back(enemyShip);
		this->enemyShipSpawnTimer = 150.0f;
	}
	else {
		this->enemyShipSpawnTimer--;
	}
}



Game::Game()
{
	this->initializeVariables();
	this->initializeTexture();
	this->initializeSprite();
	this->initializeWindow();
}

Game::~Game()
{
	delete this->gamewindow;
}


void Game::updateDeltaTime()
{
	/* Updates the deltaTime variable to create frame rate independant gameplay. (The time it takes to update and render one frame) */
	this->deltaTime = this->deltaTimeClock.restart().asSeconds();
}

void Game::updatePollEvents()
{
	/*
	@return void

	- Event polling
	*/
	while (this->gamewindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) 
		{
			this->gamewindow->close();
		}

	}
}

void Game::updateBullet()
{
	/*
	@return void

		- Loops through the projectile array and calls the objects update method.
	*/
	for (int i = 0; i < this->player.airCannonProjectiles.size(); i++)
	{
		this->player.airCannonProjectiles[i]->update();
	}
}

void Game::updateZapper()
{
	spawnZapper();
	

	for (int i = 0; i < this->zapperArray.size(); i++) {
		this->zapperArray[i]->update();
	}
}

void Game::updateEnemyShip()
{
	spawnEnemyShip();
	
	for (int i = 0; i < this->enemyShipArray.size(); i++) {
		this->enemyShipArray[i]->update(this->player, this->enemyCannonArray);
	}
}

void Game::updateEnemyCannon()
{
	for (int i = 0; i < this->enemyCannonArray.size(); i++) {
		this->enemyCannonArray[i]->update(this->player, this->deltaTime);
	}
}





void Game::update()
{
	/*
		@return void

		- Updates every frame.
	*/
	this->updateDeltaTime();
	this->updatePollEvents();
	this->updateBullet();
	this->updateZapper();
	this->updateEnemyShip();
	this->updateEnemyCannon();
	this->collisionIntersect();
	this->userInterface.update(this->player);
	this->player.update(this->gamewindow);
}


void Game::renderBullet()
{
	/*
		@return void

		- For every projectile stored in the container, draw the sprite.
		- if the Y position is less than 0 (out of bounds), delete the instantiated object.
		- Erase the object from the vector container
	*/

		for (int i = 0; i < this->player.airCannonProjectiles.size(); i++)
		{
			gamewindow->draw(this->player.airCannonProjectiles[i]->airCannonSprite);

			if (this->player.airCannonProjectiles[i]->airCannonSprite.getPosition().y < 0) {
				delete this->player.airCannonProjectiles[i];
				this->player.airCannonProjectiles.erase(this->player.airCannonProjectiles.begin() + i);
			}
	}

}

void Game::renderZapper()
{
	for (int i = 0; i < this->zapperArray.size(); i++) {
		this->gamewindow->draw(this->zapperArray[i]->zapperSprite);

		if (this->zapperArray[i]->zapperSprite.getPosition().y < 0)
		{
			delete this->zapperArray[i];
			this->zapperArray.erase(this->zapperArray.begin() + i);
		}
	}
}

void Game::renderEnemyShip()
{
	for (int i = 0; i < this->enemyShipArray.size(); i++)
	{

		if (!this->enemyShipArray[i]->isDead(this->player)) {
			this->gamewindow->draw(this->enemyShipArray[i]->enemyShipSprite);

			if (this->enemyShipArray[i]->enemyShipSprite.getPosition().y > 800) {
				delete this->enemyShipArray[i];
				enemyShipArray.erase(this->enemyShipArray.begin() + i);
			}
		}
		else if (this->enemyShipArray[i]->isDead(this->player)) {
			enemyShipArray.erase(this->enemyShipArray.begin() + i);
		}
	}
}

void Game::renderEnemyCannon()
{
	for (int i = 0; i < this->enemyCannonArray.size(); i++)
	{
		this->gamewindow->draw(this->enemyCannonArray[i]->enemyCannonSprite);

		if (this->enemyCannonArray[i]->enemyCannonSprite.getPosition().y > 800 || this->enemyCannonArray[i]->enemyCannonSprite.getPosition().y < 0) {
			delete this->enemyCannonArray[i];
			this->enemyCannonArray.erase(this->enemyCannonArray.begin() + i);
		}
		else if (this->enemyCannonArray[i]->enemyCannonSprite.getPosition().x > 800 || this->enemyCannonArray[i]->enemyCannonSprite.getPosition().x < 0)
		{
			delete this->enemyCannonArray[i];
			this->enemyCannonArray.erase(this->enemyCannonArray.begin() + i);
		}
	}
}

void Game::render()
{

	/*
	@return void

		- Main method for rendering
	*/

	if (!this->player.isDead()) {

		this->gamewindow->clear();
		this->gamewindow->draw(this->worldBackground);
		this->userInterface.renderUI(this->gamewindow);
		this->renderBullet();
		this->renderZapper();
		this->renderEnemyShip();
		this->renderEnemyCannon();
		this->gamewindow->draw(player.playerSprite);
		this->gamewindow->display();
	}
	else
	{
		this->gamewindow->clear(sf::Color::Black);
		this->userInterface.renderUI(this->gamewindow);
		this->gamewindow->display();
	}
}

bool Game::getIsWindowOpen()
{
	/*
	@return bool

		- returns whether the window is open. Used for looping in Main.cpp
	*/
	return this->gamewindow->isOpen();
}
