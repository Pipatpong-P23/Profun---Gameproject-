#include "Ranking.h"
#include "main_menu.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


Ranking::Ranking(sf::RenderWindow &window)
{
//init
	Background_ranking_tex.loadFromFile("Ranking_board.png");
	Bakground_ranking_sp.setTexture(Background_ranking_tex);
	Bakground_ranking_sp.setPosition(1.f,1.f);

    std::vector<HighScoreEntry> highScores = LoadHighScores("highscores.oakkun");

    for (int i = 0; i < highScores.size(); i++) {
        how_many_score = i;
        std::cout << highScores[i].playerProfile<< " " << highScores[i].playerName << " " << highScores[i].score << "\n";
    }


    font.loadFromFile("Font_score.ttf");

    Score_TOP.setFont(font);
    Score_TOP.setString("TOP SCORE");
    Score_TOP.setFillColor(sf::Color::Black);
    Score_TOP.setCharacterSize(48);
    Score_TOP.setPosition(288, 97);

    if (how_many_score >= 0) {////////////////////////////////top1
        Name_player_Top1.setFont(font);
        Name_player_Top1.setString(highScores[0].playerName);
        Name_player_Top1.setFillColor(sf::Color::Black);
        Name_player_Top1.setCharacterSize(56);
        Name_player_Top1.setPosition(900, 137);

        Score_int_Top1.setFont(font);
        Score_int_Top1.setString(sf::String(std::to_string(highScores[0].score)));
        Score_int_Top1.setFillColor(sf::Color::Black);
        Score_int_Top1.setCharacterSize(56);
        Score_int_Top1.setPosition(1180, 137);

        //profile 
        if (highScores[0].playerProfile == "1")  Pro1_tex.loadFromFile("Profile1.png");
        if (highScores[0].playerProfile == "2")  Pro1_tex.loadFromFile("Profile2.png");
        if (highScores[0].playerProfile == "3")  Pro1_tex.loadFromFile("Profile3.png");
        if (highScores[0].playerProfile == "4")  Pro1_tex.loadFromFile("Profile4.png");
 
        Pro1_sp.setTexture(Pro1_tex);
        Pro1_sp.setScale(0.25, 0.25);
        Pro1_sp.setPosition(776, 128);


    }

    if (how_many_score >= 1) {/////////////////////////////////top2
        Name_player_Top2.setFont(font);
        Name_player_Top2.setString(highScores[1].playerName);
        Name_player_Top2.setFillColor(sf::Color::Black);
        Name_player_Top2.setCharacterSize(48);
        Name_player_Top2.setPosition(900, 250);

        Score_int_Top2.setFont(font);
        Score_int_Top2.setString(sf::String(std::to_string(highScores[1].score)));
        Score_int_Top2.setFillColor(sf::Color::Black);
        Score_int_Top2.setCharacterSize(56);
        Score_int_Top2.setPosition(1180, 250);

        //profile 
        if (highScores[1].playerProfile == "1")  Pro2_tex.loadFromFile("Profile1.png");
        if (highScores[1].playerProfile == "2")  Pro2_tex.loadFromFile("Profile2.png");
        if (highScores[1].playerProfile == "3")  Pro2_tex.loadFromFile("Profile3.png");
        if (highScores[1].playerProfile == "4")  Pro2_tex.loadFromFile("Profile4.png");
        Pro2_sp.setTexture(Pro2_tex);
        Pro2_sp.setScale(0.25, 0.25);
        Pro2_sp.setPosition(776, 240);
    }

    if (how_many_score >= 2) {////////////////////////////////////top3
        Name_player_Top3.setFont(font);
        Name_player_Top3.setString(highScores[2].playerName);
        Name_player_Top3.setFillColor(sf::Color::Black);
        Name_player_Top3.setCharacterSize(48);
        Name_player_Top3.setPosition(900, 363);

        Score_int_Top3.setFont(font);
        Score_int_Top3.setString(sf::String(std::to_string(highScores[2].score)));
        Score_int_Top3.setFillColor(sf::Color::Black);
        Score_int_Top3.setCharacterSize(56);
        Score_int_Top3.setPosition(1180, 363);

        //profile 
        if (highScores[2].playerProfile == "1")  Pro3_tex.loadFromFile("Profile1.png");
        if (highScores[2].playerProfile == "2")  Pro3_tex.loadFromFile("Profile2.png");
        if (highScores[2].playerProfile == "3")  Pro3_tex.loadFromFile("Profile3.png");
        if (highScores[2].playerProfile == "4")  Pro3_tex.loadFromFile("Profile4.png");
        Pro3_sp.setTexture(Pro3_tex);
        Pro3_sp.setScale(0.25, 0.25);
        Pro3_sp.setPosition(776, 352);
    }

    if (how_many_score >= 3) {///////////////////////////top4
        Name_player_Top4.setFont(font);
        Name_player_Top4.setString(highScores[3].playerName);
        Name_player_Top4.setFillColor(sf::Color::Black);
        Name_player_Top4.setCharacterSize(48);
        Name_player_Top4.setPosition(900, 476);

        Score_int_Top4.setFont(font);
        Score_int_Top4.setString(sf::String(std::to_string(highScores[3].score)));
        Score_int_Top4.setFillColor(sf::Color::Black);
        Score_int_Top4.setCharacterSize(56);
        Score_int_Top4.setPosition(1180, 476);

        //profile 
        if (highScores[3].playerProfile == "1")  Pro4_tex.loadFromFile("Profile1.png");
        if (highScores[3].playerProfile == "2")  Pro4_tex.loadFromFile("Profile2.png");
        if (highScores[3].playerProfile == "3")  Pro4_tex.loadFromFile("Profile3.png");
        if (highScores[3].playerProfile == "4")  Pro4_tex.loadFromFile("Profile4.png");
        Pro4_sp.setTexture(Pro4_tex);
        Pro4_sp.setScale(0.25, 0.25);
        Pro4_sp.setPosition(776, 475);
    }

    if (how_many_score >= 4) {//////////////////////////top5
        Name_player_Top5.setFont(font);
        Name_player_Top5.setString(highScores[4].playerName);
        Name_player_Top5.setFillColor(sf::Color::Black);
        Name_player_Top5.setCharacterSize(48);
        Name_player_Top5.setPosition(900, 589);

        Score_int_Top5.setFont(font);
        Score_int_Top5.setString(sf::String(std::to_string(highScores[4].score)));
        Score_int_Top5.setFillColor(sf::Color::Black);
        Score_int_Top5.setCharacterSize(56);
        Score_int_Top5.setPosition(1180, 589);

        //profile 
        if (highScores[4].playerProfile == "1")  Pro5_tex.loadFromFile("Profile1.png");
        if (highScores[4].playerProfile == "2")  Pro5_tex.loadFromFile("Profile2.png");
        if (highScores[4].playerProfile == "3")  Pro5_tex.loadFromFile("Profile3.png");
        if (highScores[4].playerProfile == "4")  Pro5_tex.loadFromFile("Profile4.png");
        Pro5_sp.setTexture(Pro5_tex);
        Pro5_sp.setScale(0.25, 0.25);
        Pro5_sp.setPosition(776, 587);
    }
    
	Loop(window);
}

