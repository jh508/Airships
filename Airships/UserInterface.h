#pragma once
#include "Player.h"
#include <iostream>
class UI {
public:
	UI();
	~UI();

	void update(Player& player);

	void renderUI(sf::RenderTarget* window);

private:

	void initializeTextures();
	void initializeFont();
	void initializeText();
	void initializeSprites();
	sf::Sprite heartSprite;
	sf::Texture heartTexture;
	sf::Text livesText;
	sf::Text scoreText;
	sf::Text score;
	sf::Font textFont;
};