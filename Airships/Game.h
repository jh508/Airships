#pragma once

#include "Player.h"
#include "UserInterface.h"

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
	

private:

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


	// Update Methods
	void updatePollEvents();
	void updateBullet();

	// Render Methods
	void renderBullet();

	

};
