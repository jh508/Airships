#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class ZapperEnemy {
public:
	ZapperEnemy();
	ZapperEnemy(float x);
	~ZapperEnemy();

	void update();

	//	Getters and Setters
	sf::Sprite getZapperSprite();


private:

	//	Initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite(float xPos);

	//	Sprites
	sf::Sprite zapperSprite;
	sf::Texture zapperTexture;

};