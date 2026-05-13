#include "playing.h"
#include <iostream>
playing::playing(){}
playing::~playing(){}
void playing::Initialize(){}
void playing::Load(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, std::string characterName){
	player.Load(characterName);
	enemy.Load();
	gamefps.Load();
	if (Map.loadFromFile("Assets/World/Map-1.png")) {
		mapSprite.setTexture(Map);
		mapSprite.setScale(sf::Vector2f(3,3));
	}
	else {
		std::cout<<"Map texture failed to load!"<<std::endl;
	}
}
void playing::Update(PlayerLogic& player, EnemyLogic& enemy, fps& gamefps, float deltatime, sf::RenderWindow& window){
	gamefps.Update(deltatime);
	player.Update(deltatime, window, enemy);
	enemy.Update(deltatime ,player.getCharacterSpritePosition());
}

void playing::Draw(sf::RenderWindow& window, EnemyLogic& enemy, fps& gamefps, PlayerLogic& player){
	window.draw(mapSprite);
	player.Draw(window);
	enemy.Draw(window);
	gamefps.Draw(window);
}