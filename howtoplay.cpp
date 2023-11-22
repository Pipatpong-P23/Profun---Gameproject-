#include "howtoplay.h"
#include "main_menu.h"

howtoplay::howtoplay(sf::RenderWindow& window)
{
	How_to_play.loadFromFile("how_to_play.png");
	Background_howtoplay.setTexture(How_to_play);
	Loop(window);
}

void howtoplay::Update(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Escape) {
				main_menu main_menu(window);
			}
		}
	}
}

void howtoplay::Draw(sf::RenderWindow& window)
{
	window.draw(Background_howtoplay);
}

void howtoplay::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(window, event);
		Draw(window);
		window.display();
	}
}
