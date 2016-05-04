#pragma once
#include <map>

enum Element { AIR, SAND, WATER, STONE, ICE, SPOUT, FIRE, EMBER, SMOKE, WOOD, BORDER };

static std::map<Element, float> DENSITY_MAP = {
	{ AIR, 0.f },
	{ SAND, 0.7f },
	{ WATER, 0.3f },
	{ STONE, 1.0f},
	{ ICE, 1.f },
	{ SPOUT, 1.f },
	{ FIRE, -0.1f },
	{ EMBER, 0.5f },
	{ SMOKE, -0.1f },
	{ WOOD, 1.0f },
	{ BORDER, 99.f} };

static std::map<Element, bool> FLAMMABLE_MAP = {
	{ AIR, false },
	{ SAND, false },
	{ WATER, false },
	{ STONE, false },
	{ ICE, false },
	{ SPOUT, false },
	{ FIRE, false },
	{ EMBER, false },
	{ SMOKE, false },
	{ WOOD, true },
	{ BORDER, false } };