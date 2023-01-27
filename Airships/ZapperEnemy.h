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

	void Update();

	float verticalSpeed;
	float randomNum;
	float spawnInterval;
	int damage = 1;

	sf::Sprite zapperSprite;
	std::vector<ZapperEnemy*> zapperArray;

private:

	void initializeVariables();

	void initializeTexture();
	void initializeSprite();

	sf::Texture zapperTexture;


};