#include "carwindow.h"
#include<algorithm>

carwindow::carwindow() : window(sf::VideoMode(500, 500), "carracing game"), car1("assets/car5.png", 200.0f) {

	loadingtextures();

}
void carwindow::loadingtextures() {


	if (gamemusic.loadbackgroundmusic("music/accelerate.wav")) {
		gamemusic.playbackgroundmusic();
	}

	if (!gamemusic.loaddrivingmusic("music/accelerate.wav")) {
		std::cout << "error playing music" << std::endl;
	}





	texture1.loadFromFile("assets/bg.png");
	texture2.loadFromFile("assets/road7.jpg");
	window.setFramerateLimit(60);

	sprite[0].setTexture(texture1);
	//sprite[0].setScale(0.15f, 0.15f);
	sprite[0].setScale(1.3f, 1.0f);
	sprite[0].setPosition(0, -250);



	sprite[1].setTexture(texture2);
	sprite[1].setScale(0.32f, 0.32f);
	sprite[1].setPosition(6.5f, 0.0f);
	//sprite[1].setPosition(10, 0.0f);

	sprite[2].setTexture(texture2);
	sprite[2].setScale(0.32f, 0.32f);
	//sprite[2].setPosition(sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width, 72.0f);
	sprite[2].setPosition(6.5f, sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height);








}








void carwindow::restartgame() {
	gameover = false;
	car1.resetposition();
	obstacles.clear();
	obstacleclock.restart();

}
void carwindow::checkcollisions() {
	sf::FloatRect carbounds = car1.getbounds();
	for (const auto& Obstacle : obstacles) {
		if (carbounds.intersects(Obstacle.getbounds())) {
			gameover = true;
		}
	}
	if (carbounds.left<roadleftboundry - 76 || carbounds.left + carbounds.width + 200>roadrightboundry) {
		gameover = true;
	}
	if (gameover) {
		std::cout << "you lose!" << std::endl;
		displaygameoverscreen();
	}
}


void carwindow::generateobstacles() {
	float x = static_cast<float>(rand() % static_cast<int>(roadrightboundry - roadleftboundry) + roadleftboundry);
	float y = -100.0f;
	float width = 50.0f;
	float height = 50.0f;
	float speed = car1.getspeed() * speedincreasefactor;
	obstacles.emplace_back(x, y, width, height, speed);
}


void carwindow::updateobstacles(float deltatime) {
	for (auto& Obstacle : obstacles) {
		Obstacle.update(deltatime);

	}
	obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [](const Obstacle& obs) {
		return obs.getbounds().top > 600;
		}), obstacles.end());

}

void carwindow::handleinput(float deltatime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && carmoving) {
		car1.moveleft(deltatime);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && carmoving) {
		car1.moveright(deltatime);
	}



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && carmoving) {
		car1.acceleration(deltatime);
		scors.increasescore(1);
		if (!isdriving) {
			gamemusic.playdrivingmusic();
			isdriving = true;
		}
	
	}
	
	else {
		if (isdriving) {
			gamemusic.stopdrivingmusic();
			car1.stopspeed(deltatime);
			isdriving = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && carmoving) {
		car1.deceleration(deltatime);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		carmoving = !carmoving;
	}
	if (carmoving) {
		car1.update(deltatime);
	}
}


void carwindow::displaygameoverscreen() {
	sf::Font font;
	if (!font.loadFromFile("assets/font4.otf")) {
		std::cout << "error loading text thank you" << std::endl;

	}

	//sf::Text gameovertext;
	gam.setFont(font);
	gam.setString("you lose!press enter to restart");
	gam.setCharacterSize(80);
	gam.setFillColor(sf::Color::Red);
	gam.setPosition(sf::Vector2f(100, 200));
	gam.setScale(0.5f, 0.5f);
	window.clear();
	window.draw(gam);
	window.display();

	while (!true) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();

			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
				restartgame();
			}
			return;

		}
	}
}

void carwindow::draw() {
	window.clear();
	window.draw(sprite[0]);
	window.draw(sprite[1]);
	window.draw(sprite[2]);
	//window.draw(*gam);
	car1.draw(&window);
	scors.draw(&window);

	for (auto& Obstacle : obstacles) {
		Obstacle.draw(&window);
	}
	window.display();
}


