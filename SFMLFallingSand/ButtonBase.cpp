#include "ButtonBase.h"



ButtonBase::ButtonBase()
{
	position = sf::Vector2f(0, 0);
	size = sf::Vector2f(40, 40);
	buttonColor = sf::Color::Red;
	selectedColor = sf::Color::White;
	selected = false;


	hitBox = sf::Rect<float>(position, size);
	buttonRect = sf::RectangleShape(size);
	buttonRect.setPosition(position);
	buttonRect.setFillColor(buttonColor);

	buttonBorder = sf::RectangleShape(size + sf::Vector2f(4, 4));
	buttonBorder.setPosition(position - sf::Vector2f(2,2));
	buttonBorder.setFillColor(selectedColor);


}


ButtonBase::~ButtonBase()
{
}

void ButtonBase::draw(sf::RenderWindow & targetWindow)
{
	if (selected)
		targetWindow.draw(buttonBorder);
	targetWindow.draw(buttonRect);
}

void ButtonBase::setPosition(sf::Vector2f pos)
{
	position = pos;
	buttonRect.setPosition(pos);
	buttonBorder.setPosition(pos - sf::Vector2f(2, 2));

	hitBox = sf::Rect<float>(pos, size);
}

void ButtonBase::setColor(sf::Color color)
{
	buttonColor = color;
	buttonRect.setFillColor(color);
}

void ButtonBase::setSelectedColor(sf::Color color)
{
	selectedColor = color;
	buttonBorder.setFillColor(color);
}

void ButtonBase::setSelected(bool select)
{
	selected = select;
}

bool ButtonBase::checkIfClicked(sf::Vector2f mouseCoords)
{
	if (hitBox.contains(mouseCoords))
	{
		selected = !selected;
		return true;
	}
	return false;
}
