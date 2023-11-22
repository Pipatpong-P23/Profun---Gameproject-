#include "main_menu.h"
#include "Game.h"
#include "Ranking.h"
#include "Name_player.h"
#include "howtoplay.h"


main_menu::main_menu(sf::RenderWindow& window)
{
	font.loadFromFile("Fontgame.ttf");
	credit.setFont(font);

	credit.setString("CONTROL");
	credit.setFillColor(sf::Color:: White);
	credit.setCharacterSize(44);
	credit.setPosition(190, 479);
	
	
	creadit_up.setFont(font);
	creadit_up.setString("PLAY");
	creadit_up.setFillColor(sf::Color::Red);
	creadit_up.setCharacterSize(48);
	creadit_up.setPosition(223 , 325);

	credit_down.setFont(font);
	credit_down.setString("SCORE");
	credit_down.setFillColor(sf::Color::White);
	credit_down.setCharacterSize(48);
	credit_down.setPosition(215, 631);

	//name 
	NamePoohh.setFont(font);
	NamePoohh.setString("66010572 Pipatpong panpruake");
	NamePoohh.setFillColor(sf::Color::White);
	NamePoohh.setCharacterSize(48);
	NamePoohh.setPosition(15, 0);

	//background
	BG_menu_tx.loadFromFile("menu_new.png");
	BG_menu_sp.setTexture(BG_menu_tx);
	BG_menu_sp.setPosition(0.f, 0.f);
	
	//choose menu 
	here = 1 ;
	
	Soundbuffer_control.loadFromFile("sound_control_3.mp3");
	Sound_control.setBuffer(Soundbuffer_control);



	Loop(window);

}

void main_menu::Update(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased ) {
			if (event.key.code == sf::Keyboard::Escape) {
				window.close();
			}
			if (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::J) {//Enter
				if(here == 1 ) Name_player Name_player(window) ; // play 
				else if (here == 2)howtoplay howtoplay(window) ; //how to play 
				else if (here == 3) Ranking Ranking(window); // ranking 
			}
			if ((event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W) && here != 1 ) {
				here--;
				Sound_control.play();
			}
			if ((event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)&& here != 3) {
				here++;
				Sound_control.play();
			}
		}
		if (here == 1 ) { // credit_up
			creadit_up.setFillColor(sf::Color::Red); 
			credit.setFillColor(sf::Color::White);
			credit_down.setFillColor(sf::Color::White);
		}
		else if (here == 2) { // credit
			creadit_up.setFillColor(sf::Color::White);
			credit.setFillColor(sf::Color::Red);
			credit_down.setFillColor(sf::Color::White);
		}
		else if (here == 3) { // credit_down
			creadit_up.setFillColor(sf::Color::White);
			credit.setFillColor(sf::Color::White);
			credit_down.setFillColor(sf::Color::Red);
		}
	

	}
}

void main_menu::Draw(sf::RenderWindow& window)
{
	window.draw(BG_menu_sp);
	window.draw(credit); //draw something
	window.draw(creadit_up);
	window.draw(credit_down);
	window.draw(NamePoohh); 

}

void main_menu::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(window , event);
		Draw(window);
		window.display();
	}
}
