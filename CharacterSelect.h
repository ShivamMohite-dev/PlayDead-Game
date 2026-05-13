#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.h"
class CharacterSelect{
private:
	std::string selectedcharacter, finalizedcharacter = "";
	sf::Font GraduateFont;
	sf::Texture backgroundTexture, robinTexture, frierenTexture, hinataTexture;
	sf::Sprite background_sprite, robin, hinata, frieren;
	sf::Text pickText, RobinNameText, FrierenNameText, HinataNameText, charname, selectText, abilityinfo, proceedText;
	sf::RectangleShape rect1, rect2, rect3, proceedbutton;
	sf::Music clicksound, hoversound;
public:
	CharacterSelect();
	~CharacterSelect();
	std::string getcharacter() { return finalizedcharacter; }
	void Initialize();
	void Load();
	void Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState);
	void Draw(sf::RenderWindow& window);
};

