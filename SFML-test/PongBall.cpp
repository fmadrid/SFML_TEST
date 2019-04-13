#include "PongBall.h"

PongBall::PongBall() {
	// Load the sound used in the game
	if (!ballSoundBuffer.loadFromFile("ball.wav")) {
		std::cout << "cannot open audio";
	}
	else
		ballSound.setBuffer(ballSoundBuffer);

	radius = 10;
	ballSpeed = 400.f;
	ballAngle = 50.f;

	ballShape.setRadius(radius - 3);
	ballShape.setOutlineThickness(3);
	ballShape.setOutlineColor(sf::Color::Black);
	ballShape.setFillColor(sf::Color::White);
	ballShape.setOrigin(radius / 2, radius / 2);
	ballShape.setPosition(gameWidth / 2, gameHeight / 2);
}

void PongBall::move(float deltaTime) {
	float factor = ballSpeed * deltaTime;
	ballShape.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);
}

void PongBall::checkCollision() {
	// Check collisions between the ball and the screen
	if (ballShape.getPosition().x - radius < 0.f)
	{
		ballSound.play();
		ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
		ballShape.setPosition(radius + 0.1f, ballShape.getPosition().y);
	}
	if (ballShape.getPosition().x + radius > gameWidth)
	{
		ballSound.play();
		ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
		ballShape.setPosition(gameWidth - radius - 0.1f, ballShape.getPosition().y);
	}
	if (ballShape.getPosition().y - radius < 0.f)
	{
		ballSound.play();
		ballAngle = -ballAngle;
		ballShape.setPosition(ballShape.getPosition().x, radius + 0.1f);
	}
	if (ballShape.getPosition().y + radius > gameHeight)
	{
		ballSound.play();
		ballAngle = -ballAngle;
		ballShape.setPosition(ballShape.getPosition().x, gameHeight - radius - 0.1f);
	}
}
sf::CircleShape PongBall::getBallShape() {
	return ballShape;
}

void PongBall::setGameDimension(int width, int height) {
	gameWidth = width;
	gameHeight = height;
}