void carwindow::moveground(float deltatime) {
	//if (ev.type == sf::Event::KeyReleased) {
		//if (ev.key.code == sf::Keyboard::Return) {

	sprite[1].move(0.f, movespeed*deltatime);
	sprite[2].move(0.f, movespeed * deltatime);


	//}
//}


/* if (sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width < 0) {
	sprite[1].setPosition(sprite[2].getGlobalBounds().left + sprite[2].getGlobalBounds().width, 72.0f);
}

if (sprite[2].getGlobalBounds().left + sprite[2].getGlobalBounds().width < 0) {
	sprite[2].setPosition(sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width, 72.0f);
}

*/


	if (sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height > 0) {
		sprite[1].setPosition(6.5f, sprite[2].getGlobalBounds().top - sprite[2].getGlobalBounds().height);
	}

	if (sprite[2].getGlobalBounds().top - sprite[2].getGlobalBounds().height > 0) {
		sprite[2].setPosition(6.5f, sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height);
	}

}

void carwindow::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();

			}
		}

		if (!gameover) {
			float deltatime = clock.restart().asSeconds();
			handleinput(deltatime);
			moveground(deltatime);
			if (obstacleclock.getElapsedTime().asSeconds() > obstaclespawintime) {
				generateobstacles();
				obstacleclock.restart();
			}
			updateobstacles(deltatime);
			checkcollisions();
			draw();
		}
	}
	scors.savehighscores();
}



























/* carwindow::carwindow() {
	initwindow();


}
carwindow::~carwindow() {

}
void carwindow::initwindow() {
	this->window = new sf::RenderWindow(sf::VideoMode(500, 500), "starting game");
	texture();



}
void carwindow::renderwindow() {
	this->window->clear();


	window->draw(sprite[0]);
	window->draw(sprite[1]);
	window->draw(sprite[2]);
	window->draw(car.carsprite);
	obs.draw(window);

	scors.draw(window);




	//window->draw(car.carsprite);

	//window->draw(sprite[2]);



	//window->draw(sprite3);
	//sprite2.move(-0.1, 0);



	this->window->display();
}
void carwindow::Windowloop() {
	while (this->window->isOpen()) {
		sf::Time dt = clock.restart();

		car.move(dt);
		processevents(dt.asSeconds());

		car.update(dt,window);
		moveground(dt);


		renderwindow();







	}
	scors.savehighscores();
}


void carwindow::processevents(float dt) {
	sf::Event ev;
	while (this->window->pollEvent(ev)) {
		if (ev.type == sf::Event::Closed) {
			this->window->close();
		}

	}
	// hangle car movement


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {


			car.accelerate(dt);
			car.moveup();
			car.startoscillating();
			scors.increasescore(1);

	}


 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		car.decelerate(dt);
		car.startoscillating();

	}
	else {
		car.stoposcillating();
		car.stopenginesound();
	}
	float rotationspeed = car.getrotationspeed();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		car.rotate(-rotationspeed * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		car.rotate(rotationspeed * dt);
		car.accelerate(dt);
		car.startoscillating();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		car.moveright();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		car.moveleft();
	}


	   }

void carwindow::texture() {
	texture1.loadFromFile("assets/bg.png");
	texture2.loadFromFile("assets/road7.jpg");
	window->setFramerateLimit(60);

	sprite[0].setTexture(texture1);
	//sprite[0].setScale(0.15f, 0.15f);
	sprite[0].setScale(1.3f, 1.0f);
	sprite[0].setPosition(0, -250);



	sprite[1].setTexture(texture2);
	sprite[1].setScale(0.32f, 0.32f);
	sprite[1].setPosition(6.5f, 0.0f);
	//sprite[1].setPosition(10, 0.0f);

	sprite[2].setTexture(texture2);
	sprite[2].setScale(0.32f, 0.32f);
	//sprite[2].setPosition(sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width, 72.0f);
	sprite[2].setPosition(6.5f, sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height);








}

void carwindow::moveground(sf::Time &dt) {
	//if (ev.type == sf::Event::KeyReleased) {
		//if (ev.key.code == sf::Keyboard::Return) {

	sprite[1].move(0.f,move_speed * dt.asSeconds());
	sprite[2].move(0.f,move_speed * dt.asSeconds());


		//}
	//}


	/* if (sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width < 0) {
		sprite[1].setPosition(sprite[2].getGlobalBounds().left + sprite[2].getGlobalBounds().width, 72.0f);
	}

	if (sprite[2].getGlobalBounds().left + sprite[2].getGlobalBounds().width < 0) {
		sprite[2].setPosition(sprite[1].getGlobalBounds().left + sprite[1].getGlobalBounds().width, 72.0f);
	}


	if (sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height > 0) {
		sprite[1].setPosition(6.5f,sprite[2].getGlobalBounds().top - sprite[2].getGlobalBounds().height);
	}

	if (sprite[2].getGlobalBounds().top - sprite[2].getGlobalBounds().height > 0) {
		sprite[2].setPosition(6.5f, sprite[1].getGlobalBounds().top - sprite[1].getGlobalBounds().height);
	}

}

*/











