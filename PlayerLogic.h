#pragma once
#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include "CharacterSelect.h"
#include "EnemyLogic.h"
#include <vector>
class PlayerLogic{
private:
    sf::Texture Character, fireballTexture, purpleflameTexture, rasenshurikenTexture; // Fireball texture loaded once, shared across all fireballs
    float playerspeed, maxFirerate, Fireratetimer;
    std::vector<Projectile> projectiles;
    std::string mycharacter;
    sf::RectangleShape boundingbox;
    sf::Sprite characterSprite;
    sf::Vector2f boundingboxOffset;
    sf::Text playerHealth;
    sf::Font font;
    bool playerAlive;
public:
    PlayerLogic();
    ~PlayerLogic();
    std::string getcharacter() { return mycharacter; }
    const sf::Sprite getcharacterSprite() { return characterSprite; }
    sf::Vector2f getCharacterSpritePosition() { return characterSprite.getPosition(); }
    void Initialize();
    void Load(std::string mycharacter);
    void Update(float deltatime, sf::RenderWindow& window, EnemyLogic& enemy);
    void Draw(sf::RenderWindow& window);
};