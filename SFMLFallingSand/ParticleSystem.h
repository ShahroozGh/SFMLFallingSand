#pragma once
#include <SFML\Graphics.hpp>
#include "ParticleBase.h"


class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
	ParticleSystem();
	ParticleSystem(int winWidth, int winHeight);
	~ParticleSystem();

	void update();
	void refreshScreen();
	void addParticles(int x, int y, int brushSize);

	float getTempFromMouse(int x, int y);

	Element ADD_TYPE;

	bool SHOW_TEMP_COLOR;
	bool USE_GRAY_SCALE_TEMP;
	bool USE_TEMPERATURE_MODEL;


private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// our particles don't use a texture
		states.texture = NULL;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	sf::VertexArray m_vertices;
	
	std::vector<std::vector<ParticleBase> > grid;

	int WINDOW_WIDTH, WINDOW_HEIGHT;
	int WIN_TILE_WIDTH, WIN_TILE_HEIGHT;
	int TILE_SIZE;

	

	void initVerticies();

	

	void swap(int x1, int y1, int x2, int y2);
	void replace(int x1, int y1, Element type);
	void addParticle(int x1, int y1, ParticleBase particle);
	void ignite(int x, int y);
	void putOut(int x, int y);

	void updateTileColor(int x, int y, Element type);
	sf::Color tempToColor(float temp);

	//Returns true if e1 more dense than e2
	bool isMoreDense(Element e1, Element e2);
	

	//Gets ptr to [0] of quad at x,y
	sf::Vertex* getQuad(int x, int y);

};

