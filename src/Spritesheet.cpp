#include "Spritesheet.hpp"

Spritesheet::Spritesheet()
{
	//ctor
}

Spritesheet::~Spritesheet()
{
	//dtor
}

void Spritesheet::AddSheet(sf::Texture* tex, int tileWidth, int tileHeight, int tilesX, int tilesY) {
	Sheet s;
	s.image = tex;
	s.TileWidth = tileWidth;
	s.TileHeight = tileHeight;
	s.TilesX = tilesX;
	s.TilesY = tilesY;
	m_Sheets.push_back(s);
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
}
