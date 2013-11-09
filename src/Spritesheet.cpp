#include "Spritesheet.hpp"
#include "Utilities.hpp"

Spritesheet::Spritesheet()
{
	//ctor
}

Spritesheet::~Spritesheet()
{
	//dtor
}

bool Spritesheet::AddSheet(const sf::Texture* tex, int tilesX, int tilesY, int tileWidth, int tileHeight) {
	if (tex == 0) return false;
	Sheet s;
	s.image = tex;
	s.TilesX = tilesX;
	s.TilesY = tilesY;
	if (tileWidth == 0) s.TileWidth = tex->getSize().x/tilesX;
	else s.TileWidth = tileWidth;
	if (tileHeight == 0) s.TileHeight = tex->getSize().y/tilesY;
	else s.TileHeight = tileHeight;
	m_Sheets.push_back(s);
	return true;
}

bool Spritesheet::AddSequence(const char* name, unsigned int frames[][3], int n, int fps) {
	SpriteSequence s;
	s.sequenceName = name;
	for (int i = 0; i<n;i++) {
		Frame f;
		f.sheet = frames[i][0];
		f.tileX = frames[i][1];
		f.tileY = frames[i][2];
		s.frames.push_back(f);
	}
	if (fps) s.intervalMilliseconds = 1000/fps;
	else s.intervalMilliseconds = 0;
	m_Sequences.push_back(s);
	if (m_ActiveSequenceItem == -1) ActivateSequence(name);
	return true;
}

bool Spritesheet::ActivateSequence(const char* seq) {
	if (m_ActiveSequenceItem != -1) {
		if (m_Sequences[m_ActiveSequenceItem].sequenceName.compare(seq) == 0) {
			return true;
		}
	}
	for (unsigned int i = 0; i < m_Sequences.size(); i++) {
		if (m_Sequences[i].sequenceName.compare(seq) == 0) {
			m_ActiveSequenceItem = i;
			ActivateFrame(m_Sequences[i].frames[0]);
			m_CurrentSequenceIndex = 0;
			return true;
		}
	}
	return false;
}

void Spritesheet::tick() {
	if (m_Sequences[m_ActiveSequenceItem].frames.size() <= 1 || m_Sequences[m_ActiveSequenceItem].intervalMilliseconds == 0) // There's animation!
		return;
	if (m_clk.getElapsedTime().asMilliseconds() >= m_Sequences[m_ActiveSequenceItem].intervalMilliseconds) { // Let's change frame!
		lpe::Log(lpe::to_string(m_CurrentSequenceIndex));
		if (m_CurrentSequenceIndex < m_Sequences[m_ActiveSequenceItem].frames.size()) { // Within range
			ActivateFrame(m_Sequences[m_ActiveSequenceItem].frames[m_CurrentSequenceIndex]);
			m_CurrentSequenceIndex++;
		}
		else { //Reset
			m_CurrentSequenceIndex = 0;
			ActivateFrame(m_Sequences[m_ActiveSequenceItem].frames[m_CurrentSequenceIndex]);
			m_CurrentSequenceIndex++;
		}
	}
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_ActiveSequenceItem == -1)
		return;
	target.draw(m_sprite, states);
}

bool Spritesheet::ActivateFrame(Frame& frm) {
	// Set the sheet
	m_sprite.setTexture(*m_Sheets[frm.sheet].image);
	// Set the renderet rectangle
	//lpe::Log(lpe::to_string(frm.tileX*m_Sheets[frm.sheet].TileWidth));
	//lpe::Log(lpe::to_string(frm.tileY*m_Sheets[frm.sheet].TileHeight));
	//lpe::Log(lpe::to_string(m_Sheets[frm.sheet].TileWidth));
	//lpe::Log(lpe::to_string(m_Sheets[frm.sheet].TileHeight));
	sf::IntRect rect(frm.tileX*m_Sheets[frm.sheet].TileWidth, frm.tileY*m_Sheets[frm.sheet].TileHeight, m_Sheets[frm.sheet].TileWidth, m_Sheets[frm.sheet].TileHeight);
	m_sprite.setTextureRect(rect);
	m_clk.restart();
}
