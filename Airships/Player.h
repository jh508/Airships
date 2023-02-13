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



	//	Public Methods
	void update(sf::RenderTarget* target);
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void shoot();

	//	Getters and Setter
	sf::Sprite getPlayer();
	sf::Vector2f getStarterPos();
	int getScore();
	void setScore(int newScore);
	int getLives();
	void setLives(int newLives);

	//	Booleans
	bool isDead();

	std::vector<AirCannon*> airCannonProjectiles;

private:

	//	initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite();


	//	Private Methods
	void updateInput();
	void boundaryDetection(sf::RenderTarget* target);

	//	Sprite Manager
	void updateTexture();
	sf::Sprite playerSprite;
	sf::Texture spriteTextureFull;
	sf::Texture spriteTextureSlight;
	sf::Texture spriteTextureLow;

	//	Private Pointers
	AirCannon* airCannonPtr;


	//	Private Variables
	sf::Vector2f starterPos;
	float verticalVelocity;
	float horizontalVelocity;
	float playerXPos;
	float playerYPos;
	float airCannonDelay;
	int lives;
	int score;

};