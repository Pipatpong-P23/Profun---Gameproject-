#include "player2_movement.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <math.h>
#include <vector>

Player2Movement::Player2Movement(sf::Sprite& sprite, sf::Texture& texture , float scale)
    : playerSprite(sprite), playerTexture(texture), scale_player(scale), currentFrame(0), frameTime(sf::seconds(0.1f)), isRight_Pressed(false), isLeft_Pressed(false)
{
    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect(0, 64, 32, 32));
    playerSprite.setOrigin(32, 0);
    playerSprite.setScale(sf::Vector2f(-4.5, 4.5));
}

void Player2Movement::moveLeft2()
{
    if (set_scale.getElapsedTime().asSeconds() > 0.5) scale = scale_player * 4.5, set_scale.restart(); ;
    int movespeed = 11.f;
    playerSprite.move(-movespeed, 0.f);

    if (!isLeft_Pressed) {
        isLeft_Pressed = true;
        isRight_Pressed = false;
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

void Player2Movement::moveRight2()
{
    if (set_scale.getElapsedTime().asSeconds() > 0.5) scale = scale_player * 4.5, set_scale.restart(); ;
    int movespeed = 11.f;
    playerSprite.move(movespeed, 0.f);

    if (!isRight_Pressed) {
        isRight_Pressed = true;
        isLeft_Pressed = false;
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

void Player2Movement::update2()
{
    if (set_scale.getElapsedTime().asSeconds() > 0.5) scale = scale_player * 4.5, set_scale.restart(); ;
    if (!isRight_Pressed || !isLeft_Pressed) {
        isLeft_Pressed = false; // ÃÕà«çµãËé»ØèÁ D äÁè¶Ù¡¡´¤éÒ§
        isRight_Pressed = false; // ÃÕà«çµãËé»ØèÁ A äÁè¶Ù¡¡´¤éÒ§

        if (frameClock.getElapsedTime() >= frameTime) {
            frameClock.restart();
            currentFrame = ((currentFrame + 1) % 4);
            playerSprite.setTextureRect(sf::IntRect(currentFrame * 32, 64, 32, 32));
        }
    }
}
