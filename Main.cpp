#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "homepage.h"
#include "CharacterSelect.h"
#include "playing.h"
#include "PlayerLogic.h"
#include "fps.h"
#include "EnemyLogic.h"
#include <iostream>
int main()
{
    sf::RenderWindow window(sf::VideoMode(836, 836), "PlayDead - 2D MULTILEVEL SHOOTING GAME");
    window.setFramerateLimit(60);
    //------------------------------------------INITIALIZE-----------------------------//
    gamestate currentState = gamestate::Homepage;
    bool playingLoaded = false;

    homepage InitialHomepage;
    InitialHomepage.Initialize();

    CharacterSelect character;
    character.Initialize();

    playing playwindow;
    playwindow.Initialize();

    PlayerLogic player;
    player.Initialize();

    fps ingamefps;
    ingamefps.Initialize();

    EnemyLogic enemy;
    enemy.Initialize();
    //------------------------------------------INITIALIZE-----------------------------//

    //---------------------------------------------LOAD--------------------------------//
    InitialHomepage.Load(window);
    character.Load();
    //---------------------------------------------LOAD--------------------------------//

    sf::Clock clock;
    while (window.isOpen())
    {
        float deltatime = clock.restart().asMilliseconds();

        // Event loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            switch (currentState)
            {
            case gamestate::Homepage:
                InitialHomepage.Update(window, event, currentState);
                break;
            case gamestate::CharacterSelect:
                character.Update(window, event, currentState);
                break;
            default: break;
            }
        }

        // Update
        switch (currentState)
        {
        case gamestate::Playing:
            if (!playingLoaded)
            {
                playwindow.Load(player, enemy, ingamefps, character.getcharacter());
                playingLoaded = true;
            }
            playwindow.Update(player, enemy, ingamefps, deltatime, window);
            break;
        default: break;
        }

        // Draw
        window.clear(sf::Color::Black);
        switch (currentState)
        {
        case gamestate::Homepage:
            InitialHomepage.Draw(window);
            break;
        case gamestate::CharacterSelect:
            character.Draw(window);
            break;
        case gamestate::Playing:
            playwindow.Draw(window,enemy, ingamefps, player);
            break;
        default: break;
        }
        window.display();
    }
    return 0;
}

