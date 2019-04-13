////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "PongBall.h"

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// Define constants
	const int gameWidth = 800;
	const int gameHeight = 600;
	
	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight, 32), "Ball Animation", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	// Create the ball
	PongBall ball;
	ball.setGameDimension(gameWidth, gameHeight);

	sf::Clock clock;

	while (window.isOpen()) // MAIN GAME LOOP -- should be more concise and readable after modification
	{
		// Handle events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Window closed or escape key pressed: exit
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}
		}

		float deltaTime = clock.restart().asSeconds();

		// Move the ball
		ball.move(deltaTime);

		// Check collisions between the ball and the screen
		ball.checkCollision();

		// Clear the window
		window.clear(sf::Color(50, 200, 50));

		window.draw(ball.getBallShape());

		// Display things on screen
		window.display();
	}

	return EXIT_SUCCESS;
}