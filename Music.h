#pragma once
#include<SFML/Audio.hpp>
class Music
{
private:
	sf::Music backgroundmusic;
	sf::Music drivingmusic;


public:
	bool loadbackgroundmusic(const std::string& filename);
	bool loaddrivingmusic(const std::string& filename);
	void playbackgroundmusic();
	void playdrivingmusic();
	void stopdrivingmusic();
	
};

