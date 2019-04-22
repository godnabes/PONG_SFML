#include <SFML/Graphics.hpp>
int const WINDOW_WIDTH = 1280;
int const WINDOW_HEIGHT = 720;
int keys[999] = {};
int x = 10, y = 10, h = 100, w = 20;

void updateGame();

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	sf::RectangleShape shape(sf::Vector2f(w,h));
	shape.setFillColor(sf::Color::Green);

	window.setVerticalSyncEnabled(false);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) keys[event.key.code] = true;
			if (event.type == sf::Event::KeyReleased) keys[event.key.code] = false;
		}

		updateGame();

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

void updateGame()
{
	if (keys[sf::Keyboard::Up]) y--;
	if (keys[sf::Keyboard::Down]) y++;
}