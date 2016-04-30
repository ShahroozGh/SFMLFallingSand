#pragma once
#include <SFML\Graphics.hpp>

class ButtonBase
{
public:
	ButtonBase();
	~ButtonBase();

	void draw(sf::RenderWindow &targetWindow);
	void setPosition(sf::Vector2f pos);
	void setColor(sf::Color color);
	void setSelectedColor(sf::Color color);
	void setSelected(bool select);
	bool checkIfClicked(sf::Vector2f mouseCoords);

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape buttonRect;
	sf::RectangleShape buttonBorder;
	sf::Color buttonColor, selectedColor;
	sf::Rect<float> hitBox;
	bool selected;
};

