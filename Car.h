#pragma once
#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cmath>
#include<vector>
class Car {
private:
	sf::RectangleShape shape;
	sf::Texture texture;

	float speed;
	float accelerations;
	float maxspeed;
	float minspeed;
	float lanewidth;

public:
	Car(const std::string& texturefile, float lanewidth);
	void resetposition();
	sf::FloatRect getbounds()const;
	void draw(sf::RenderWindow* window);
	void acceleration(float deltatime);
	void stopspeed(float);
	void deceleration(float deltatime);
	void moveleft(float deltatime);
	void moveright(float deltatime);
	void update(float deltatime);
	float getspeed()const;

};
/*sf::Texture texture;
sf::Sprite tiresprite;
sf::SoundBuffer enginesoundbuffer;
sf::Sound enginesound;

float speed;
float maxspeed;
float rotationspeed;
float oscillationangle;
bool isoscillating;




public:
	sf::Sprite carsprite;
	Car();
	void setcartexture();
	float getrotationspeed();
	float getspeed();



void setposition();
void move(sf::Time&);
void update(sf::Time&,sf::RenderWindow*);
void rotate(float angle);
void accelerate(float deltatime);
void decelerate(float deltatime);

void startoscillating();
void stoposcillating();
void draw(sf::RenderWindow& window);
void moveup();
void stopenginesound();
void moveright();
void moveleft();



	};
/*
class Car {
private:
	float speed=250;
	float direction;//angle in degrees
	int gear;
	float acceleration;
	float maxspeed;
	float friction;


public:
	sf::Texture cartexture;
	sf::Sprite carsprite;
	Car();
	void accelerate();
	void brake();
	void steerleft();
	void steerright();
	void shiftup();
	void shiftdown();
	void applyfriction();
	void update();
	void eventanalysis();

};
class Car
{
private:


public:
	sf::Sprite carsprite;
	sf::Texture cartexture;
	int carmovespeed = 250;


	Car();
	~Car();
	void resetcarposition();
	void setshouldmove(bool);
	void movecar(sf::Time&);




*/





