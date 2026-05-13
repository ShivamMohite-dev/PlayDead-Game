#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.h"
class homepage{
private:
    sf::Text TitleText, GamenameText1, GamenameText2, PlayButtonText, ExitButtonText;
    sf::Texture CommonTexture, PlayerTexture;
    sf::Sprite HomepageSprite, PlayerSprite1;
    sf::Font PlayfairFont, AwesomeFont;
    sf::RectangleShape PlayButton, ExitButton;
    sf::Music backgroundMusic;
public:
	homepage();
	~homepage();
	void Initialize();
	void Load(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState);
	void Draw(sf::RenderWindow& window);
};

