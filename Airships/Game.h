#pragma once

#include "Player.h"

class Game {
public:
	Game();
	~Game();

	bool getIsWindowOpen();
	void update();
	void renderBullet();
	void render();

	Player player;
	AirCannon* airCannonPtr;
	

private:

	sf::RenderWindow* gamewindow;
	sf::Event event;
	

	void initializeVariables();
	void initializeWindow();


	void updatePollEvents();
	void UpdateBullet();



	

};
