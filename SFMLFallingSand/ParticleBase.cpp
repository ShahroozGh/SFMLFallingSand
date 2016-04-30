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
