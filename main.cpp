#include <SFML/Graphics.hpp>
int const WINDOW_WIDTH = 1280;
int const WINDOW_HEIGHT = 720;
int keys[999] = {};
int player1X = 0, player1Y = 10, h = 100, w = 20;
int player2X = 1260, player2Y = 10;

sf::RectangleShape player1(sf::Vector2f(w, h));
sf::RectangleShape player2(sf::Vector2f(w, h));

void updateGame();

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");
	
	player1.setFillColor(sf::Color::Green);
	player2.setFillColor(sf::Color::Blue);

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
		window.draw(player1);
		window.draw(player2);
		window.display();
	}

	return 0;
}

void updateGame()
{
	if(player1Y > 0)
		if (keys[sf::Keyboard::W]) player1Y--;
	if(player1Y < WINDOW_HEIGHT - h)
		if (keys[sf::Keyboard::S]) player1Y++;

	if(player2Y > 0)
		if (keys[sf::Keyboard::Up]) player2Y--;
	if(player2Y < WINDOW_HEIGHT - h)
		if (keys[sf::Keyboard::Down]) player2Y++;

	player1.setPosition(player1X, player1Y);
	player2.setPosition(player2X, player2Y);
}