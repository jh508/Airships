#pragma once

#include "Player.h"
#include "ZapperEnemy.h"
#include "UserInterface.h"

class Game {
public:
	Game();
	~Game();

	bool getIsWindowOpen();
	void update();
	void render();

	Player player;
	UI userInterface;
	AirCannon* airCannonPtr;
	

private:

	sf::RenderWindow* gamewindow;
	sf::Event event;
	sf::Texture worldTexture;
	sf::Sprite worldBackground;
	

	void initializeVariables();
	void initializeTexture();
	void initializeSprite();
	void initializeWindow();

	void updatePollEvents();
	void updateBullet();


	void renderBullet();

	

};
