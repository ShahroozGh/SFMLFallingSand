#pragma once
#include <map>

enum Element { AIR, SAND, WATER, STONE, ICE, SPOUT, BORDER };

static std::map<Element, float> DENSITY_MAP = {
	{ AIR, 0.f },
	{ SAND, 0.7f },
	{ WATER, 0.3f },
	{ STONE, 1.0f},
	{ ICE, 1.f },
	{ SPOUT, 1.f },
	{ BORDER, 99.f} };