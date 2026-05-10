#pragma once
#include<SFML/Graphics.hpp>
#include "CharacterSelect.h"

class PlayerLogic
{
private:
	sf::Texture Character;
	std::string mycharacter;
	float playerspeed;
public:
	sf::Sprite characterSprite;

public:
	PlayerLogic(); 
	~PlayerLogic(); 
	std::string getcharacter() { return mycharacter; }
	void Initialize();
	void Load(std::string mycharacter);
	void Update(float deltatime);
	void Draw(sf::RenderWindow& window);
};
