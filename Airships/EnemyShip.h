#pragma once
#include "Player.h"
#include "EnemyCannon.h"
#include <vector>

class EnemyShip{
public:
	EnemyShip(float xPos);
	~EnemyShip();

	// Public resources
	sf::Sprite enemyShipSprite;

	void update(Player& player, std::vector<EnemyCannon*>& cannonVector);

private:

	//Initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite(float xPos);
	void shootPlayer(Player& player, std::vector<EnemyCannon*>& cannonVector);

	// Private resources
	sf::Texture enemyShipTexture;

	// Private Variables
	float verticalVelocity;
	int lives;
	float shootCoolDown;
	float distanceToPlayer;

	
	

};