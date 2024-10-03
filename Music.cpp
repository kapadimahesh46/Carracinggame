#include "Music.h"

bool Music::loadbackgroundmusic(const std::string& filename) {
	if (!backgroundmusic.openFromFile(filename)) {
		return false;
	}
	backgroundmusic.setLoop(true);
	return true;
}



bool Music::loaddrivingmusic(const std::string& filename) {
	if (!drivingmusic.openFromFile(filename)) {
		return false;
	}
	drivingmusic.setLoop(true);
	return true;
}


void Music::playbackgroundmusic() {
	backgroundmusic.play();
}


void Music::playdrivingmusic() {
	if (backgroundmusic.getStatus() == sf::Music::Playing) {
		backgroundmusic.stop();

	}
	drivingmusic.play();
}


void Music::stopdrivingmusic() {
	if (drivingmusic.getStatus() == sf::Music::Playing) {
		drivingmusic.stop();
	}

	if (backgroundmusic.getStatus() != sf::Music::Playing) {
		playbackgroundmusic();
	}

}
