#pragma once
#include "Player.h"
#include "EnemyCannon.h"
#include <vector>

class EnemyShip{
public:
	EnemyShip(float xPos);
	~EnemyShip();

	//	Getters and Setters
	sf::Sprite getEnemyShip();
	int getEnemyShipLives();
	void setEnemyShipLives(int newLives);


	void update(Player& player, std::vector<EnemyCannon*>& cannonVector);
	bool isDead(Player& player);


private:

	//Initialization
	void initializeVariables();
	void initializeTexture();
	void initializeSprite(float xPos);
	void shootPlayer(Player& player, std::vector<EnemyCannon*>& cannonVector);

	// Private resources
	sf::Texture enemyShipTexture;
	sf::Sprite enemyShipSprite;

	// Private Variables
	float verticalVelocity;
	float shootCoolDown;
	float distanceToPlayer;
	int lives;

	
	

};