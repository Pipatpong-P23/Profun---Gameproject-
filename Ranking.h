#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ranking
{
public:
	struct HighScoreEntry {
		std::string playerProfile;
		std::string playerName;
		int score;

		// Define a comparison operator for sorting
		bool operator<(const HighScoreEntry& other) const {
			return score > other.score; // Sort in descending order
		}
	};
	std::vector<HighScoreEntry> highScores;

	Ranking(sf::RenderWindow &window);
	void Update(sf::RenderWindow &window, sf::Event &event);
	void Draw(sf::RenderWindow &window);
	void Loop(sf::RenderWindow &window);

	std::vector<HighScoreEntry> LoadHighScores(const std::string& filename);
	

	sf::Texture Background_ranking_tex;
	sf::Sprite Bakground_ranking_sp;

	int how_many_score;

	sf::Font font;

	sf::Text Score_TOP;

	sf::Text Name_player_Top1;
	sf::Text Name_player_Top2;
	sf::Text Name_player_Top3;
	sf::Text Name_player_Top4;
	sf::Text Name_player_Top5;

	sf::Text Score_int_Top1;
	sf::Text Score_int_Top2;
	sf::Text Score_int_Top3;
	sf::Text Score_int_Top4;
	sf::Text Score_int_Top5;

	sf::Sprite Pro1_sp; 
	sf::Texture Pro1_tex;

	sf::Sprite Pro2_sp;
	sf::Texture Pro2_tex;

	sf::Sprite Pro3_sp;
	sf::Texture Pro3_tex;

	sf::Sprite Pro4_sp;
	sf::Texture Pro4_tex;

	sf::Sprite Pro5_sp;
	sf::Texture Pro5_tex;


};

