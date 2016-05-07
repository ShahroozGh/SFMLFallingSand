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
	{ EMBER, sf::Color(255,185,115) },
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

//Initial ambient temperatures (similar to kelvin)

//1636.15.0k <- Approx melting point of steel
//1143.15k <- A flame?
//973.15k <- Magma (cool)
//373.0k <- 100c boiling point of water
//310.0k <- 37c body temp
//290.0k <- 25c Room temp
//273.0k <- 0c Freezing point
//183.0k <- -130c lowest temp recorded

static std::map<Element, float> AMBIENT_TEMP_MAP = {
	{ AIR, 290.0f },
	{ SAND, 290.0f },
	{ WATER, 290.0f },
	{ WATER_VAPOR, 30.0f },
	{ STONE, 290.0f },
	{ ICE, 273.0f },
	{ SPOUT, 290.0f },
	{ FIRE, 500.0f },
	{ EMBER, 700.0f },
	{ SMOKE, 320.0f },
	{ ASH, 290.0f },
	{ WOOD, 290.0f },
	{ BORDER, -1.0f } };

//Determines resistance to change/transfer of temperature
//Heat Conductivity
static std::map<Element, float> TEMP_COEFF_MAP = {
	{ AIR, 0.01f },
	{ SAND, 1.0f },
	{ WATER, 5.0f },
	{ WATER_VAPOR, 1.0f },
	{ STONE, 1.0f },
	{ ICE, 5.0f },
	{ SPOUT, 1.0f },
	{ FIRE, 5.0f },
	{ EMBER, 1.0f },
	{ SMOKE, 1.0f },
	{ ASH, 1.0f },
	{ WOOD, 1.0f },
	{ BORDER, -1.0f } };


//Point of phase change between solid and liquid
static std::map<Element, float> SOLID_LIQUID_POINT = {
	{ SAND, 900.0f },
	{ WATER, 273.0f },
	{ ICE, 273.0f },
	{ STONE, 900.0f },
	{ BORDER, -1.0f } };

static std::map<Element, float> GAS_LIQUID_POINT = {
	{ WATER, 373.0f },
	{ WATER_VAPOR, 373.0f },
	{ BORDER, -1.0f } };

