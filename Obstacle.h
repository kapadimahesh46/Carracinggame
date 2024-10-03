#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class Obstacle {
private:
	sf::RectangleShape shape;
	float speed;
public:
	Obstacle(float x, float y, float width, float height, float speed);
	sf::FloatRect getbounds()const;
	void update(float deltatime);
	void draw(sf::RenderWindow* window);



};

