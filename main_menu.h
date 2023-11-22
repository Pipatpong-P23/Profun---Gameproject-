#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class main_menu
{
public:
	main_menu(sf::RenderWindow &window );
	void Update(sf::RenderWindow &window , sf::Event &event) ;
	void Draw(sf::RenderWindow &window );
	void Loop(sf::RenderWindow &window );

	sf::Font font;
	sf::Text credit;
	sf::Text creadit_up; 
	sf::Text credit_down;
	
	int here;
	
	//background 
	sf::Sprite BG_menu_sp;
	sf::Texture BG_menu_tx;

	//sound 
	sf::SoundBuffer Soundbuffer_control;
	sf::Sound Sound_control;

	sf::SoundBuffer FireBuffer_sound;
	sf::Sound Fire_sound;

	sf::Text NamePoohh;
};

