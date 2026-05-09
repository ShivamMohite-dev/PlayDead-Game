#include "homepage.h"
#include <iostream>
homepage::homepage()
{
}
homepage::~homepage()
{
}

void homepage::Initialize()
{
}
void homepage::Load(sf::RenderWindow& window)
{
    if (CommonTexture.loadFromFile("Assets/World/Homepage-Texture.png")) {
        std::cout << "Initial Homepage texture loaded!" << std::endl;
        HomepageSprite.setTexture(CommonTexture);
    }
    else {
        std::cout << "Initial Homepage texture loading failed!" << std::endl;
    }

    if (PlayfairFont.loadFromFile("Assets/Fonts/Playfair_variable-font.ttf")) {
        std::cout << "\nPlayfair.ttf Font loaded successfully!" << std::endl;
        TitleText.setFont(PlayfairFont);
        TitleText.setString("Welcome Aboard");
        TitleText.setCharacterSize(90);
        TitleText.setFillColor(sf::Color(16, 42, 67));
        TitleText.setStyle(sf::Text::Bold);
        TitleText.setPosition(sf::Vector2f(45, 320));
    }
    else {
        std::cout << "Playfair.ttf Font loading failed!" << std::endl;
    }

    if (AwesomeFont.loadFromFile("Assets/Fonts/Awesome.ttf")) {
        std::cout << "Awesome.ttf Font loaded successfully!" << std::endl;
        // Game title
        GamenameText1.setFont(AwesomeFont);
        GamenameText2.setFont(AwesomeFont);
        GamenameText1.setString("PLAY");
        GamenameText2.setString("DEAD");
        GamenameText1.setCharacterSize(110);
        GamenameText2.setCharacterSize(110);
        GamenameText1.setFillColor(sf::Color(255, 248, 231));
        GamenameText2.setFillColor(sf::Color(255, 248, 231));
        GamenameText1.setStyle(sf::Text::Bold);
        GamenameText2.setStyle(sf::Text::Bold);
        GamenameText1.setPosition(sf::Vector2f(230, 10));
        GamenameText2.setPosition(sf::Vector2f(290, 140));

        // Button text
        PlayButtonText.setFont(AwesomeFont);
        ExitButtonText.setFont(AwesomeFont);
        PlayButtonText.setString("PLAY");
        ExitButtonText.setString("EXIT");
        PlayButtonText.setCharacterSize(30);
        ExitButtonText.setCharacterSize(30);
        PlayButtonText.setFillColor(sf::Color::Black);
        ExitButtonText.setFillColor(sf::Color::Black);
        PlayButtonText.setStyle(sf::Text::Bold);
        ExitButtonText.setStyle(sf::Text::Bold);
        PlayButtonText.setPosition(sf::Vector2f(220, 525));
        ExitButtonText.setPosition(sf::Vector2f(520, 525));
    }
    else {
        std::cout << "Awesome.ttf Font loading failed!" << std::endl;
    }

    PlayButton.setSize(sf::Vector2f(250, 50));
    ExitButton.setSize(sf::Vector2f(250, 50));
    PlayButton.setOutlineThickness(2);
    ExitButton.setOutlineThickness(2);
    PlayButton.setFillColor(sf::Color::Transparent);
    ExitButton.setFillColor(sf::Color::Transparent);
    PlayButton.setOutlineColor(sf::Color::Black);
    ExitButton.setOutlineColor(sf::Color::Black);
    PlayButton.setPosition(sf::Vector2f(140, 520));
    ExitButton.setPosition(sf::Vector2f(440, 520));

    if (PlayerTexture.loadFromFile("Assets/Player/Robin.png")) {
        std::cout << "Player 1 Sprite Loaded successfully!" << std::endl;
        PlayerSprite1.setTexture(PlayerTexture);
        PlayerSprite1.setPosition(sf::Vector2f(100, 620));
        PlayerSprite1.setScale(0.8f, 0.8f);
    }
    else {
        std::cout << "Player 1 Sprite failed to load!" << std::endl;
    }

    if (backgroundMusic.openFromFile("Assets/Audio/Homepage-BackgroundMusic.mp3"))
    {
        std::cout << "Background music loaded successfully!" << std::endl;
        backgroundMusic.setLoop(true);
        backgroundMusic.setVolume(40.f);
        backgroundMusic.play();
    }
    else
    {
        std::cout << "Background music loading failed!" << std::endl;
    }

    

    
}
void homepage::Update(sf::RenderWindow& window, sf::Event& event, gamestate& currentState)
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    // PLAY BUTTON HOVER
    if (PlayButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        PlayButton.setFillColor(sf::Color(16, 42, 67, 180));
        PlayButton.setOutlineColor(sf::Color(255, 248, 231));
        PlayButtonText.setFillColor(sf::Color(255, 248, 231));
    }
    else
    {
        PlayButton.setFillColor(sf::Color::Transparent);
        PlayButton.setOutlineColor(sf::Color::Black);
        PlayButtonText.setFillColor(sf::Color::Black);
    }
    // EXIT BUTTON HOVER
    if (ExitButton.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
    {
        ExitButton.setFillColor(sf::Color(120, 20, 20, 180));
        ExitButton.setOutlineColor(sf::Color(255, 248, 231));
        ExitButtonText.setFillColor(sf::Color(255, 248, 231));
    }
    else
    {
        ExitButton.setFillColor(sf::Color::Transparent);
        ExitButton.setOutlineColor(sf::Color::Black);
        ExitButtonText.setFillColor(sf::Color::Black);
    }

    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            // PLAY BUTTON CLICK
            if (PlayButton.getGlobalBounds().contains(mousePos))
            {
                std::cout << "PLAY BUTTON CLICKED!" << std::endl;
                backgroundMusic.stop();
                currentState = gamestate::CharacterSelect;
            }
            if (ExitButton.getGlobalBounds().contains(mousePos))
            {
                std::cout << "EXIT BUTTON CLICKED!" << std::endl;
                backgroundMusic.stop();
                window.close();
            }
        }
    }
}
void homepage::Draw(sf::RenderWindow& window)
{
    window.draw(HomepageSprite);
    window.draw(TitleText);
    window.draw(GamenameText1);
    window.draw(GamenameText2);
    window.draw(PlayButton);
    window.draw(ExitButton);
    window.draw(PlayButtonText);
    window.draw(ExitButtonText);
    window.draw(PlayerSprite1);
}
