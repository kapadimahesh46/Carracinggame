#ifndef CARWINDOW_H
#define CARWINDOW_H

#include"carwindow.h"

#include"mainmenu.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<stdlib.h>

using namespace std;
using namespace sf;

#include<iostream>

int main() {
	sf::RenderWindow menu(sf::VideoMode(500, 500), "mainmenu", sf::Style::Default);
	mainmenu mainmenu(menu.getSize().x, menu.getSize().y);
	while (menu.isOpen()) {
		sf::Event event;
		while (menu.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				menu.close();
			}
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Up) {
					mainmenu.moveup();
					break;
				}
				if (event.key.code == sf::Keyboard::Down) {
					mainmenu.movedown();
					break;
				}
				if (event.key.code == sf::Keyboard::Return) {




					int x = mainmenu.mainmenupressed();
					if (x == 0) {
						sf::RenderWindow PLAY(sf::VideoMode(500, 500), "play");
						while (PLAY.isOpen()) {
							sf::Event event1;
							while (PLAY.pollEvent(event1)) {
								if (event1.type == sf::Event::Closed) {
									PLAY.close();
								}
								if (event1.type == sf::Event::KeyPressed) {
									if (event1.key.code == sf::Keyboard::Escape) {
										PLAY.close();
									}
								}

							}
							//OPTIONS.close();
							//ABOUT.close();
							PLAY.clear();
							//carwindow car1;
							carwindow game;
							game.run();

							//car1.texture();
							//car1.Windowloop();
							PLAY.display();
						}
					}
					if (x == 1) {
						sf::RenderWindow OPTIONS(sf::VideoMode(500, 500), "Options");
						while (OPTIONS.isOpen()) {
							sf::Event event1;
							while (OPTIONS.pollEvent(event1)) {
								if (event1.type == sf::Event::Closed) {
									OPTIONS.close();
								}
								if (event1.type == sf::Event::KeyPressed) {
									if (event1.key.code == sf::Keyboard::Escape) {
										OPTIONS.close();
									}
								}
							}
							//PLAY.close();
							OPTIONS.clear();
							//ABOUT.close();
							OPTIONS.display();
						}
					}
					if (x == 2) {
						sf::RenderWindow ABOUT(sf::VideoMode(500, 500), "about");
						while (ABOUT.isOpen()) {
							sf::Event event1;
							while (ABOUT.pollEvent(event1)) {
								if (event.type == sf::Event::Closed) {
									ABOUT.close();
								}
								if (event1.type == sf::Event::KeyPressed) {
									if (event.key.code == sf::Keyboard::Escape) {
										ABOUT.close();
									}
								}
							}
							//PLAY.close();
							//OPTIONS.close();
							ABOUT.clear();
							ABOUT.display();
						}
					}
					if (x == 3) {
						sf::RenderWindow Exit(sf::VideoMode(500, 500), "exit");
						while (Exit.isOpen()) {
							sf::Event event1;
							while (Exit.pollEvent(event1)) {
								if (event1.type == sf::Event::Closed) {
									Exit.close();
								}
								if (event1.type == sf::Event::KeyPressed) {
									if (event.key.code == sf::Keyboard::Return) {
										Exit.close();
										menu.close();

										break;

									}

								}
							}
							Exit.clear();
							Exit.display();
							//menu.close();
							//break;
						}
					}
				}
			}
		}
		menu.clear();
		mainmenu.draw(menu);
		menu.display();
	}
	return 0;
}
#endif 