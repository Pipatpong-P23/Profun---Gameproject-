#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class howtoplay
{
public:
	howtoplay(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window , sf::Event& event );
	void Draw(sf::RenderWindow& window);
	void Loop(sf::RenderWindow& window);


	sf::Sprite Background_howtoplay;
	sf::Texture How_to_play;

};

