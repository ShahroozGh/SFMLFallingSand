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
	temperature = AMBIENT_TEMP_MAP[type];
	isBurning = false;

	if (p_type == FIRE || p_type == HOT_FIRE) {
		life = rand() % 10 + 10;
	}
	else {
		life = -1;
	}

	

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
