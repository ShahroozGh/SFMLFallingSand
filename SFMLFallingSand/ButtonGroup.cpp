#include "ButtonGroup.h"



ButtonGroup::ButtonGroup()
{
	selectedButton = -1;

	position = sf::Vector2f(0, 0);
	size = sf::Vector2f(700, 100);
	bgColor = sf::Color(111,111,111);
	
	groupHitBox = sf::Rect<float>(position, size);
	backgroundShape = sf::RectangleShape(size);
	backgroundShape.setPosition(position);
	backgroundShape.setFillColor(bgColor);

	
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());

	buttons[0].setPosition(sf::Vector2f(10,20));
	buttons[0].setColor(sf::Color::Yellow);
	buttons[0].setSelectedColor(sf::Color::White);

	buttons[1].setPosition(sf::Vector2f(70, 20));
	buttons[1].setColor(sf::Color::Blue);
	buttons[1].setSelectedColor(sf::Color::White);

	buttons[2].setPosition(sf::Vector2f(130, 20));
	buttons[2].setColor(sf::Color(211, 211, 211));
	buttons[2].setSelectedColor(sf::Color::White);

	buttons[3].setPosition(sf::Vector2f(190, 20));
	buttons[3].setColor(sf::Color(140, 255, 255));
	buttons[3].setSelectedColor(sf::Color::White);

	buttons[4].setPosition(sf::Vector2f(250, 20));
	buttons[4].setColor(sf::Color(0, 0, 200));
	buttons[4].setSelectedColor(sf::Color::White);

	buttons[5].setPosition(sf::Vector2f(310, 20));
	buttons[5].setColor(sf::Color::Red);
	buttons[5].setSelectedColor(sf::Color::White);

	buttons[6].setPosition(sf::Vector2f(370, 20));
	buttons[6].setColor(sf::Color(100,45,0));
	buttons[6].setSelectedColor(sf::Color::White);

	buttons[7].setPosition(sf::Vector2f(430, 20));
	buttons[7].setColor(sf::Color::Magenta);
	buttons[7].setSelectedColor(sf::Color::White);


	
	
}


ButtonGroup::~ButtonGroup()
{
}

void ButtonGroup::draw(sf::RenderWindow & renderWindow)
{

	renderWindow.draw(backgroundShape);

	for (int i = 0; i < buttons.size(); i++)
		buttons[i].draw(renderWindow);
}

bool ButtonGroup::onClick(sf::Vector2f mouseCoords)
{
	if (groupHitBox.contains(mouseCoords)) {
		//Clicked inside box
		//Check if buttons are hit
		for (int i = 0; i < buttons.size(); i++) {

			if (buttons[i].checkIfClicked(mouseCoords)) {
				if (selectedButton != -1)
					buttons[selectedButton].setSelected(false);
				selectedButton = i;
				buttons[i].setSelected(true);
			}
		}
		return true;
	}
	else {
		return false;
	}
	
}
