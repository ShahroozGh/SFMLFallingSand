#include "ParticleSystem.h"



ParticleSystem::ParticleSystem()
{

	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(4);

}

ParticleSystem::ParticleSystem(int winWidth, int winHeight)
{
	ADD_TYPE = WATER;

	TILE_SIZE = 2;
	WINDOW_WIDTH = winWidth;
	WINDOW_HEIGHT = winHeight;

	WIN_TILE_WIDTH = winWidth / TILE_SIZE;
	WIN_TILE_HEIGHT = winHeight / TILE_SIZE;


	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(WIN_TILE_WIDTH * WIN_TILE_HEIGHT * 4);

	

	//Init grid
	for (int x = 0; x < WIN_TILE_WIDTH; x++) {
		grid.push_back(std::vector<ParticleBase>(WIN_TILE_HEIGHT));
		for (int y = 0; y < WIN_TILE_HEIGHT; y++) {
			if (x == 10 && y == 50)
				grid[x][y] = ParticleBase(SAND, x, y);
			else if (x == 0 || x == WIN_TILE_WIDTH - 1 || y == 0 || y == WIN_TILE_HEIGHT - 1) {
				grid[x][y] = ParticleBase(BORDER, x, y);
			}
			else if (y <= 350/2) {
				grid[x][y] = ParticleBase(WATER, x, y);
			}
			else
				grid[x][y] = ParticleBase(AIR, x, y);
		}
	}

	initVerticies();
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::initVerticies()
{
	for (int x = 0; x < WIN_TILE_WIDTH; x++) {
		for (int y = 0; y < WIN_TILE_HEIGHT; y++) {
			sf::Vertex* quad = getQuad(x, y);

			// define its 4 corners
			quad[0].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE);
			quad[1].position = sf::Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE);
			quad[2].position = sf::Vector2f(x * TILE_SIZE + TILE_SIZE, y * TILE_SIZE + TILE_SIZE);
			quad[3].position = sf::Vector2f(x * TILE_SIZE, y * TILE_SIZE + TILE_SIZE);

			//Set colors
			// define its 4 corners
			/*
			quad[0].color = sf::Color::Black;
			quad[1].color = sf::Color::Black;
			quad[2].color = sf::Color::Black;
			quad[3].color = sf::Color::Black;
			*/
			updateTileColor(x,y,grid[x][y].type);


		}
	}

}

void ParticleSystem::swap(int x1,int y1,int x2,int y2)
{
	ParticleBase temp = grid[x1][y1];
	grid[x1][y1] = grid[x2][y2];
	grid[x2][y2] = temp;

	grid[x1][y1].moved = true;
	grid[x2][y2].moved = true;
	//Update vertex array here
	updateTileColor(x1, y1, grid[x1][y1].type);
	updateTileColor(x2, y2, grid[x2][y2].type);
}

void ParticleSystem::replace(int x1, int y1, Element type)
{

	grid[x1][y1] = ParticleBase(type, x1, y1);
	updateTileColor(x1, y1, type);

}

void ParticleSystem::addParticle(int x1, int y1, ParticleBase particle)
{
	grid[x1][y1] = particle;
	//Update vertexArray color
	updateTileColor(x1, y1, particle.type);
}

void ParticleSystem::updateTileColor(int x, int y, Element type)
{
	sf::Color color;
	/*
	if (type == AIR)
		color = sf::Color::Black;
	else if (type == SAND)
		color = sf::Color::Yellow;
	else if (type == WATER)
		color = sf::Color::Blue;
	else if (type == STONE)
		color = sf::Color(211, 211, 211); //Light grey
	else if (type == ICE)
		color = sf::Color(140, 255, 255); //Very close to white
	else if (type == SPOUT)
		color = sf::Color(0, 0, 200); //Bluish
	else if (type == BORDER)
		color = sf::Color::Magenta;
	else if (type == FIRE)
		color = sf::Color::Red;
	else
		color = sf::Color::Red;
		*/
	color = grid[x][y].color;

	sf::Vertex* quad = getQuad(x, y);

	//Set colors
	// define its 4 corners
	quad[0].color = color;
	quad[1].color = color;
	quad[2].color = color;
	quad[3].color = color;

}



bool ParticleSystem::isMoreDense(Element e1, Element e2)
{
	return DENSITY_MAP[e1] > DENSITY_MAP[e2];
}

//Adds particle from mouseclick using pixel x,y
void ParticleSystem::addParticles(int x, int y, int brushSize)
{
	int xT = (x - (x % TILE_SIZE)) / TILE_SIZE;
	int yT = (y - (y % TILE_SIZE)) / TILE_SIZE;

	for (int i = 0; i < brushSize; i++) {
		for (int j = 0; j < brushSize; j++) {
			grid[xT + i - brushSize/2][yT + j - brushSize / 2] = ParticleBase(ADD_TYPE, xT, yT);
			updateTileColor(xT + i - brushSize / 2, yT + j - brushSize / 2, ADD_TYPE);
		
		}

	}
	
}

