#include "EnemyLogic.h"
#include <iostream>
EnemyLogic::EnemyLogic()
{
}

EnemyLogic::~EnemyLogic()
{
}

void EnemyLogic::Initialize()
{
}

void EnemyLogic::Load()
{
    if (enemy.loadFromFile("Assets/Enemies/skeleton.png"))
    {
        enemySprite1.setTexture(enemy);
        enemySprite1.setScale(0.2f, 0.2f);
        enemySprite1.setPosition(400, 300);

        enemySprite2.setTexture(enemy);
        enemySprite2.setScale(0.2f, 0.2f);
        enemySprite2.setPosition(600, 50);

        enemySprite3.setTexture(enemy);
        enemySprite3.setScale(0.2f, 0.2f);
        enemySprite3.setPosition(500, 500);
    }
    else {
        std::cout << "Sprite: skeleton loading failed!" << std::endl;
    }
}

void EnemyLogic::Update(float deltatime)
{
}

void EnemyLogic::Draw(sf::RenderWindow& window)
{
	window.draw(enemySprite1);
	window.draw(enemySprite2);
	window.draw(enemySprite3);
}
