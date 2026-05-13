#include "Projectile.h"
#include<iostream>
Projectile::Projectile() : speed(0.2f), animTimer(0), currentFrame(0), active(true) {}
Projectile::~Projectile(){}
void Projectile::Initialize(){}
void Projectile::Load(sf::Texture& fireballTexture, sf::Texture& purpleflameTexture, sf::Texture& rasenshurikenTexture, sf::Vector2f startPos, sf::Vector2f direction){
    this->direction = direction;

    fireball_sprite.setTexture(fireballTexture);
    fireball_sprite.setTextureRect(sf::IntRect(0, 0, 200, 200));
    fireball_sprite.setScale(0.4f, 0.4f);
    fireball_sprite.setPosition(startPos + sf::Vector2f(80,30));

    purpleflame_sprite.setTexture(purpleflameTexture);
    purpleflame_sprite.setTextureRect(sf::IntRect(0, 0, 64, 32));
    purpleflame_sprite.setScale(1.4f, 1.4f);
    purpleflame_sprite.setRotation(20);
    purpleflame_sprite.setPosition(startPos + sf::Vector2f(100,60));

    rasenshuriken_sprite.setTexture(rasenshurikenTexture);
    rasenshuriken_sprite.setTextureRect(sf::IntRect(0, 0, 257, 157));
    rasenshuriken_sprite.setScale(0.3f, 0.3f);
    rasenshuriken_sprite.setPosition(startPos + sf::Vector2f(50,30));

    currentFrame = 0;
    animTimer = 0;
    active = true;
}
void Projectile::Update(float deltatime, std::string mycharacter) {
    if (active){
        if (mycharacter == "Robin") {
            fireball_sprite.move(direction * speed * deltatime); // Moving the projectile
            // Animate through spritesheet frames
            animTimer += deltatime;
            if (animTimer >= 50.f) {
                currentFrame = (currentFrame + 1) % 30;
                int col = currentFrame % 5;
                int row = currentFrame / 5;
                fireball_sprite.setTextureRect(sf::IntRect(col * 200, row * 200, 200, 200));
                animTimer = 0;
            }
            // Deactivate if out of bounds
            sf::Vector2f pos = fireball_sprite.getPosition();
            if (pos.x < 0 || pos.x > 1920 || pos.y < 0 || pos.y > 1080)
                active = false;
        }
        if (mycharacter == "Frieren") {
            purpleflame_sprite.move(direction * speed * deltatime); // Moving the projectile
            // Animate through spritesheet frames
            animTimer += deltatime;
            if (animTimer >= 50.f) {
                currentFrame = (currentFrame + 1) % 30;
                int col = currentFrame % 5;
                int row = currentFrame / 5;
                purpleflame_sprite.setTextureRect(sf::IntRect(col * 64, row * 32, 64, 32));
                animTimer = 0;
            }
            // Deactivate if out of bounds
            sf::Vector2f pos = purpleflame_sprite.getPosition();
            if (pos.x < 0 || pos.x > 1920 || pos.y < 0 || pos.y > 1080)
                active = false;
        }
        if (mycharacter == "Hinata") {
            rasenshuriken_sprite.move(direction * speed * deltatime); // Moving the projectile
            // Animate through spritesheet frames
            animTimer += deltatime;
            if (animTimer >= 50.f) {
                currentFrame = (currentFrame + 1) % 30;
                int col = currentFrame % 5;
                int row = currentFrame / 5;
                rasenshuriken_sprite.setTextureRect(sf::IntRect(col * 257, row * 157, 257, 157));
                animTimer = 0;
            }
            // Deactivate if out of bounds
            sf::Vector2f pos = rasenshuriken_sprite.getPosition();
            if (pos.x < 0 || pos.x > 1920 || pos.y < 0 || pos.y > 1080)
                active = false;
        }
    }
    else {
        return;
    }
}
void Projectile::Draw(sf::RenderWindow& window, std::string mycharacter){
    if(mycharacter == "Robin")
	    window.draw(fireball_sprite);
    if (mycharacter == "Frieren")
        window.draw(purpleflame_sprite);
    if (mycharacter == "Hinata")
        window.draw(rasenshuriken_sprite);
}
