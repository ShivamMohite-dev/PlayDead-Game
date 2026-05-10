#pragma once
#include<SFML/Graphics.hpp>
class EnemyLogic
{
private:
	sf::Texture enemy;
	float enemyspeed;
public:
	sf::Sprite enemySprite1, enemySprite2, enemySprite3;
public:
	EnemyLogic();
	~EnemyLogic();
	void Initialize();
	void Load();
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};
