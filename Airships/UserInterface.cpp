#include "UserInterface.h"


void UI::initializeTextures()
{
	if (!this->heartTexture.loadFromFile("Sprites/heart.png")) {
		throw "Error loading textures";
	}
}

void UI::initializeFont()
{
	if (!this->textFont.loadFromFile("Fonts/Akira.otf")) {
		throw "Error loading font";
	}

}

void UI::initializeText()
{
	// Lives Text
	this->livesText.setFont(this->textFont);
	this->livesText.setFillColor(sf::Color::White);
	this->livesText.setCharacterSize(24);
	this->livesText.setPosition(65, 55);

	// Score Text
	this->scoreText.setFont(this->textFont);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setCharacterSize(20);
	this->scoreText.setPosition(600, 55);
	this->scoreText.setString(scoreText.getString());

	// End Text
	this->endText.setFont(this->textFont);
	this->endText.setFillColor(sf::Color::White);
	this->endText.setCharacterSize(20);
	this->endText.setPosition(400, 55);
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
	if (!player.isDead()) {
		this->livesText.setString(std::to_string(player.lives));
		this->scoreText.setString("Score: " + std::to_string(player.score));
		this->endText.setString("Test");
	}
	else {
		this->livesText.setString("0");
	}

}

void UI::renderUI(sf::RenderTarget* window)
{
	window->draw(this->heartSprite);
	window->draw(this->livesText);
	window->draw(this->scoreText);
}

