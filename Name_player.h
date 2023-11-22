#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

class Name_player
{
public:
	Name_player(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, sf::Event& event);
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);


	sf::Sprite background;
	sf::Texture background_tex;

	int current_name;

	sf::Font font;

	std::string player1NameString;
	sf::Text namePlayer1;

	std::string player2NameString;
	sf::Text namePlayer2;
	
	sf::Sprite player1_profile;
	sf::Sprite player2_profile;
	sf::Texture Profile1;
	sf::Texture Profile2;
	sf::Texture Profile3;
	sf::Texture Profile4;

	int here1;
	int here2;

	sf::Sprite move_left;
	sf::Texture move_tex_left;

	sf::Sprite move_right;
	sf::Texture move_tex_right;

	sf::Sprite move_left2;
	sf::Texture move_tex_left2;

	sf::Sprite move_right2;
	sf::Texture move_tex_right2;

	sf::RectangleShape __Name1;
	sf::RectangleShape __Name2;

	sf::Clock Time_name1;
	sf::Clock Time_name2;

	sf::Sound change_profile;
	sf::SoundBuffer change_profile_buffer;

	float centerX;

	bool enteringPlayer1Name = true;
	
	sf::SoundBuffer click_buffer;
	sf::Sound click;
};

