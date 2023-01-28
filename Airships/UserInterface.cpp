#include "UserInterface.h"


void UI::initializeTextures()
{
	this->heartTexture.loadFromFile("Sprites/heart.png");
}

void UI::initializeFont()
{
	if (!this->textFont.loadFromFile("Fonts/Akira.otf")) {
		std::cout << "Error loading font" << std::endl;
	}

}

void UI::initializeText()
{
	this->livesText.setFont(this->textFont);
	this->livesText.setFillColor(sf::Color::White);
	this->livesText.setCharacterSize(24);
	this->livesText.setPosition(65, 55);
}

void UI::initializeSprites()
{
	this->heartSprite.setTexture(this->heartTexture);
	this->heartSprite.setOrigin(sf::Vector2f(-50, -50));
}


UI::UI()
{
	this->initializeTextures();
	this->initializeFont();
	this->initializeText();
	this->initializeSprites();
}

UI::~UI()
{
}

void UI::update(Player& player)
{
	this->livesText.setString(std::to_string(player.lives));
}

void UI::renderUI(sf::RenderTarget* window)
{
	window->draw(this->heartSprite);
	window->draw(this->livesText);
}

