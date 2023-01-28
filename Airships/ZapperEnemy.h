#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <vector>

class ZapperEnemy {
public:
	ZapperEnemy();
	~ZapperEnemy();

	void update();


	sf::Sprite zapperSprite;

private:

	void initializeVariables();
	void initializeTexture();
	void initializeSprite();

	sf::Texture zapperTexture;

};