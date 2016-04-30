#pragma once
#include <SFML\Graphics.hpp>
#include "ButtonBase.h"
#include <vector>

class ButtonGroup
{
public:
	ButtonGroup();
	~ButtonGroup();

	std::vector<ButtonBase> buttons;
	void draw(sf::RenderWindow & renderWindow);
	bool onClick(sf::Vector2f mouseCoords);
	
	int selectedButton;

private:
	sf::Rect<float> groupHitBox;
	sf::RectangleShape backgroundShape;

	sf::Vector2f position;
	sf::Vector2f size;

	sf::Color bgColor;

	

	
};

