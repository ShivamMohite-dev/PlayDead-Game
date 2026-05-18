#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "homepage.h"
#include "CharacterSelect.h"
#include "playing.h"
#include "PlayerLogic.h"
#include "fps.h"
#include "EnemyLogic.h"
#include "LevelComplete.h"
#include "gamestate.h"
#include "GameStats.h"
#include "GameOver.h"
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

    GameStats stats;

    int currentLevel = 1;
    LevelComplete levelcomplete;
    levelcomplete.Load(stats);


    GameOver gameover;
    gameover.Load();
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

            case gamestate::GameOver:
                gameover.Update(window, event, currentState, playingLoaded);
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
                playwindow.Load(player, enemy, ingamefps, character.getcharacter(), currentLevel, stats);
                playingLoaded = true;
            }
            playwindow.Update(player, enemy, ingamefps, deltatime, window, currentState, stats);
            break;

        case gamestate::LevelComplete:
            levelcomplete.Update(window, event, currentState, currentLevel, stats);
            if (currentState == gamestate::Playing) // ← state just changed to Playing
                playingLoaded = false; // ← reset so Load() gets called again
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
            playwindow.Draw(window,enemy, ingamefps, player, currentState);
            break;
        case gamestate::LevelComplete:
            levelcomplete.Draw(window);
            break;
        case gamestate::GameOver:
            gameover.Draw(window);
            break;
        default: break;
        }
        window.display();
    }
    return 0;
}

