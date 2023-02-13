#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class AirCannon {
public:

	AirCannon();
	~AirCannon();

	void update();

	//	Getters and Setters
	sf::Sprite getSprite();
	void setSpritePos(sf::Vector2f pos);


private:

	//	Initialization
	void initializeTexture();
	void initializeSprite();
	void initializeVariables();

	//	Variables
	float projectileSpeed;

	//	Sprite and Texture
	sf::Sprite airCannonSprite;
	sf::Texture airCannonTexture;
};