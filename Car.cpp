
#include "Car.h"
Car::Car(const std::string& texturefile, float lanewidth) :speed(0.0f), accelerations(5.0f),
maxspeed(5.0f), minspeed(-50.0f), lanewidth(lanewidth) {
	if (!texture.loadFromFile(texturefile)) {
		shape.setFillColor(sf::Color::Blue);

	}
	else {
		shape.setTexture(&texture);

	}
	shape.setSize(sf::Vector2f(100.0f, 100.0f));

	resetposition();

}

void Car::resetposition() {
	shape.setPosition(375.0f, 400.0f);
	speed = 0.0f;

}

sf::FloatRect Car::getbounds()const {
	return shape.getGlobalBounds();

}
void Car::draw(sf::RenderWindow* window) {
	window->draw(shape);


}

void Car::acceleration(float deltatime) {
	speed += accelerations * deltatime;
	if (speed >= maxspeed) {
		speed-=accelerations*deltatime;
		

	}

}
void Car::deceleration(float deltatime) {
	speed -= accelerations * deltatime;
	if (speed < minspeed) {
		speed = minspeed;
	}
}

void Car::moveleft(float deltatime) {
	shape.move(-lanewidth * deltatime, 0);


}
void Car::moveright(float deltatime) {
	shape.move(lanewidth * deltatime, 0);
}
void Car::update(float deltatime) {
	shape.move(0, -speed * deltatime);

}
float Car::getspeed()const {
	return speed;
}
void Car::stopspeed(float deltatime) {
	maxspeed = 0.02f*deltatime;
	
}






/*Car::Car() {
	speed = 0.0f;
	maxspeed = 100.0f;
	rotationspeed = 10.0f;
	oscillationangle = 0.f;
	isoscillating = false;
	if (!enginesoundbuffer.loadFromFile("music/accelerate.wav")) {
		std::cout << "Failed to load music from directory" << std::endl;
	}
	enginesound.setBuffer(enginesoundbuffer);
	enginesound.setLoop(true);
	setcartexture();
	setposition();



}
float Car::getrotationspeed() {
	return rotationspeed;
}
float Car::getspeed() {
	return speed;
}
void Car:: setcartexture() {
	texture.loadFromFile("assets/car5.png");
	carsprite.setTexture(texture);

	carsprite.setScale(0.2f, 0.2f);

}
void Car:: setposition() {
	carsprite.setOrigin(20, 100);
	carsprite.setPosition(0,300);




}
void Car::move(sf::Time& deltatime) {
	//carsprite.move( -speed * deltatime,0.f);
	carsprite.move(0.f, speed * deltatime.asSeconds());


	if (isoscillating) {
		oscillationangle += deltatime.asSeconds() * 50.0f;
		float offset = std::sin(oscillationangle) * 50.f;
		//carsprite.move(offset * deltatime, 0);
		carsprite.move(0.f, offset * deltatime.asSeconds());
	}
}

void Car:: rotate(float angle) {
	carsprite.rotate(angle);

}
void Car:: accelerate(float deltatime) {
	if (speed < maxspeed) {
		speed += 50.f * deltatime;
	}


}

void Car:: decelerate(float deltatime) {
	if (speed > -maxspeed) {
		speed -= 100.f * deltatime;
	}
}
void Car:: startoscillating() {
	isoscillating = true;

}
void Car::stoposcillating() {
	isoscillating = false;
	oscillationangle = 0.f;
}

void Car::update(sf::Time& dt, sf::RenderWindow* window) {
	sf::Vector2f position = carsprite.getPosition();
	position.y -= speed * dt.asSeconds();
	if (position.y < 0) {
		position.y = 0;
	}
	else if (position.y + carsprite.getGlobalBounds().height > window->getSize().y) {
		position.y = window->getSize().y - carsprite.getGlobalBounds().height;

	carsprite.setPosition(position);
	}

	// boundry detection
}

void Car::moveup(){
	if (enginesound.getStatus() != sf::Sound::Playing) {
		enginesound.play();


	}
}

void Car::stopenginesound() {
	enginesound.stop();
}
void Car::moveright() {
	carsprite.move(sf::Vector2f(2.5f, 0.f));
}
void Car::moveleft() {
	carsprite.move(sf::Vector2f(-2.5f, 0.f));


}
*/














