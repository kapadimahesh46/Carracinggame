#include"Obstacle.h"
Obstacle::Obstacle(float x, float y, float width, float height, float speed) :
	speed(speed) {
	shape.setPosition(x, y);
	shape.setSize(sf::Vector2f(width, height));
	shape.setFillColor(sf::Color::Red);
}

sf::FloatRect Obstacle::getbounds()const {
	return shape.getGlobalBounds();
}
void Obstacle::update(float deltatime) {
	shape.move(0, speed * deltatime);
}

void Obstacle::draw(sf::RenderWindow* window) {
	window->draw(shape);
}