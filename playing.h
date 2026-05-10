#pragma once
#include <SFML/Graphics.hpp>
#include "CharacterSelect.h"
#include "PlayerLogic.h"
#include "fps.h"
#include "EnemyLogic.h"
class playing
{
private:
	sf::Texture Map;
	sf::Sprite mapSprite;
public:
	playing();
	~playing();
	void Initialize();
	void Load(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps,std::string characterName);
	void Update(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, float deltatime);
	void Draw(sf::RenderWindow& window, EnemyLogic& enemy, fps& gamefps, PlayerLogic& player);
};