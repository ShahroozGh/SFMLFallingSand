#pragma once
#include <vector>
#include "MapsAndConstants.h"
#include <SFML\Graphics.hpp>

class ParticleBase
{
public:
	ParticleBase();
	ParticleBase(Element p_type, int p_x, int p_y);
	~ParticleBase();
	
	//int type;
	Element type;

	int x, y;
	bool moved;

	//State properties
	bool isBurning;
	float temperature;
	int life;

	sf::Color color;

	void update(std::vector<std::vector<ParticleBase> > &grid);
	
};

