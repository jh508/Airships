#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class AirCannon {
public:

	AirCannon();
	~AirCannon();

	void update();
	sf::Sprite airCannonSprite;

private:

	//Initialization
	void initializeTexture();
	void initializeSprite();
	void initializeVariables();

	// Variables
	float projectileSpeed;
	
	sf::Texture airCannonTexture;
};