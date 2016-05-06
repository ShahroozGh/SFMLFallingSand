#pragma once
#include <SFML\Graphics.hpp>

class ButtonBase
{
public:
	ButtonBase();
	~ButtonBase();

	void draw(sf::RenderWindow &targetWindow);
	bool checkIfClicked(sf::Vector2f mouseCoords);

	void setPosition(sf::Vector2f pos);
	void setSize(sf::Vector2f newSize);
	void setColor(sf::Color color);
	void setSelectedColor(sf::Color color);
	void setSelected(bool select);

	sf::Vector2f getSize();

private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::RectangleShape buttonRect;
	sf::RectangleShape buttonBorder;
	sf::Color buttonColor, selectedColor;
	sf::Rect<float> hitBox;
	bool selected;
};