void Ranking::Update(sf::RenderWindow& window, sf::Event& event)
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

void Ranking::Draw(sf::RenderWindow& window)
{
	window.draw(Bakground_ranking_sp); 
    window.draw(Score_TOP);
    if (how_many_score >= 0) window.draw(Name_player_Top1) , window.draw(Score_int_Top1), window.draw(Pro1_sp) ;
    if (how_many_score >= 1) window.draw(Name_player_Top2), window.draw(Score_int_Top2) , window.draw(Pro2_sp) ;
    if (how_many_score >= 2) window.draw(Name_player_Top3), window.draw(Score_int_Top3) , window.draw(Pro3_sp) ;
    if (how_many_score >= 3) window.draw(Name_player_Top4), window.draw(Score_int_Top4) , window.draw(Pro4_sp) ;
    if (how_many_score >= 4) window.draw(Name_player_Top5), window.draw(Score_int_Top5) , window.draw(Pro5_sp) ;

}

void Ranking::Loop(sf::RenderWindow& window)
{
	while (window.isOpen()) {
		sf::Event event;
		window.clear();
		Update(window, event);
		Draw(window);
		window.display();
	}
}

std::vector<Ranking::HighScoreEntry> Ranking::LoadHighScores(const std::string& filename)
{
    std::vector<Ranking::HighScoreEntry> highScores;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
    }

    std::string line;
    while (std::getline(file, line)) {
        // Split the line  playerProfile, playerName and score
        std::istringstream iss(line);
        std::string playerProfile;
        std::string playerName;
        int score;

        // Read playerProfile
        if (std::getline(iss, playerProfile, ',') && std::getline(iss, playerName, ',') && iss >> score) {
            highScores.push_back({ playerProfile, playerName, score });
        }
    }

    file.close();
    //sort
    std::sort(highScores.begin(), highScores.end());

    std::vector<Ranking::HighScoreEntry> topFive;
    if (highScores.size() >= 5) {
        topFive.assign(highScores.begin(), highScores.begin() + 5);
    }
    else {
        topFive = highScores;
    }

    return topFive;
}


