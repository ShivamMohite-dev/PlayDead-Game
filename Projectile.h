#pragma once
#include <SFML/Graphics.hpp>
class Projectile{
private:
	float speed, animTimer;
	sf::Vector2f direction;
	int currentFrame;   
	bool active;          
	sf::Sprite fireball_sprite, purpleflame_sprite, rasenshuriken_sprite;
public:
	Projectile();
	~Projectile();
	void Initialize();
	sf::FloatRect getFireballSpriteGlobalBounds() { return fireball_sprite.getGlobalBounds(); }
	sf::FloatRect getPurpleFlameSpriteGlobalBounds() { return purpleflame_sprite.getGlobalBounds(); }
	sf::FloatRect getRasenshurikenSpriteGlobalBounds() { return rasenshuriken_sprite.getGlobalBounds(); }
	void Load(sf::Texture& fireballTexture, sf::Texture& purpleflameTexture, sf::Texture& rasenshurikenTexture, sf::Vector2f startPos, sf::Vector2f direction);
	void Update(float deltatime, std::string mycharacter);
	bool isActive() { return active; }
	void Draw(sf::RenderWindow& window, std::string mycharacter);
};

