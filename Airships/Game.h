#pragma once

#include "Player.h"
#include "UserInterface.h"
#include "ZapperEnemy.h"
#include "EnemyShip.h"
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

	// Public Containers
	std::vector<ZapperEnemy*> zapperArray;
	std::vector<EnemyShip*> enemyShipArray;
	std::vector<EnemyCannon*> enemyCannonArray;
	

private:

	// Private Variables
	float zapperSpawnTimer;
	float zapperRandomXPos;
	float enemyShipSpawnTimer;
	float enemyShipRandomXPos;

	// Delta Time variables
	sf::Clock deltaTimeClock;
	float deltaTime;

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


	// Spawner Methods
	void spawnZapper();
	void spawnEnemyShip();

	// Update Methods
	void updateDeltaTime();
	void updatePollEvents();
	void updateBullet();
	void updateZapper();
	void updateEnemyShip();
	void updateEnemyCannon();

	// Render Methods
	void renderBullet();
	void renderZapper();
	void renderEnemyShip();
	void renderEnemyCannon();
	

};
