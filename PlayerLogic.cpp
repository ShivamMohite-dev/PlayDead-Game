#include "PlayerLogic.h"
#include<iostream>
PlayerLogic::PlayerLogic(): playerspeed(2.0f)
{
}

PlayerLogic::~PlayerLogic()
{
}

void PlayerLogic::Initialize()
{
}

void PlayerLogic::Load(std::string mycharacter)
{
	this->mycharacter = mycharacter;
	if (mycharacter == "Robin") {
		if (Character.loadFromFile("Assets/Player/Robin.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setScale(sf::Vector2f(0.3f, 0.3f));
			characterSprite.setPosition(sf::Vector2f(50, 50));
		}
		else {
			std::cout << "Sprite: Robin failed to load!";
		}
	}
	else if (mycharacter == "Frieren") {
		if (Character.loadFromFile("Assets/Player/Frieren.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setScale(sf::Vector2f(0.3f, 0.3f));
			characterSprite.setPosition(sf::Vector2f(50, 50));
		}
		else {
			std::cout << "Sprite: Frieren failed to load!";
		}
	}
	else {
		if (Character.loadFromFile("Assets/Player/Hinata.png")) {
			characterSprite.setTexture(Character);
			characterSprite.setScale(sf::Vector2f(0.3f, 0.3f));
			characterSprite.setPosition(sf::Vector2f(50, 50));
		}
		else {
			std::cout << "Sprite: Frieren failed to load!";
		}
	}
}

void PlayerLogic::Update(float deltatime)
{
	sf::Vector2f pos = characterSprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		characterSprite.setPosition(pos + sf::Vector2f(0.4, 0) * playerspeed * deltatime);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		characterSprite.setPosition(pos - sf::Vector2f(0.4, 0) * playerspeed * deltatime);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		characterSprite.setPosition(pos - sf::Vector2f(0, 0.4) * playerspeed * deltatime);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		characterSprite.setPosition(pos + sf::Vector2f(0, 0.4) * playerspeed * deltatime);
}

void PlayerLogic::Draw(sf::RenderWindow& window)
{
	
	window.draw(characterSprite);
}
