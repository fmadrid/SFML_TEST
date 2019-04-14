#include <SFML/Graphics.hpp>

int main()
{
	// Initializes a new RenderWindow
	const unsigned int WIDTH{ 200 }, HEIGHT{ 200 };
	const std::string TITLE{ "SFML works!" };
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);

	// Initialize a circle
	sf::CircleShape shape(100.f);			// Radius is (float) 100.0
	shape.setFillColor(sf::Color::Green);	// Shape's color is green

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}