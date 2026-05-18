#include "playing.h"
#include <iostream>
playing::playing(){}
playing::~playing(){}
void playing::Initialize(){}
void playing::Load(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, std::string characterName, int currentLevel, GameStats& stats){
	stats.Reset();
	levelClock.restart();
	player.Load(characterName);
	player.clearProjectiles();
	enemy.Reset(currentLevel);
	enemy.Load();
	gamefps.Load();
	if (currentLevel == 1) {
		if (Map.loadFromFile("Assets/World/Map-1.png"))
		{
			mapSprite.setTexture(Map);
			mapSprite.setScale(sf::Vector2f(3, 3));
		}
		else std::cout << "Map-1 failed to load!" << std::endl;
	}
	else if (currentLevel == 2) {
		if (Map.loadFromFile("Assets/World/Map-2.png"))
		{
			mapSprite.setTexture(Map);
			mapSprite.setScale(sf::Vector2f(2.7, 3));
		}
		else std::cout << "Map-2 failed to load!" << std::endl;
	}
	else if (currentLevel == 3) {
		if (Map.loadFromFile("Assets/World/Map-3.png"))
		{
			mapSprite.setTexture(Map);
			mapSprite.setScale(sf::Vector2f(3, 4));
		}
		else std::cout << "Map-3 failed to load!" << std::endl;
	}
	if (!LevelFont.loadFromFile("Assets/Fonts/Graduate-Regular.ttf")) {
		std::cout << "Graduate Font failed to load!" << std::endl;
	}
	levelText.setFont(LevelFont);
	levelText.setCharacterSize(30);
	levelText.setStyle(sf::Text::Bold);
	levelText.setFillColor(sf::Color::Black);
	levelText.setPosition(sf::Vector2f(320, 20));

	std::string level = "LEVEL  " + std::to_string(currentLevel);
	levelText.setString(level);
}
void playing::Update(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, float deltatime, sf::RenderWindow& window, gamestate& currentState, GameStats& stats){
	gamefps.Update(deltatime);
	stats.timeTaken = levelClock.getElapsedTime().asSeconds();
	player.Update(deltatime, window, enemy, stats);
	enemy.Update(deltatime ,player.getCharacterSpritePosition(), stats);

	if (enemy.allEnemiesDead())
		currentState = gamestate::LevelComplete;
}

void playing::Draw(sf::RenderWindow& window, EnemyLogic& enemy, fps& gamefps, PlayerLogic& player, gamestate& currentState){
	window.draw(mapSprite);
	window.draw(levelText);
	player.Draw(window, currentState);
	enemy.Draw(window);
	gamefps.Draw(window);
}