#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gamestate.h"
#include "GameStats.h"
class LevelComplete
{
private:
	sf::Font font;
	sf::Texture BackgroundTexture, StatsBoxTexture, commonui, spideytexture1, spideytexture2, luffy1texture, luffy2texture;
	sf::Sprite backgroundsprite, statsboxsprite, websprite1, websprite2, spideysprite1, spideysprite2, luffy1sprite, luffy2sprite;
	sf::Text winningText, nextlevelbuttonText, exitbuttonText, statsText;
	sf::RectangleShape nextlevelButton, exitButton;
	sf::Music bgaudio, clicksound;
public:
	void Initialize();
	void Load(GameStats& stats);
	void Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState, int& currentLevel, GameStats& stats);
	void Draw(sf::RenderWindow& window);
};

