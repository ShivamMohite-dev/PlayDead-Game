#include "PlayerLogic.h"
#include "MathLogic.h"
#include<iostream>
PlayerLogic::PlayerLogic(): playerspeed(2.0f), maxFirerate(200.0f), Fireratetimer(0), playerAlive(true){}
PlayerLogic::~PlayerLogic(){}
void PlayerLogic::Initialize(){}
void PlayerLogic::Load(std::string mycharacter){
    playerAlive = true;
	this->mycharacter = mycharacter;
	characterSprite.setScale(sf::Vector2f(0.3f, 0.3f));
	if (mycharacter == "Robin") {
		if (Character.loadFromFile("Assets/Player/Robin.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setPosition(sf::Vector2f(-10, 30));
			boundingbox.setSize(sf::Vector2f(110, 140));
			boundingboxOffset = sf::Vector2f(70, 0);
		}
		else {
			std::cout << "Sprite: Robin failed to load!";
		}
	}
	else if (mycharacter == "Frieren") {
		if (Character.loadFromFile("Assets/Player/Frieren.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setPosition(sf::Vector2f(50, 50));
			boundingbox.setSize(sf::Vector2f(140, 150));
			boundingboxOffset = sf::Vector2f(0, 0);
		}
		else {
			std::cout << "Sprite: Frieren failed to load!";
		}
	}
	else {
		if (Character.loadFromFile("Assets/Player/Hinata.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setPosition(sf::Vector2f(50, 50));
			boundingbox.setSize(sf::Vector2f(140, 150));
			boundingboxOffset = sf::Vector2f(0, 0);
		}
		else {
			std::cout << "Sprite: Frieren failed to load!";
		}
	}
	boundingbox.setOutlineColor(sf::Color::Black);
	boundingbox.setFillColor(sf::Color::Transparent);
	boundingbox.setPosition(characterSprite.getPosition() + boundingboxOffset);
	boundingbox.setOutlineThickness(1);
	//-----------------------NEW LINE OF CODE ADDED---------------------------------------------//
	if (fireballTexture.loadFromFile("Assets/Projectiles/Fireball/Fireball_Spritesheet.png")) {
		std::cout << "Fireball spritesheet loaded successfully" << std::endl;
	}
	else { std::cout << "Fireball spritesheet loading failed" << std::endl; };
	if (purpleflameTexture.loadFromFile("Assets/Projectiles/Fireball/purpleflame_Spritesheet.png")) {
		std::cout << "Purple Flame spritesheet loaded successfully" << std::endl;
	}
	else { std::cout << "Fireball spritesheet loading failed" << std::endl; };
	if (rasenshurikenTexture.loadFromFile("Assets/Projectiles/Fireball/Rasenshuriken_Spritesheet.png")) {
		std::cout << "Rasenshuriken spritesheet loaded successfully" << std::endl;
	}
	else { std::cout << "Fireball spritesheet loading failed" << std::endl; };
	//-----------------------NEW LINE OF CODE ADDED---------------------------------------------//

}
void PlayerLogic::Update(float deltatime, sf::RenderWindow& window, EnemyLogic& enemy, GameStats& stats)
{
    if (playerAlive) {
        sf::Vector2f pos = characterSprite.getPosition();
        boundingbox.setPosition(characterSprite.getPosition() + boundingboxOffset);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            characterSprite.setPosition(pos + sf::Vector2f(0.4, 0) * playerspeed * deltatime);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            characterSprite.setPosition(pos - sf::Vector2f(0.4, 0) * playerspeed * deltatime);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            characterSprite.setPosition(pos - sf::Vector2f(0, 0.4) * playerspeed * deltatime);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            characterSprite.setPosition(pos + sf::Vector2f(0, 0.4) * playerspeed * deltatime);

        Fireratetimer += deltatime;
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && Fireratetimer >= maxFirerate) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            sf::Vector2f playerPos = characterSprite.getPosition() + sf::Vector2f(30, 30);
            sf::Vector2f direction = MathLogic::normalize(mousePos - playerPos);
            Projectile p;
            p.Load(fireballTexture, purpleflameTexture, rasenshurikenTexture, playerPos, direction);
            projectiles.push_back(p);
            Fireratetimer = 0;
            stats.projectilesFired++;
        }

        for (int i = 0; i < (int)projectiles.size(); i++) {
            projectiles[i].Update(deltatime, mycharacter);

            bool hit = false;

            if (mycharacter == "Robin") {
                if (MathLogic::checkCollision(projectiles[i].getFireballSpriteGlobalBounds(), enemy.getEnemy1Bounds()) && enemy.getEnemy1Health() > 0)
                {
                    enemy.changeHealth(1, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getFireballSpriteGlobalBounds(), enemy.getEnemy2Bounds()) && enemy.getEnemy2Health() > 0)
                {
                    enemy.changeHealth(2, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getFireballSpriteGlobalBounds(), enemy.getEnemy3Bounds()) && enemy.getEnemy3Health() > 0)
                {
                    enemy.changeHealth(3, -10); hit = true;
                }
            }
            if (mycharacter == "Frieren") {
                if (MathLogic::checkCollision(projectiles[i].getPurpleFlameSpriteGlobalBounds(), enemy.getEnemy1Bounds()) && enemy.getEnemy1Health() > 0)
                {
                    enemy.changeHealth(1, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getPurpleFlameSpriteGlobalBounds(), enemy.getEnemy2Bounds()) && enemy.getEnemy2Health() > 0)
                {
                    enemy.changeHealth(2, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getPurpleFlameSpriteGlobalBounds(), enemy.getEnemy3Bounds()) && enemy.getEnemy3Health() > 0)
                {
                    enemy.changeHealth(3, -10); hit = true;
                }
            }
            if (mycharacter == "Hinata") {
                if (MathLogic::checkCollision(projectiles[i].getRasenshurikenSpriteGlobalBounds(), enemy.getEnemy1Bounds()) && enemy.getEnemy1Health() > 0)
                {
                    enemy.changeHealth(1, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getRasenshurikenSpriteGlobalBounds(), enemy.getEnemy2Bounds()) && enemy.getEnemy2Health() > 0)
                {
                    enemy.changeHealth(2, -10); hit = true;
                }
                else if (MathLogic::checkCollision(projectiles[i].getRasenshurikenSpriteGlobalBounds(), enemy.getEnemy3Bounds()) && enemy.getEnemy3Health() > 0)
                {
                    enemy.changeHealth(3, -10); hit = true;
                }
            }

            if (hit) {
                stats.projectilesHit++;
                stats.enemiesEliminated = 3 - (
                    (enemy.getEnemy1Health() > 0 ? 1 : 0) +
                    (enemy.getEnemy2Health() > 0 ? 1 : 0) +
                    (enemy.getEnemy3Health() > 0 ? 1 : 0)
                    );
                projectiles.erase(projectiles.begin() + i);
                i--;
                continue;
            }
        }

        // Cleanup
        projectiles.erase(
            std::remove_if(projectiles.begin(), projectiles.end(),
                [](Projectile& p) { return !p.isActive(); }),
            projectiles.end());

        if (MathLogic::checkCollision(characterSprite.getGlobalBounds(), enemy.getEnemy1Bounds()) && enemy.getEnemy1Health() > 0)
            playerAlive = false;
        if (MathLogic::checkCollision(characterSprite.getGlobalBounds(), enemy.getEnemy2Bounds()) && enemy.getEnemy2Health() > 0)
            playerAlive = false;
        if (MathLogic::checkCollision(characterSprite.getGlobalBounds(), enemy.getEnemy3Bounds()) && enemy.getEnemy3Health() > 0)
            playerAlive = false;
    }
}
void PlayerLogic::Draw(sf::RenderWindow& window, gamestate& currentState){
	if (playerAlive) {
		window.draw(characterSprite);
		window.draw(boundingbox);
		for (auto& f : projectiles)
			f.Draw(window, mycharacter);
	}
	else {
		currentState = gamestate::GameOver; // ← state change instead of window.close()
	}
}