#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSelect.h"
#include "PlayerLogic.h"
#include "fps.h"
#include "GameStats.h"
#include "EnemyLogic.h"
class playing{
private:
	sf::Texture Map;
	sf::Sprite mapSprite;
	sf::Font LevelFont;
	sf::Text levelText;
	sf::Clock levelClock;
public:
	playing();
	~playing();
	void Initialize();
	void Load(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps,std::string characterName, int currentLevel, GameStats& stats);
	void Update(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, float deltatime, sf::RenderWindow& window, gamestate& currentState, GameStats& stats);
	void Draw(sf::RenderWindow& window, EnemyLogic& enemy, fps& gamefps, PlayerLogic& player, gamestate& currentState);
};