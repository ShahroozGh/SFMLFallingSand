#include "ParticleBase.h"



ParticleBase::ParticleBase()
{
}

ParticleBase::ParticleBase(Element p_type, int p_x, int p_y)
{
	type = p_type;
	x = p_x;
	y = p_y;
	moved = false;
	life = -1;
	temperature = 0;
	isBurning = false;

	if (p_type == FIRE) {
		life = rand() % 10 + 10;
	}
	else {
		life = -1;
	}

	/*
	if (type == AIR)
		color = sf::Color::Black;
	else if (type == SAND)
		color = sf::Color::Yellow;
	else if (type == WATER)
		color = sf::Color::Blue;
	else if (type == STONE)
		color = sf::Color(211, 211, 211); //Light grey
	else if (type == ICE)
		color = sf::Color(140, 255, 255); //Very close to white
	else if (type == SPOUT)
		color = sf::Color(0, 0, 200); //Bluish
	else if (type == FIRE)
		color = sf::Color::Red;
	else if (type == SMOKE)
		color = sf::Color(100,100,100);
	else if (type == WOOD)
		color = sf::Color(100,45,0);
	else if (type == BORDER)
		color = sf::Color::Magenta;
	else
		color = sf::Color::Red;
		*/

	color = COLOR_MAP[type];
}


ParticleBase::~ParticleBase()
{
}

void ParticleBase::update(std::vector<std::vector<ParticleBase> > &grid)
{
	if (moved) {
		moved = false;
		return;
	}

	if (type == AIR) {
		return;
	}
	else if (type == SAND) {
		y++;
		moved = true;

		grid[x][y + 1].y = y - 1;

		ParticleBase temp = grid[x][y];
		grid[x][y] = grid[x][y + 1];
		grid[x][y + 1] = temp;

		
	}
}
