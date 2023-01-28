#include "Game.h"
#include <iostream>

void Game::initializeVariables()
{
	this->airCannonPtr = nullptr;
	this->gamewindow = nullptr;

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


void Game::updatePollEvents()
{
	while (this->gamewindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->gamewindow->close();
	}
}

void Game::updateBullet()
{
	for (int i = 0; i < this->player.airCannonProjectiles.size(); i++)
	{
		this->player.airCannonProjectiles[i]->update();
	}
}


void Game::update()
{
	this->updatePollEvents();
	this->updateBullet();
	this->userInterface.update(this->player);
	this->player.update(this->gamewindow);
}


void Game::renderBullet()
{
		for (int i = 0; i < this->player.airCannonProjectiles.size(); i++)
		{
			gamewindow->draw(this->player.airCannonProjectiles[i]->airCannonSprite);

			if (this->player.airCannonProjectiles[i]->airCannonSprite.getPosition().y < 0) {
				delete this->player.airCannonProjectiles[i];
				this->player.airCannonProjectiles.erase(this->player.airCannonProjectiles.begin() + i);
			}
	}

}

void Game::render()
{
	this->gamewindow->clear();
	this->gamewindow->draw(this->worldBackground);
	this->userInterface.renderUI(this->gamewindow);
	this->gamewindow->draw(player.playerSprite);
	this->renderBullet();
	this->gamewindow->display();

}

bool Game::getIsWindowOpen()
{
	return this->gamewindow->isOpen();
}