sf::Vertex * ParticleSystem::getQuad(int x, int y)
{
	
	return &m_vertices[(x + y * WIN_TILE_WIDTH)*4];
	//return nullptr;
}

void ParticleSystem::update()
{
	//Do stuff
	//Get "SubArray" (Ptr to some multiple of 4 which is the beginning of a quad)
	sf::Vertex* quad = &m_vertices[0];


	for (int x = 0; x < WIN_TILE_WIDTH; x++) {
		for (int y = 0; y < WIN_TILE_HEIGHT; y++) {
			/*if (grid[x][y].moved) {
				grid[x][y].moved = false;
			}
			else {
				grid[x][y].update(grid);
			}
			*/
			
			
			ParticleBase curr = grid[x][y];
			//If already moved do nothing, reset moved flag?
			if (curr.moved)
				continue;
			
			//If air do nothing
			else if (curr.type == AIR)
				continue;
			else if (curr.type == FIRE) {
				//decriment life
				grid[x][y].life--;
				int life = grid[x][y].life;
				//Update color to match life time
				//Max life for fire is 20, min is 0
				//Red 255,0,0 -> Yellow 255,255,0 ->White 255,255,255
			
				grid[x][y].color = sf::Color(255, 12*life, 0.6*std::pow(life,2));
				

				if (grid[x][y].life == 0) {
					replace(x,y,AIR);
					continue;
				}

				int random = rand() % 100;
				//Check if it can set anything on fire
				if (grid[x - 1][y].type == WOOD && random < 5) {
					grid[x - 1][y].isBurning = true;
				}
				else if (grid[x][y - 1].type == WOOD && random < 10) {
					grid[x][y - 1].isBurning = true;
				}
				else if (grid[x + 1][y].type == WOOD && random < 10) {
					grid[x + 1][y].isBurning = true;
				}
				else if (grid[x][y + 1].type == WOOD && random < 15) {
					grid[x][y + 1].isBurning = true;
				}

				//Reverse gravity
				if (DENSITY_MAP[grid[x][y - 1].type] < DENSITY_MAP[curr.type]) {
					swap(x, y, x, y - 1);
				}

				if (grid[x][y - 1].type == FIRE || grid[x][y - 1].type != FIRE) {
					//Check if diagonals are open
					//Attempt to go diagonal up
					if (grid[x + 1][y - 1].type == AIR || grid[x - 1][y - 1].type == AIR) {
						int random = rand() % 2;

						if (random == 0) {
							if (grid[x + 1][y - 1].type == AIR)
								swap(x, y, x + 1, y - 1);
						}
						else {
							if (grid[x - 1][y - 1].type == AIR)
								swap(x, y, x - 1, y - 1);
						}
					}

					//Attempt to go sideways
					if (grid[x + 1][y].type == AIR || grid[x - 1][y].type == AIR) {
						int random = rand() % 2;

						if (random == 0) {
							if (grid[x + 1][y].type == AIR)
								swap(x, y, x + 1, y);
						}
						else {
							if (grid[x - 1][y].type == AIR)
								swap(x, y, x - 1, y);
						}
					}
				}
			}

			else if (curr.type == SAND) {

				//Gravity
				if (DENSITY_MAP[grid[x][y+1].type] < DENSITY_MAP[curr.type]){
					swap(x,y,x,y + 1);
				}
				if (grid[x][y + 1].type == WATER && curr.type == SAND) {
					swap(x, y, x, y + 1);
				}
				else if (grid[x][y + 1].type == SAND) {
					if (grid[x + 1][y + 1].type == AIR || grid[x - 1][y + 1].type == AIR) {
						int random = rand() % 2;

						if (random == 0) {
							if (grid[x+1][y+1].type == AIR)
								swap(x, y, x + 1, y + 1);
						}
						else {
							if (grid[x - 1][y + 1].type == AIR)
								swap(x, y, x - 1, y + 1);
						}
							
					}
				}
				
			}

			else if (curr.type == WATER) {
				
				//Check to put out any fire/decrease temperature
				if (grid[x][y + 1].type == FIRE)
					replace(x, y + 1, AIR);
				if (grid[x][y - 1].type == FIRE)
					replace(x, y - 1, AIR);
				if (grid[x + 1][y].type == FIRE)
					replace(x + 1, y, AIR);
				if (grid[x - 1][y].type == FIRE)
					replace(x - 1, y, AIR);
				

				//Gravity
				if (DENSITY_MAP[grid[x][y + 1].type] < DENSITY_MAP[curr.type]) {
					swap(x, y, x, y + 1);
				}
				else if (grid[x][y + 1].type == WATER) {
					//Attempt to go diagonal down
					if (grid[x + 1][y + 1].type == AIR || grid[x - 1][y + 1].type == AIR) {
						int random = rand() % 2;

						if (random == 0) {
							if (grid[x + 1][y + 1].type == AIR)
								swap(x, y, x + 1, y + 1);
						}
						else {
							if (grid[x - 1][y + 1].type == AIR)
								swap(x, y, x - 1, y + 1);
						}
					}

					//Attempt to go sideways
					if (grid[x + 1][y].type == AIR || grid[x - 1][y].type == AIR) {
						int random = rand() % 2;

						if (random == 0) {
							if (grid[x + 1][y].type == AIR)
								swap(x, y, x + 1, y);
						}
						else {
							if (grid[x - 1][y].type == AIR)
								swap(x, y, x - 1, y);
						}
					}


				}
			
			}

			else if (curr.type == STONE) {
			
			}

			else if (curr.type == WOOD) {
				int random = rand() % 100;
				if (grid[x][y].isBurning) {
					if (grid[x - 1][y].type == AIR && random < 5) {
						//grid[x - 1][y] = ParticleBase(WATER, x - 1, y);
						replace(x - 1, y, FIRE);
					}
					else if (grid[x][y - 1].type == AIR && random < 10) {
						//grid[x + 1][y] = ParticleBase(WATER, x + 1, y);
						replace(x, y - 1, FIRE);
					}
					else if (grid[x + 1][y].type == AIR && random < 10) {
						//grid[x + 1][y] = ParticleBase(WATER, x + 1, y);
						replace(x + 1, y, FIRE);
					}
					else if (grid[x][y + 1].type == AIR && random < 15) {
						//grid[x][y + 1] = ParticleBase(WATER, x, y + 1);
						replace(x, y + 1, FIRE);
					}
				
				}

			}

			else if (curr.type == ICE) {
				int random = rand() % 100;

				if (grid[x - 1][y].type == WATER && random < 2) {
					//grid[x - 1][y] = ParticleBase(ICE, x - 1, y);
					replace(x-1, y, ICE);
				}
				else if(grid[x + 1][y].type == WATER && random < 4){
					//grid[x + 1][y] = ParticleBase(ICE, x - 1, y);
					replace(x + 1, y, ICE);
				}
				else if (grid[x][y + 1].type == WATER && random < 6) {
					//grid[x][y + 1] = ParticleBase(ICE, x - 1, y);
					replace(x, y + 1, ICE);
				}
				else if (grid[x][y - 1].type == WATER && random < 8) {
					//grid[x][y - 1] = ParticleBase(ICE, x - 1, y);
					replace(x, y - 1, ICE);
				}
			}

			else if (curr.type == SPOUT) {
				int random = rand() % 100;

				if (grid[x - 1][y].type == AIR && random < 5) {
					//grid[x - 1][y] = ParticleBase(WATER, x - 1, y);
					replace(x - 1, y, WATER);
				}
				else if (grid[x + 1][y].type == AIR && random < 10) {
					//grid[x + 1][y] = ParticleBase(WATER, x + 1, y);
					replace(x + 1, y, WATER);
				}
				else if (grid[x][y + 1].type == AIR && random < 15) {
					//grid[x][y + 1] = ParticleBase(WATER, x, y + 1);
					replace(x, y + 1, WATER);
				}

			}

			


			
		}
	}

	
	//Reset moved flags
	for (int x = 0; x < WIN_TILE_WIDTH; x++) {
		for (int y = 0; y < WIN_TILE_HEIGHT; y++) {
			grid[x][y].moved = false;
			/*
			int type = grid[x][y].type;
			sf::Color color;
			if (type == AIR)
				color = sf::Color::Black;
			else if (type == SAND)
				color = sf::Color::Yellow;
			else if (type == WATER)
				color = sf::Color::Blue;
			else if (type == STONE)
				color = sf::Color(211, 211, 211); //Light grey
			else if (type == ICE)
				color = sf::Color(140, 255, 255); //Very close to white
			else if (type == SPOUT)
				color = sf::Color(0, 0, 200); //Bluish
			else if (type == BORDER)
				color = sf::Color::Magenta;
			else
				color = sf::Color::Red;

			sf::Vertex* quad = getQuad(x, y);

			//Set colors
			// define its 4 corners
			quad[0].color = color;
			quad[1].color = color;
			quad[2].color = color;
			quad[3].color = color;
			*/
			
		}
		
	}
	
}



