#pragma once
#include "Player.h"

class EnemyShip{
public:
	EnemyShip(float xPos);
	~EnemyShip();

	// Public resources
	sf::Sprite enemyShipSprite;

	void update(Player& player);

private:

	//Initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite(float xPos);
	void shootPlayer(Player& player);

	// Private resources
	sf::Texture enemyShipTexture;

	// Private Variables
	float verticalVelocity;
	int lives;
	float shootCoolDown;
	float distanceToPlayer;
	

};