#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ParticleSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int windowStyle)
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape rectShape(sf::Vector2f(50, 50));
	rectShape.setFillColor(sf::Color::Red);

	ParticleSystem particles(700,700);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();


			if (event.type == sf::Event::KeyPressed)
			{

				switch (event.key.code) {
				case sf::Keyboard::Num1:
					particles.ADD_TYPE = SAND;
					break;
				case sf::Keyboard::Num2:
					particles.ADD_TYPE = WATER;
					break;
				case sf::Keyboard::Num3:
					particles.ADD_TYPE = STONE;
					break;
				case sf::Keyboard::Num4:
					particles.ADD_TYPE = ICE;
				case sf::Keyboard::Num5:
					particles.ADD_TYPE = SPOUT;
					break;
				}
			}

		}


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
			// left mouse button is pressed:
			particles.addParticle(localPosition.x, localPosition.y);
		}


		particles.update();

		window.clear();

		window.draw(particles);
		window.display();

		window.setFramerateLimit(30);
	}

	return 0;
}