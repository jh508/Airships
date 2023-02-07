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

	// Public Methods
	void update(sf::RenderTarget* target);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void shoot();
	void restartGame();
	sf::Vector2f getStarterPos();
	bool isDead();

	std::vector<AirCannon*> airCannonProjectiles;

	// Public variables
	int lives;
	int score;

private:

	// initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite();

	sf::Vector2f starterPos;
	// Private Methods
	void updateInput();
	void boundaryDetection(sf::RenderTarget* target);

	// Sprite Manager
	void updateTexture();
	sf::Texture spriteTextureFull;
	sf::Texture spriteTextureSlight;
	sf::Texture spriteTextureLow;

	AirCannon* airCannonPtr;

	

	// Private Variables
	float verticalVelocity;
	float horizontalVelocity;
	float playerXPos;
	float playerYPos;
	float airCannonDelay;


	// Resources

};