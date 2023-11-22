#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Game.h"
#include "main_menu.h"

int WinMain()
{
    sf::RenderWindow window(sf::VideoMode(1440, 810), "WAR OF GHOST" );
    window.setFramerateLimit(60);

    main_menu menu(window);
    
}
