#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonBase.h"
#include <vector>
#include "MapsAndConstants.h"

class ButtonGroup
{
public:
	ButtonGroup();
	~ButtonGroup();

	std::vector<ButtonBase> buttons;
	std::vector<sf::RectangleShape> tempScale;

	void draw(sf::RenderWindow & renderWindow);
	bool onClick(sf::Vector2f mouseCoords);

	sf::Color tempToColor(float temp);
	
	int selectedButton;

private:
	sf::Rect<float> groupHitBox;
	sf::RectangleShape backgroundShape;

	sf::Vector2f position;
	sf::Vector2f size;

	sf::Color bgColor;

	

	
};

