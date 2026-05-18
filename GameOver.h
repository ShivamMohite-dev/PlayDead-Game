#pragma once
#include <SFML/Graphics.hpp>
#include "gamestate.h"

class GameOver
{
private:
    sf::Font font;
    sf::Texture bgtexture, StatsBoxTexture, commonui, spideytexture1, spideytexture2, luffy1texture, luffy2texture;
    sf::Sprite bgsprite, statsboxsprite, websprite1, websprite2, spideysprite1, spideysprite2, luffy1sprite, luffy2sprite;
    sf::Text gameOverText, message;
    sf::Text tryAgainButtonText, exitButtonText;
    sf::RectangleShape tryAgainButton, exitButton;
public:
    void Load();
    void Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState, bool& playingLoaded);
    void Draw(sf::RenderWindow& window);
};