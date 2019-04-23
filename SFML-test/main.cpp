#include <SFML/Graphics.hpp>
int main() {

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

	// run the program as long as the window is open
	while (window.isOpen()) {

		// Check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {

			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);

		// end the current frame
		window.display();
	}

	return EXIT_SUCCESS;
}