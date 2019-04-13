#ifndef PONGBALL_H
#define PONGBALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class PongBall {
public:
	PongBall();
	void move(float deltaTime);
	void checkCollision();
	sf::CircleShape getBallShape();
	void setGameDimension(int width, int height);
private:
	float radius;
	sf::CircleShape ballShape;
	sf::Sound ballSound;
	sf::SoundBuffer ballSoundBuffer;
	float ballSpeed;
	float ballAngle;
	int gameWidth, gameHeight;
	const float pi = 3.14159f;
};

#endif