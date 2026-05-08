#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.h"
class homepage
{
private:
    sf::Texture CommonTexture;
    sf::Font PlayfairFont;
    sf::Font AwesomeFont;
    sf::Sprite HomepageSprite;
    sf::Text TitleText;
    sf::Text GamenameText1, GamenameText2;
    sf::RectangleShape PlayButton, ExitButton;
    sf::Text PlayButtonText, ExitButtonText;
    sf::Music backgroundMusic;
    sf::Texture PlayerTexture;
    sf::Sprite PlayerSprite1;
public:
	homepage();
	~homepage();
	void Initialize();
	void Load(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState);
	void Draw(sf::RenderWindow& window);
};

