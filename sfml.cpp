#include <SFML/Graphics.hpp>
#include "imgui.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "", sf::Style::None);
	sf::Vector2i grabbedOffset;

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	bool grabbedWindow = false;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
					grabbedOffset = window.getPosition() - sf::Mouse::getPosition();
			}
		}

		window.clear(sf::Color::Red);

	

		grabbedWindow = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (grabbedWindow)
			window.setPosition(sf::Mouse::getPosition() + grabbedOffset);

		window.draw(shape);		
		window.display();
	}

	return EXIT_SUCCESS;
}
