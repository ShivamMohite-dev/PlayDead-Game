#pragma once
#include<SFML/Graphics.hpp>
#include "MathLogic.h"
class EnemyLogic{
private:
	sf::Texture enemy;
	float enemyspeed;
	sf::RectangleShape boundingbox1, boundingbox2, boundingbox3;
	sf::Text enemyHealth1, enemyHealth2, enemyHealth3;
	sf::Font Graduate;
	sf::Sprite enemySprite1, enemySprite2, enemySprite3;
	int health1, health2, health3;
	sf::Vector2f moveDirection1, moveDirection2, moveDirection3;
	float directionTimer1, directionTimer2, directionTimer3;
	float directionChangeInterval;
public:
	EnemyLogic();
	~EnemyLogic();
	sf::FloatRect getEnemy1Bounds() { return enemySprite1.getGlobalBounds(); }
	sf::FloatRect getEnemy2Bounds() { return enemySprite2.getGlobalBounds(); }
	sf::FloatRect getEnemy3Bounds() { return enemySprite3.getGlobalBounds(); }
	int getEnemy1Health() { return health1; }
	int getEnemy2Health() { return health2; }
	int getEnemy3Health() { return health3; }
	void changeHealth(int enemyIndex, int hp);
	void Initialize();
	void Load();
	void Update(float deltatime, sf::Vector2f playerPos);
	void Draw(sf::RenderWindow& window);
};
