#include "Name_player.h"
#include "main_menu.h"
#include "Game.h"

Name_player::Name_player(sf::RenderWindow& window)
{
	font.loadFromFile("Font_score.ttf");
	namePlayer1.setFont(font);
	namePlayer1.setString("");
	namePlayer1.setPosition(131, 660);
	namePlayer1.setCharacterSize(54);
	namePlayer1.setFillColor(sf::Color::Black);

	namePlayer2.setFont(font);
	namePlayer2.setString("");
	namePlayer2.setPosition(888, 660);
	namePlayer2.setCharacterSize(54);
	namePlayer2.setFillColor(sf::Color::Black);

	background_tex.loadFromFile("choose__profile.png");
	background.setTexture(background_tex);
	background.setPosition(0, 0);
	
	Profile1.loadFromFile("Profile1.png");
	Profile2.loadFromFile("Profile2.png");
	Profile3.loadFromFile("Profile3.png");
	Profile4.loadFromFile("Profile4.png");
	
	player1_profile.setTexture(Profile2);
	player1_profile.setPosition(178, 194);

	player2_profile.setTexture(Profile3);
	player2_profile.setPosition(945, 212);
	
	here1 = 2;
	here2 = 3;

	move_tex_left.loadFromFile("button_play_left.png");
	move_tex_right.loadFromFile("button_play_right.png");
	
	move_tex_left2.loadFromFile("button_play_left.png");
	move_tex_right2.loadFromFile("button_play_right.png");

	move_left.setTexture(move_tex_left);
	move_right.setTexture(move_tex_left);

	move_left.setScale(-0.5 ,0.5);
	move_left.setPosition(595, 440);
	move_left.setOrigin(52,0);

	move_right.setScale(0.5, 0.5);
	move_right.setPosition(97, 440);

	//***********2

	move_left2.setTexture(move_tex_left2);
	move_right2.setTexture(move_tex_left2);

	move_left2.setScale(0.5, 0.5);
	move_left2.setPosition(855, 440);
	move_left2.setOrigin(0, 0);

	move_right2.setScale(-0.5, 0.5);
	move_right2.setOrigin(52, 0);
	move_right2.setPosition(1353, 440);


	__Name1.setOrigin(0, 0);
	__Name1.setSize(sf::Vector2f(4, 65));
	__Name1.setFillColor(sf::Color::Black);
	__Name1.setPosition(window.getSize().x / 2.0f - namePlayer1.getLocalBounds().width / 2.0f - 400 , 660 );

	__Name2.setOrigin(0, 0);
	__Name2.setSize(sf::Vector2f(4, 65));
	__Name2.setFillColor(sf::Color::Black);
	__Name2.setPosition(window.getSize().x / 2.0f - namePlayer2.getLocalBounds().width / 2.0f   , 660);

	click_buffer.loadFromFile("click.mp3");
	click.setBuffer(click_buffer);
	click.setVolume(50);

	change_profile_buffer.loadFromFile("sound_control_3.mp3");
	change_profile.setBuffer(change_profile_buffer);
	change_profile.setVolume(50);

	Loop(window);
}

void Name_player::Update(sf::RenderWindow& window, sf::Event& event)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Escape) main_menu main_menu(window);

			if (event.key.code == sf::Keyboard::Left && enteringPlayer1Name && here1 != 1 )change_profile.play() , here1--;
			else if (event.key.code == sf::Keyboard::Left && !enteringPlayer1Name && here2 != 1 )change_profile.play(), here2--;
			
			if (event.key.code == sf::Keyboard::Right && enteringPlayer1Name && here1 != 4) change_profile.play(), here1++;
			else if (event.key.code == sf::Keyboard::Right && !enteringPlayer1Name && here2 != 4) change_profile.play(), here2++;

			if (event.key.code == sf::Keyboard::Return && player1NameString.size() != 0) {
				if (enteringPlayer1Name ) {
					enteringPlayer1Name = false; 
				}
				else {
					Game game(window, player1NameString, player2NameString , here1 , here2 );
				}
			}
		}

		if (event.type == sf::Event::TextEntered) {
			if (enteringPlayer1Name) {
				centerX = window.getSize().x / 2.0f - namePlayer1.getLocalBounds().width / 2.0f;
				namePlayer1.setPosition(centerX - 400 , 660);
				if (event.text.unicode == '\b' && player1NameString.size() != 0 && event.text.unicode != '\r') {
					player1NameString.erase(player1NameString.size() - 1, 1);
					Time_name1.restart();
					click.play();

				}
				else if (player1NameString.size() <= 9 && event.text.unicode != '\r' && ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z') || (event.text.unicode == ' ') || (event.text.unicode == '_'))) {
					player1NameString += event.text.unicode;
					Time_name1.restart();
					click.play();


				}
				namePlayer1.setString(player1NameString);
			}
			else {
				centerX = window.getSize().x / 2.0f - namePlayer2.getLocalBounds().width / 2.0f;
				namePlayer2.setPosition(centerX + 400 , 660);
				if (event.text.unicode == '\b' && player2NameString.size() != 0 && event.text.unicode != '\r') {
					player2NameString.erase(player2NameString.size() - 1, 1);
					Time_name2.restart();
			
					click.play();
				}
				else if (player2NameString.size() <= 9 && event.text.unicode != '\r' && ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') || (event.text.unicode >= 'a' && event.text.unicode <= 'z') || (event.text.unicode == ' ') || (event.text.unicode == '_'))) {
					player2NameString += event.text.unicode;
				
					Time_name2.restart();
					click.play();
				}
				namePlayer2.setString(player2NameString);
			}
		}

		if (here1 == 1 ) {
			player1_profile.setTexture(Profile1);
		}
		else if (here1 == 2 ) {
			player1_profile.setTexture(Profile2);
		}
		else if (here1 == 3 ) {
			player1_profile.setTexture(Profile3);
		}
		else if (here1 == 4 ) {
			player1_profile.setTexture(Profile4);
		}

		if (here2 == 1) {
			player2_profile.setTexture(Profile1);
		}
		else if (here2 == 2) {
			player2_profile.setTexture(Profile2);
		}
		else if (here2 == 3) {
			player2_profile.setTexture(Profile3);
		}
		else if (here2 == 4) {
			player2_profile.setTexture(Profile4);
		}
		if(enteringPlayer1Name)__Name1.setPosition(namePlayer1.getGlobalBounds().left + namePlayer1.getGlobalBounds().width , namePlayer1.getPosition().y);
		if(!enteringPlayer1Name)__Name2.setPosition(namePlayer2.getGlobalBounds().left + namePlayer2.getGlobalBounds().width, namePlayer2.getPosition().y);

	}
}

void Name_player::Draw(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(namePlayer1);
	window.draw(namePlayer2);

	window.draw(player1_profile);
	window.draw(player2_profile);

	if (here1 != 4) window.draw(move_left);
	if (here1 != 1) window.draw(move_right);

	if (here2 != 1) window.draw(move_left2);
	if (here2 != 4) window.draw(move_right2);

	if (Time_name1.getElapsedTime().asSeconds() < 1.2 && enteringPlayer1Name) window.draw(__Name1);
	else if (Time_name1.getElapsedTime().asSeconds() > 1.9 && enteringPlayer1Name ) Time_name1.restart();
	if (Time_name2.getElapsedTime().asSeconds() < 1.2 && !enteringPlayer1Name) window.draw(__Name2);
	else if (Time_name2.getElapsedTime().asSeconds() > 1.9 && !enteringPlayer1Name)Time_name2.restart();

}

void Name_player::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(window, event);
		Draw(window);
		window.display();
	}
}


