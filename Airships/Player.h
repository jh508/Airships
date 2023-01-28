#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "AirCannon.h"
#include <vector>


class Player {
public:

	Player();
	~Player();

	sf::Sprite playerSprite;

	void update(sf::RenderTarget* target);
	void getPlayerPos();

	std::vector<AirCannon*> airCannonProjectiles;

	// Public variables
	int lives;
private:

	void initializeVariables();

	// initialization
	void initializeTexture();
	void initializeSprite();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void shoot(sf::RenderTarget* target);
	void updateInput(sf::RenderTarget* target);
	void boundaryDetection(sf::RenderTarget* target);

	AirCannon* airCannonPtr;


	sf::Texture spriteTexture;
	

	// Variables
	float verticalVelocity;
	float horizontalVelocity;
	float playerXPos;
	float playerYPos;
	float airCannonDelay;


	// Resources

};