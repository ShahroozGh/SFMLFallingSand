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
	
	sf::Clock clock;

	//Text
	//Load font
	sf::Font font;
	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		// error...
		return 0;
	}

	//Create text to draw
	sf::Text elapsedTime;
	// set the string to display
	elapsedTime.setString("Time: ");
	// set the character size
	elapsedTime.setCharacterSize(12); // in pixels, not points!
									   // set the color
	elapsedTime.setColor(sf::Color::White);

	elapsedTime.setFont(font);

	sf::Text fpsLabel;
	fpsLabel.setPosition(sf::Vector2f(600, 20));
	// set the string to display
	fpsLabel.setString("FPS: ");
	// set the character size
	fpsLabel.setCharacterSize(12); // in pixels, not points!
									  // set the color
	fpsLabel.setColor(sf::Color::White);

	fpsLabel.setFont(font);

	sf::Text numOfParticlesLabel;
	numOfParticlesLabel.setPosition(sf::Vector2f(600, 40));
	// set the string to display
	numOfParticlesLabel.setString("Particles: ");
	// set the character size
	numOfParticlesLabel.setCharacterSize(12); // in pixels, not points!
								   // set the color
	numOfParticlesLabel.setColor(sf::Color::White);

	numOfParticlesLabel.setFont(font);

	//Game loop
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
					case 5:
						particles.ADD_TYPE = FIRE;
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
				case sf::Keyboard::Num6:
					particles.ADD_TYPE = FIRE;
					break;
				}
			}

		}

		//Or just disable if button pos is in button area
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !buttonHit)
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window); // window is a sf::Window
			// left mouse button is pressed:
			int brushSize = 5;
			particles.addParticles(localPosition.x, localPosition.y, brushSize);
		}

		
		particles.update();

		window.clear();

		
		window.draw(particles);

		//button.draw(window);

		bGroup.draw(window);

		window.draw(elapsedTime);
		window.draw(fpsLabel);
		window.draw(numOfParticlesLabel);

		window.display();

		sf::Time elapsed = clock.restart();
		elapsedTime.setString("Time:" + std::to_string(elapsed.asMilliseconds()));
		fpsLabel.setString("FPS:" + std::to_string(1000.0f / elapsed.asMilliseconds()));
		numOfParticlesLabel.setString("Particles:");



		window.setFramerateLimit(30);
	}

	return 0;
}