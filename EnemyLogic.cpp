#include "EnemyLogic.h"
#include <iostream>
EnemyLogic::EnemyLogic() :enemyspeed(0.02f), health1(100), health2(100), health3(100), directionTimer1(0), directionTimer2(0), directionTimer3(0), directionChangeInterval(2000.f) {}
EnemyLogic::~EnemyLogic(){}
void EnemyLogic::changeHealth(int index, int hp)
{
    if (index == 1)
    {
        health1 += hp;
        enemyHealth1.setString(std::to_string(health1));
    }
    if (index == 2)
    {
        health2 += hp;
        enemyHealth2.setString(std::to_string(health2));
    }
    if (index == 3)
    {
        health3 += hp;
        enemyHealth3.setString(std::to_string(health3));
    }
}
void EnemyLogic::Initialize(){}
void EnemyLogic::Load() {
    if (enemy.loadFromFile("Assets/Enemies/skeleton.png")) {
        enemySprite1.setTexture(enemy); // Enemy-Sprite 1
        enemySprite1.setScale(0.2f, 0.2f);
        enemySprite1.setPosition(600, 300);
        enemySprite2.setTexture(enemy);// Enemy-Sprite 2
        enemySprite2.setScale(0.2f, 0.2f);
        enemySprite2.setPosition(600, 50);
        enemySprite3.setTexture(enemy);// Enemy-Sprite 3
        enemySprite3.setScale(0.2f, 0.2f);
        enemySprite3.setPosition(600, 600);
    }
    else {
        std::cout << "Sprite: skeleton loading failed!" << std::endl; // Delete this line of code, if plan to deploy somewhere
    }
    boundingbox1.setSize(sf::Vector2f(90, 90)); // Bounding box for Enemy sprite 1
    boundingbox1.setOutlineColor(sf::Color::Black);
    boundingbox1.setFillColor(sf::Color::Transparent);
    boundingbox1.setOutlineThickness(1);
    boundingbox2.setSize(sf::Vector2f(90, 90)); // Bounding box for Enemy sprite 2
    boundingbox2.setOutlineColor(sf::Color::Black);
    boundingbox2.setFillColor(sf::Color::Transparent);
    boundingbox2.setOutlineThickness(1);
    boundingbox3.setSize(sf::Vector2f(90, 90)); // Bounding box for Enemy sprite 3
    boundingbox3.setOutlineColor(sf::Color::Black);
    boundingbox3.setFillColor(sf::Color::Transparent);
    boundingbox3.setOutlineThickness(1);
    if (Graduate.loadFromFile("Assets/Fonts/Playfair_variable-font.ttf")) {
        enemyHealth1.setFont(Graduate);
        enemyHealth1.setCharacterSize(10);
        enemyHealth1.setStyle(sf::Text::Bold);
        enemyHealth1.setPosition(enemySprite1.getPosition());
        enemyHealth2.setFont(Graduate);
        enemyHealth2.setCharacterSize(10);
        enemyHealth2.setStyle(sf::Text::Bold);
        enemyHealth2.setPosition(enemySprite2.getPosition());
        enemyHealth3.setFont(Graduate);
        enemyHealth3.setCharacterSize(10);
        enemyHealth3.setStyle(sf::Text::Bold);
        enemyHealth3.setPosition(enemySprite3.getPosition());
    }
}
void EnemyLogic::Update(float deltatime, sf::Vector2f playerPos)
{
    // Enemy 1
    if (health1 > 0)
    {
        directionTimer1 += deltatime;
        if (directionTimer1 >= directionChangeInterval)
        {
            sf::Vector2f toPlayer = MathLogic::normalize(playerPos - enemySprite1.getPosition());
            float deviation = (rand() % 100 - 50) / 100.f;
            moveDirection1 = MathLogic::normalize(sf::Vector2f(toPlayer.x + deviation, toPlayer.y + deviation));
            directionTimer1 = 0;
        }
        enemySprite1.move(moveDirection1 * enemyspeed * deltatime);
        boundingbox1.setPosition(enemySprite1.getPosition());
        enemyHealth1.setPosition(enemySprite1.getPosition() + sf::Vector2f(0, -15.f)); // ← follows sprite, above head
        enemyHealth1.setString("Health: " + std::to_string(health1));
    }

    // Enemy 2
    if (health2 > 0)
    {
        directionTimer2 += deltatime;
        if (directionTimer2 >= directionChangeInterval)
        {
            sf::Vector2f toPlayer = MathLogic::normalize(playerPos - enemySprite2.getPosition());
            float deviation = (rand() % 200 - 100) / 100.f;
            moveDirection2 = MathLogic::normalize(sf::Vector2f(toPlayer.x + deviation, toPlayer.y + deviation));
            directionTimer2 = 0;
        }
        enemySprite2.move(moveDirection2 * enemyspeed * deltatime);
        boundingbox2.setPosition(enemySprite2.getPosition());
        enemyHealth2.setPosition(enemySprite2.getPosition() + sf::Vector2f(0, -15.f));
        enemyHealth2.setString("Health: " + std::to_string(health2));
    }

    // Enemy 3
    if (health3 > 0)
    {
        directionTimer3 += deltatime;
        if (directionTimer3 >= directionChangeInterval)
        {
            sf::Vector2f toPlayer = MathLogic::normalize(playerPos - enemySprite3.getPosition());
            float deviation = (rand() % 300 - 150) / 100.f;
            moveDirection3 = MathLogic::normalize(sf::Vector2f(toPlayer.x + deviation, toPlayer.y + deviation));
            directionTimer3 = 0;
        }
        enemySprite3.move(moveDirection3 * enemyspeed * deltatime);
        boundingbox3.setPosition(enemySprite3.getPosition());
        enemyHealth3.setPosition(enemySprite3.getPosition() + sf::Vector2f(0, -15.f));
        enemyHealth3.setString("Health: " + std::to_string(health3));
    }
}
void EnemyLogic::Draw(sf::RenderWindow& window){
    if (health1 > 0)
    {
        window.draw(enemySprite1);
        window.draw(boundingbox1);
        window.draw(enemyHealth1);
    }
    if (health2 > 0)
    {
        window.draw(enemySprite2);
        window.draw(boundingbox2);
        window.draw(enemyHealth2);
    }
    if(health3 > 0)
    {
        window.draw(enemySprite3);
        window.draw(boundingbox3);
        window.draw(enemyHealth3);
    }
    if (health3 == 0 && health2 == 0 && health1 == 0)
    {
        std::cout << "Enemies have been slained.....VICTORY" << std::endl;
        window.close();
    }
}