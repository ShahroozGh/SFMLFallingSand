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
	buttons.push_back(ButtonBase());
	buttons.push_back(ButtonBase());

	buttons[0].setColor(sf::Color::Yellow);
	buttons[1].setColor(sf::Color::Blue);
	buttons[2].setColor(sf::Color(211, 211, 211));
	buttons[3].setColor(sf::Color(140, 255, 255));
	buttons[4].setColor(sf::Color(0, 0, 200));
	buttons[5].setColor(sf::Color::Red);
	buttons[6].setColor(sf::Color(100,45,0));
	buttons[7].setColor(COLOR_MAP[WATER_VAPOR]);
	buttons[8].setColor(sf::Color::Magenta);

	int y = 20;
	for (int i = 0; i < buttons.size(); i++) {
		
		if (10 + i*buttons[i].getSize().x > 650)
			y += buttons[i].getSize().y + 2;
		buttons[i].setPosition(sf::Vector2f(10 + i*(buttons[i].getSize().x + 2), 20));
		buttons[i].setSelectedColor(sf::Color::White);
	}


	
	
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
