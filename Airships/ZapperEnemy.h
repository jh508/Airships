#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
#include <vector>

class ZapperEnemy {
public:
	ZapperEnemy();
	~ZapperEnemy();

	

	std::vector<ZapperEnemy*> zapperEnemyArray;
	sf::Sprite zapperSprite;

private:

	void initializeVariables();

	void initializeTexture();
	void initializeSprite();

	sf::Texture zapperTexture;

};