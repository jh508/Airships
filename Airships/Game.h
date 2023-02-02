#pragma once

#include "Player.h"
#include "UserInterface.h"
#include "ZapperEnemy.h"
#include <vector>

class Game {
public:
	// Constructor, Destructor
	Game();
	~Game();

	// Public Methods
	bool getIsWindowOpen();
	void update();
	void render();

	// Public Resources
	Player player;
	UI userInterface;
	AirCannon* airCannonPtr;
	std::vector<ZapperEnemy*> zapperArray;
	

private:

	// Private Variables
	float zapperSpawnTimer;
	float zapperRandomXPos;

	// Private Resources
	sf::RenderWindow* gamewindow;
	sf::Event event;
	sf::Texture worldTexture;
	sf::Sprite worldBackground;
	
	// Initialization Methods
	void initializeVariables();
	void initializeTexture();
	void initializeSprite();
	void initializeWindow();

	// Collision Methods
	bool collisionIntersect();

	// Zapper Methods
	void spawnZapper();

	// Update Methods
	void updatePollEvents();
	void updateBullet();
	void updateZapper();


	// Render Methods
	void renderBullet();
	void renderZapper();
	

};
