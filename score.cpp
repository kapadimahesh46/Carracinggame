#include "score.h"
score::score() :scores(0) {
	if (font.loadFromFile("assets/font4.otf")) {
		std::cout << "error brother" << std::endl;
		std::cout << "error brother" << std::endl;
	}
	scoretext.setFont(font);
	scoretext.setCharacterSize(24);
	scoretext.setFillColor(sf::Color::Green);
	scoretext.setPosition(300, 10);
	scoretext.setScale(1.5f, 1.5f);
	loadhighscores();
	updatetext();


}
void score::increasescore(int  amount) {
	scores += amount;
	updatetext();
	std::cout << "Score:" << scores << std::endl;
}
void score::updatetext() {
	scoretext.setString("Score: " + std::to_string(scores));


}
void score::draw(sf::RenderWindow* window) {
	window->draw(scoretext);
}
int  score::getscore() {
	return scores;
}
void score::savehighscores() {
	if (scores > highscores) {
		highscores = scores;
		std::ofstream outfile(filename);
		if (outfile.is_open()) {
			outfile << highscores;
			outfile.close();
		}
	}
}

void score::loadhighscores() {
	std::ifstream infile(filename);
	if (infile.is_open()) {
		std::string line;
		if (std::getline(infile, line)) {
			std::istringstream(line) >> highscores;
		}
		infile.close();
	}
	else {
		highscores = 0;
	}
}


