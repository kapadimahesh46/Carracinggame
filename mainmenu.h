#pragma once
#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
#define size 4

class mainmenu
{
public:
	mainmenu(float width, float height);
	void draw(sf::RenderWindow& window);
	void moveup();
	void movedown();
	int mainmenupressed() {
		return mainmenuselected;

	}
	~mainmenu();
private:
	int mainmenuselected;
	sf::Font font;
	sf::Text main[size];
};



