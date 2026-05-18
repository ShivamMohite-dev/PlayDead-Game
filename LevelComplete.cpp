#include "LevelComplete.h"
#include <iostream>
void LevelComplete::Initialize()
{
}
void LevelComplete::Load(GameStats& stats)
{
    if (BackgroundTexture.loadFromFile("Assets/World/CharacterSelect-Texture.png")) {
        backgroundsprite.setTexture(BackgroundTexture);
    }

    if (bgaudio.openFromFile("Assets/Audio/UpdateLevel-bg.mp3")) {
        bgaudio.setLoop(true);
        bgaudio.setVolume(20.f);
        bgaudio.play();
    }
    else { std::cout << "Failed to Load next Level window Background audio" << std::endl; }

    if (commonui.loadFromFile("Assets/World/UI-1.png")) {
        websprite1.setTexture(commonui);
        websprite1.setScale(sf::Vector2f(0.4f,0.4f));
        websprite1.setPosition(sf::Vector2f(640,1));

        websprite2.setTexture(commonui);
        websprite2.setScale(sf::Vector2f(0.4f, 0.4f));
        websprite2.setRotation(270);
        websprite2.setPosition(sf::Vector2f(1, 198));
    }

    if (spideytexture1.loadFromFile("Assets/World/UI-2.png")) {
        spideysprite1.setTexture(spideytexture1);
        spideysprite1.setScale(sf::Vector2f(0.7f,0.7f));
        spideysprite1.setPosition(sf::Vector2f(-110,80));
    }

    if (spideytexture2.loadFromFile("Assets/World/UI-3.png")) {
        spideysprite2.setTexture(spideytexture2);
        spideysprite2.setScale(sf::Vector2f(0.4f, 0.4f));
        spideysprite2.setPosition(sf::Vector2f(140, 240));
    }

    if (luffy1texture.loadFromFile("Assets/World/Luffy-1.png")) {
        luffy1sprite.setTexture(luffy1texture);
        luffy1sprite.setScale(sf::Vector2f(0.7f, 0.7f));
        luffy1sprite.setPosition(sf::Vector2f(500, 240));
    }

    if (luffy2texture.loadFromFile("Assets/World/Luffy-2.png")) {
        luffy2sprite.setTexture(luffy2texture);
        luffy2sprite.setScale(sf::Vector2f(0.6f, 0.6f));
        luffy2sprite.setPosition(sf::Vector2f(280, 180));
    }

	if (font.loadFromFile("Assets/Fonts/Graduate-Regular.ttf")) {
		winningText.setFont(font);
		winningText.setCharacterSize(60);
		winningText.setStyle(sf::Text::Bold);
		winningText.setPosition(sf::Vector2f(135,60));
		winningText.setString("LEVEL COMPLETE");
		winningText.setFillColor(sf::Color(119, 7, 55));
	}

    if (clicksound.openFromFile("Assets/Audio/click.mp3")) {
        std::cout << "Click effect audio loaded successfully!" << std::endl;
        //clicksound.setLoop(true);
        clicksound.setVolume(30.f);
    }
    else {
        std::cout << "Click effect audio loading failed!" << std::endl;
    }

	nextlevelButton.setSize(sf::Vector2f(210,50));
	nextlevelButton.setOutlineColor(sf::Color::Black);
	nextlevelButton.setOutlineThickness(2);
	nextlevelButton.setPosition(sf::Vector2f(150,190));
	nextlevelButton.setFillColor(sf::Color::Transparent);
	exitButton.setSize(sf::Vector2f(210,50));
	exitButton.setOutlineColor(sf::Color::Black);
	exitButton.setOutlineThickness(2);
	exitButton.setPosition(sf::Vector2f(450,190));
	exitButton.setFillColor(sf::Color::Transparent);

	nextlevelbuttonText.setFont(font);
	nextlevelbuttonText.setString("NEXT LEVEL");
	nextlevelbuttonText.setCharacterSize(15);
	nextlevelbuttonText.setPosition(sf::Vector2f(160, 200));

	exitbuttonText.setFont(font);
	exitbuttonText.setString("EXIT");
	exitbuttonText.setCharacterSize(15);
	exitbuttonText.setPosition(sf::Vector2f(525, 200));

    nextlevelbuttonText.setCharacterSize(30);
    exitbuttonText.setCharacterSize(30);
    nextlevelbuttonText.setFillColor(sf::Color::Black);
    exitbuttonText.setFillColor(sf::Color::Black);
    nextlevelbuttonText.setStyle(sf::Text::Bold);
    exitbuttonText.setStyle(sf::Text::Bold);

    statsText.setFont(font);
    statsText.setCharacterSize(23);
    statsText.setFillColor(sf::Color(0, 153, 102));
    statsText.setStyle(sf::Text::Bold);
    statsText.setPosition(sf::Vector2f(225, 500));

    if (StatsBoxTexture.loadFromFile("Assets/World/StatsBox.png")) {
        statsboxsprite.setTexture(StatsBoxTexture);
        statsboxsprite.setScale(sf::Vector2f(0.9f,0.9f));
        statsboxsprite.setPosition(sf::Vector2f(110,400));
        statsboxsprite.setRotation(-5);
    }
}
void LevelComplete::Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState, int& currentLevel, GameStats& stats)
{
    // Hover effects
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    if (nextlevelButton.getGlobalBounds().contains(mousePosF))
    {
        nextlevelButton.setFillColor(sf::Color(0, 180, 0, 150));
        nextlevelButton.setOutlineColor(sf::Color::White);
    }
    else
    {
        nextlevelButton.setFillColor(sf::Color::Transparent);
        nextlevelButton.setOutlineColor(sf::Color::Black);
    }

    if (exitButton.getGlobalBounds().contains(mousePosF))
    {
        exitButton.setFillColor(sf::Color(180, 0, 0, 150));
        exitButton.setOutlineColor(sf::Color::White);
    }
    else
    {
        exitButton.setFillColor(sf::Color::Transparent);
        exitButton.setOutlineColor(sf::Color::Black);
    }

    // Click events
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

            if (nextlevelButton.getGlobalBounds().contains(mousePos))
            {
                if (currentLevel < 3)
                {
                    clicksound.play();
                    currentLevel++;
                    currentState = gamestate::Playing;
                }
                else {
                    window.close();
                }
            }
            if (exitButton.getGlobalBounds().contains(mousePos))
            {
                clicksound.play();
                window.close();
            }
        }
    }

    std::string stats_str =
        "Time Taken: " + std::to_string((int)stats.timeTaken) + "s\n" +
        "Projectiles Fired: " + std::to_string(stats.projectilesFired) + "\n" +
        "Projectiles Hit: " + std::to_string(stats.projectilesHit) + "\n" +
        "Enemies Eliminated: " + std::to_string(stats.enemiesEliminated) + "\n" +
        "Accuracy: " + std::to_string((int)stats.getAccuracy()) + "%";
    statsText.setString(stats_str);
}
void LevelComplete::Draw(sf::RenderWindow& window)
{
    window.draw(backgroundsprite);
    window.draw(websprite1);
    window.draw(websprite2);
    window.draw(spideysprite1);
    window.draw(spideysprite2);
    window.draw(luffy1sprite);
    window.draw(luffy2sprite);
	window.draw(winningText);
	window.draw(nextlevelButton);
	window.draw(exitButton);
	// In Draw() add:
	window.draw(nextlevelbuttonText);
	window.draw(exitbuttonText);
    window.draw(statsboxsprite);
    window.draw(statsText);
}