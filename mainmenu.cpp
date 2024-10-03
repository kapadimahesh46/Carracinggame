
#include "mainmenu.h"
mainmenu::mainmenu(float width, float height) {
	if (!font.loadFromFile("fonts/font2.ttf")) {
		cout << "no font is here" << endl;
	}

	//setting up the mainmenu 
	main[0].setFont(font);
	main[0].setFillColor(sf::Color::Green);
	main[0].setString("PLAY");
	main[0].setCharacterSize(90);
	main[0].setPosition(sf::Vector2f(width / 3, height / 6));
	main[0].setScale(0.8f, 0.8f);


	//
	main[1].setFont(font);
	main[1].setFillColor(sf::Color::Blue);
	main[1].setString("OPTIONS");
	main[1].setCharacterSize(90);
	main[1].setPosition(sf::Vector2f(width / 3.35f, height / 2.9f));
	main[1].setScale(sf::Vector2f(0.6f, 0.6f));


	//
	main[2].setFont(font);
	main[2].setFillColor(sf::Color::White);
	main[2].setString("ABOUT");
	main[2].setCharacterSize(90);
	main[2].setPosition(sf::Vector2f(180, height / 2));
	main[2].setScale(sf::Vector2f(0.5f, 0.5f));

	//for exit button
	main[3].setFont(font);
	main[3].setFillColor(sf::Color::White);
	main[3].setString("EXIT");
	main[3].setCharacterSize(90);
	main[3].setPosition(sf::Vector2f(190, height / 1.6f));
	main[3].setScale(sf::Vector2f(0.5f, 0.5f));
	mainmenuselected = -1;

}
mainmenu::~mainmenu() {

}
// drawing mainmenu
void mainmenu::draw(sf::RenderWindow& window) {
	for (int i = 0;i < size;++i) {
		window.draw(main[i]);
	}
}
void mainmenu::moveup() {
	if (mainmenuselected - 1 >= 0) {
		main[mainmenuselected].setFillColor(sf::Color::White);
		mainmenuselected--;

		if (mainmenuselected == -1) {
			mainmenuselected = 2;
		}
		main[mainmenuselected].setFillColor(sf::Color::Blue);
	}
}

void mainmenu::movedown() {
	if (mainmenuselected + 1 <= size) {
		main[mainmenuselected].setFillColor(sf::Color::White);
		mainmenuselected++;
		if (mainmenuselected == 4) {
			mainmenuselected = 0;
		}
		main[mainmenuselected].setFillColor(sf::Color::Blue);


	}
}

