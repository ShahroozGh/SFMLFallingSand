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
	void addParticle(int x, int y);

	Element ADD_TYPE;


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

	struct Particle {
		int type;
		sf::Vector2i position;
	};

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;

	
	std::vector<std::vector<ParticleBase> > grid;

	int WINDOW_WIDTH, WINDOW_HEIGHT;
	int WIN_TILE_WIDTH, WIN_TILE_HEIGHT;
	int TILE_SIZE;

	

	void initVerticies();
	void swap(int x1, int y1, int x2, int y2);


	//Returns true if e1 more dense than e2
	bool isMoreDense(Element e1, Element e2);
	

	//Gets ptr to [0] of quad at x,y
	sf::Vertex* getQuad(int x, int y);

};

