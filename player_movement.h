#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <vector>

class PlayerMovement
{
public:
    PlayerMovement(sf::Sprite& sprite, sf::Texture& texture , float scale);

    void moveLeft();
    void moveRight();
    void update();

    float scale_player ;
   
    sf::Texture& playerTexture;

private:
    sf::Sprite& playerSprite;
    sf::Clock set_scale; 
    float scale;
    int currentFrame;
    sf::Clock frameClock;
    sf::Time frameTime;
    
    bool isDPressed;
    bool isAPressed;

};

