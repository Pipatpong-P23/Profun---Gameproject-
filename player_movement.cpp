#include "player_movement.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <vector>

PlayerMovement::PlayerMovement(sf::Sprite& sprite, sf::Texture& texture , float scale)
    : playerSprite(sprite), playerTexture(texture), scale_player(scale) ,currentFrame(0), frameTime(sf::seconds(0.1f)), isDPressed(false), isAPressed(false)
{
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
    playerSprite.setScale(sf::Vector2f(4.5, 4.5));
}

void PlayerMovement::moveLeft()
{
    if(set_scale.getElapsedTime().asSeconds() > 0.5 ) set_scale.restart() , scale = scale_player * 4.5;
    int movespeed = 11.f;
    playerSprite.move(-movespeed, 0.f);

    if (!isAPressed) {
        isAPressed = true;
        isDPressed = false;
        frameClock.restart();
        playerSprite.setOrigin(32, 0);
        playerSprite.setScale(sf::Vector2f(-scale, scale));
    }

    if (frameClock.getElapsedTime() >= frameTime) {
        frameClock.restart();
        currentFrame = ((currentFrame + 1) % 4);
        playerSprite.setTextureRect(sf::IntRect(currentFrame * 32, 96, 32, 32));
    }
}

void PlayerMovement::moveRight()
{
    if (set_scale.getElapsedTime().asSeconds() > 0.5) set_scale.restart(), scale = scale_player * 4.5;
    int movespeed = 11.f;
    playerSprite.move(movespeed, 0.f);

    if (!isDPressed) {
        isDPressed = true;
        isAPressed = false;
        frameClock.restart();
        playerSprite.setOrigin(0, 0);
        playerSprite.setScale(sf::Vector2f(scale, scale));
    }

    if (frameClock.getElapsedTime() >= frameTime) {
        frameClock.restart();
        currentFrame = ((currentFrame + 1) % 4);
        playerSprite.setTextureRect(sf::IntRect(currentFrame * 32, 96, 32, 32));
    }
}

void PlayerMovement::update()
{
    if (set_scale.getElapsedTime().asSeconds() > 0.5) set_scale.restart(), scale = scale_player * 4.5;
    if (!isDPressed || !isAPressed) {
        isDPressed = false; 
        isAPressed = false; 

        if (frameClock.getElapsedTime() >= frameTime) {
            frameClock.restart();
            currentFrame = ((currentFrame + 1) % 4);
            playerSprite.setTextureRect(sf::IntRect(currentFrame * 32, 64, 32, 32));
        }
    }
}