#include "Spritesheet.hpp"

Spritesheet::Spritesheet()
{
	//ctor
}

Spritesheet::~Spritesheet()
{
	//dtor
}

bool Spritesheet::AddSheet(sf::Texture* tex, int tilesX, int tilesY, int tileWidth, int tileHeight) {
	Sheet s;
	s.image = tex;
	s.TilesX = tilesX;
	s.TilesY = tilesY;
	if (tileWidth = 0) s.TileWidth = tex->getSize().x/tilesX;
	else s.TileWidth = tileWidth;
	if (tileHeight = 0) s.TileHeight = tex->getSize().y/tilesY;
	else s.TileHeight = tileHeight;
	m_Sheets.push_back(s);
}

bool Spritesheet::AddSequence(const char* name, int frames[][3], int n, int interval) {
	SpriteSequence s;
	s.sequenceName = name;
	for (int i = 0; i<n;i++) {
		Frame f;
		Frame.sheet = frames[i][0];
		Frame.tileX = frames[i][1];
		Frame.tileY = frames[i][2];
		s.frames.push_back(f)
	}
	s.intervalMillisec
}

bool Spritesheet::ActivateSequence(const char* seq) {
	a.compare()
	for (unsigned int i = 0; i < m_Sequences.size(); i++) {
		if (m_Sequences[i].sequenceName.compare(seq) == 0) {
			m_ActiveSequence = &m_Sequences[i];
			m_ActiveFrame = &m_Sequences[i].frames[0];
			return = true;
		}
	}
	return = false;
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_ActiveSequence == 0)
		return;
	target.draw(m_Sheets[m_ActiveFrame->sheet].image);
}
