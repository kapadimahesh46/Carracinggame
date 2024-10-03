#pragma once
#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<vector>
#include"Car.h"
#include"Obstacle.h"
#include"score.h"
#include"Music.h"


#include<vector>


using namespace std;




class carwindow {

private:
	sf::RenderWindow window;
	sf::Texture texture1, texture2;
	Car car1;
	sf::Sprite sprite[3];
	std::vector<Obstacle>obstacles;
	sf::Clock obstacleclock;
	float obstaclespawintime = 2.0f;
	float speedincreasefactor = 1.1f;
	float roadleftboundry = 100.0f;
	float roadrightboundry = 700.0f;
	bool gameover = false;
	bool carmoving = true;
	int movespeed = 500;
	bool isdriving = false;


public:
	carwindow();
	void restartgame();
	void checkcollisions();
	void generateobstacles();
	void updateobstacles(float deltatime);
	sf::Text gam;
	
	Music gamemusic;
	void handleinput(float delatime);
	void displaygameoverscreen();
	void draw();
	void run();
	score scors;
	void loadingtextures();
	void moveground(float deltatime);

};
/*private:
	sf::RenderWindow* window;
	//sf::Event ev;
	sf::Texture texture1,texture2;
	sf::Font font;
	sf::Sprite sprite[3];


	const int move_speed = 800;
	sf::Clock clock;
	sf::Time dt;






	void initwindow();
public:
	carwindow();
	~carwindow();
	void Windowloop();
	void renderwindow();

	void processevents(float);
	void moveground(sf::Time&);


	Car car;

	Obstacle obs;




	void texture();
	float scalling();
	*/






