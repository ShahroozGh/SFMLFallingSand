#pragma once
#include <vector>
#include "MapsAndConstants.h"

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

	void update(std::vector<std::vector<ParticleBase> > &grid);
	
};

