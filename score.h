#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

class score
{
public:
	score();
	void updatescore(int  scores);
	void increasescore(int  amount);
	void updatetext();
	void draw(sf::RenderWindow*);
	int  getscore();
	void savehighscores();
	void loadhighscores();




private:
	sf::Font font;
	sf::Text scoretext;
	int scores;
	int highscores;

	const std::string filename = "highscore.txt";

};



