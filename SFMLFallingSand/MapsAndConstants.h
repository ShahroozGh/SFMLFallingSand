#pragma once
#include <map>
#include <SFML\Graphics.hpp>

enum Element { AIR, SAND, WATER, WATER_VAPOR, STONE, ICE, SPOUT, FIRE, EMBER, SMOKE, ASH, WOOD, BORDER };

//Contains default colors of all the elements
static std::map<Element, sf::Color> COLOR_MAP = {
	{ AIR, sf::Color::Black },
	{ SAND, sf::Color::Yellow },
	{ WATER, sf::Color::Blue },
	{ WATER_VAPOR, sf::Color(215, 240, 255) },
	{ STONE, sf::Color(211, 211, 211) },
	{ ICE, sf::Color(140, 255, 255) },
	{ SPOUT, sf::Color(0, 0, 200) },
	{ FIRE, sf::Color::Red },
	{ EMBER, sf::Color(200,70,0) },
	{ SMOKE, sf::Color(100, 100, 100) },
	{ ASH, sf::Color(50, 50, 50) },
	{ WOOD, sf::Color(100, 45, 0) },
	{ BORDER, sf::Color::Magenta } };


static std::map<Element, float> DENSITY_MAP = {
	{ AIR, 0.f },
	{ SAND, 0.7f },
	{ WATER, 0.4f },
	{ WATER_VAPOR, -0.1f },
	{ STONE, 1.0f},
	{ ICE, 1.f },
	{ SPOUT, 1.f },
	{ FIRE, -0.1f },
	{ EMBER, 0.5f },
	{ SMOKE, -0.1f },
	{ ASH, 0.3f },
	{ WOOD, 1.0f },
	{ BORDER, 99.f} };

static std::map<Element, bool> FLAMMABLE_MAP = {
	{ AIR, false },
	{ SAND, false },
	{ WATER, false },
	{ WATER_VAPOR, false },
	{ STONE, false },
	{ ICE, false },
	{ SPOUT, false },
	{ FIRE, false },
	{ EMBER, false },
	{ SMOKE, false },
	{ ASH, false},
	{ WOOD, true },
	{ BORDER, false } };