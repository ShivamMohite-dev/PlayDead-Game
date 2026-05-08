#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameState.h"
#include "homepage.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(836, 836), "PlayDead - 2D MULTILEVEL SHOOTING GAME");

    //------------------------------------------INITIALIZE-----------------------------//
    gamestate currentState = gamestate::Homepage; // Current game state

    homepage InitialHomepage;
    InitialHomepage.Initialize();
    //------------------------------------------INITIALIZE-----------------------------//
    

    //---------------------------------------------LOAD--------------------------------//

    InitialHomepage.Load(window);

    //---------------------------------------------LOAD--------------------------------//
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            //-------------------------------------UPDATE------------------------------//
            
            // Update based on current state
            switch (currentState)
            {
                case gamestate::Homepage:
                    InitialHomepage.Update(window, event, currentState);
                    break;

                case gamestate::Playing:
                    // game.Update() will go here later
                    break;

                case gamestate::Paused:
                    // pause.Update() will go here later
                    break;

                case gamestate::GameOver:
                    // gameover.Update() will go here later
                    break;
            }

            //-------------------------------------UPDATE------------------------------//
            
            //-------------------------------------DRAW-------------------------------//
            
            // Draw based on current state
            window.clear(sf::Color::Black);
            switch (currentState)
            {
            case gamestate::Homepage:
                InitialHomepage.Draw(window);
                break;

            case gamestate::Playing:
                // game.Draw() will go here later
                break;

            case gamestate::Paused:
                // pause.Draw() will go here later
                break;

            case gamestate::GameOver:
                // gameover.Draw() will go here later
                break;
            }
            window.display();

            //-------------------------------------DRAW-------------------------------//
        }

        
    }

    return 0;
}