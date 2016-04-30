#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "ParticleSystem.h"
#include "ButtonBase.h"
#include "ButtonGroup.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int windowStyle)
{
	sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::RectangleShape rectShape(sf::Vector2f(50, 50));
	rectShape.setFillColor(sf::Color::Red);

	ParticleSystem particles(700,700);

	ButtonBase button;
	button.setPosition(sf::Vector2f(50,70));
	button.setSelected(true);

	ButtonGroup bGroup;

	bool buttonHit = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					//button.checkIfClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.x));
					//buttonHit = button.checkIfClicked(sf::Vector2f(localPosition.x, localPosition.y));
					buttonHit = bGroup.onClick(sf::Vector2f(localPosition.x, localPosition.y));

					//Update selected Element
					switch (bGroup.selectedButton) {
					case 0:
						particles.ADD_TYPE = SAND;
						break;
					case 1:
						particles.ADD_TYPE = WATER;
						break;
					case 2:
						particles.ADD_TYPE = STONE;
						break;
					case 3:
						particles.ADD_TYPE = ICE;
						break;
					case 4:
						particles.ADD_TYPE = SPOUT;
						break;
					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					//sf::Vector2i localPosition = sf::Mouse::getPosition(window);
					//button.checkIfClicked(sf::Vector2f(event.mouseButton.x, event.mouseButton.x));
					buttonHit = false;
				}
			}


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
					break;
				case sf::Keyboard::Num5:
					particles.ADD_TYPE = SPOUT;
					break;
				}
			}

		}

		//Or just disable if button pos is in button area
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !buttonHit)
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
			// left mouse button is pressed:
			particles.addParticle(localPosition.x, localPosition.y);
		}

		
		particles.update();

		window.clear();

		
		window.draw(particles);

		//button.draw(window);

		bGroup.draw(window);

		window.display();

		window.setFramerateLimit(30);
	}

	return 0;
}