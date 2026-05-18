#include "GameOver.h"
#include <iostream>
void GameOver::Load()
{
    if (bgtexture.loadFromFile("Assets/World/CharacterSelect-Texture.png")) {
        std::cout << "Background Texture Loaded Successfully" << std::endl;
        bgsprite.setTexture(bgtexture);
    }
    if (font.loadFromFile("Assets/Fonts/Graduate-Regular.ttf"))
    {
        gameOverText.setFont(font);
        gameOverText.setCharacterSize(70);
        gameOverText.setStyle(sf::Text::Bold);
        gameOverText.setFillColor(sf::Color::Red);
        gameOverText.setString("YOU DIED");
        gameOverText.setPosition(sf::Vector2f(230, 100));

        tryAgainButtonText.setFont(font);
        tryAgainButtonText.setCharacterSize(30);
        tryAgainButtonText.setFillColor(sf::Color::Black);
        tryAgainButtonText.setString("TRY AGAIN");
        tryAgainButtonText.setPosition(sf::Vector2f(168, 250));

        exitButtonText.setFont(font);
        exitButtonText.setCharacterSize(30);
        exitButtonText.setFillColor(sf::Color::Black);
        exitButtonText.setString("EXIT");
        exitButtonText.setPosition(sf::Vector2f(508, 250));

        message.setFont(font);
        message.setCharacterSize(23);
        message.setString("BETTER LUCK NEXT TIME");
        message.setStyle(sf::Text::Bold);
        message.setFillColor(sf::Color(45, 70, 185));
        message.setPosition(sf::Vector2f(220, 550));
    }
    if (commonui.loadFromFile("Assets/World/UI-1.png")) {
         websprite1.setTexture(commonui);
         websprite1.setScale(sf::Vector2f(0.4f, 0.4f));
         websprite1.setPosition(sf::Vector2f(640, 1));

         websprite2.setTexture(commonui);
         websprite2.setScale(sf::Vector2f(0.4f, 0.4f));
         websprite2.setRotation(270);
         websprite2.setPosition(sf::Vector2f(1, 198));
    }
    if (spideytexture1.loadFromFile("Assets/World/UI-2.png")) {
        spideysprite1.setTexture(spideytexture1);
        spideysprite1.setScale(sf::Vector2f(0.7f, 0.7f));
        spideysprite1.setPosition(sf::Vector2f(-110, 80));
     }

    if (spideytexture2.loadFromFile("Assets/World/UI-3.png")) {
        spideysprite2.setTexture(spideytexture2);
        spideysprite2.setScale(sf::Vector2f(0.4f, 0.4f));
        spideysprite2.setPosition(sf::Vector2f(140, 270));
     }
    if (luffy1texture.loadFromFile("Assets/World/Luffy-1.png")) {
        luffy1sprite.setTexture(luffy1texture);
        luffy1sprite.setScale(sf::Vector2f(0.7f, 0.7f));
        luffy1sprite.setPosition(sf::Vector2f(480, 244));
    }
    if (luffy2texture.loadFromFile("Assets/World/Luffy-2.png")) {
        luffy2sprite.setTexture(luffy2texture);
        luffy2sprite.setScale(sf::Vector2f(0.6f, 0.6f));
        luffy2sprite.setPosition(sf::Vector2f(280, 180));
    }
    if (StatsBoxTexture.loadFromFile("Assets/World/StatsBox.png")) {
         statsboxsprite.setTexture(StatsBoxTexture);
         statsboxsprite.setScale(sf::Vector2f(0.9f, 0.9f));
         statsboxsprite.setPosition(sf::Vector2f(110, 400));
         statsboxsprite.setRotation(-5);
    }
    tryAgainButton.setSize(sf::Vector2f(200, 60));
    tryAgainButton.setFillColor(sf::Color::Transparent);
    tryAgainButton.setOutlineColor(sf::Color::Black);
    tryAgainButton.setOutlineThickness(2);
    tryAgainButton.setPosition(sf::Vector2f(150, 240));

    exitButton.setSize(sf::Vector2f(200, 60));
    exitButton.setFillColor(sf::Color::Transparent);
    exitButton.setOutlineColor(sf::Color::Black);
    exitButton.setOutlineThickness(2);
    exitButton.setPosition(sf::Vector2f(450, 240));
}

void GameOver::Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState, bool& playingLoaded)
{
    // Hover effects
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (tryAgainButton.getGlobalBounds().contains(mousePosF))
    {
        tryAgainButton.setFillColor(sf::Color(0, 180, 0, 150));
        tryAgainButton.setOutlineColor(sf::Color::Green);
    }
    else
    {
        tryAgainButton.setFillColor(sf::Color::Transparent);
        tryAgainButton.setOutlineColor(sf::Color::White);
    }

    if (exitButton.getGlobalBounds().contains(mousePosF))
    {
        exitButton.setFillColor(sf::Color(180, 0, 0, 150));
        exitButton.setOutlineColor(sf::Color::Red);
    }
    else
    {
        exitButton.setFillColor(sf::Color::Transparent);
        exitButton.setOutlineColor(sf::Color::White);
    }

    // Click events
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (tryAgainButton.getGlobalBounds().contains(mousePos))
            {
                playingLoaded = false; // ← reload the level
                currentState = gamestate::Playing;
            }
            if (exitButton.getGlobalBounds().contains(mousePos))
            {
                window.close();
            }
        }
    }
}

void GameOver::Draw(sf::RenderWindow& window)
{
    window.draw(bgsprite);
    window.draw(gameOverText);
    window.draw(websprite1);
    window.draw(websprite2);
    window.draw(spideysprite1);
    window.draw(spideysprite2);
    window.draw(luffy1sprite);
    window.draw(luffy2sprite);
    window.draw(tryAgainButton);
    window.draw(exitButton);
    window.draw(tryAgainButtonText);
    window.draw(exitButtonText);
    window.draw(statsboxsprite);
    window.draw(message);
}