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
lpe::Log("AS1");
	SpriteSequence s;
lpe::Log("AS2");
	s.sequenceName = name;
lpe::Log("AS3");
	for (int i = 0; i<n;i++) {
		Frame f;
		f.sheet = frames[i][0];
		f.tileX = frames[i][1];
		f.tileY = frames[i][2];
		s.frames.push_back(f);
	}
lpe::Log("AS4");
	if (fps) s.intervalMilliseconds = 1000/fps;
	else s.intervalMilliseconds = 0;
lpe::Log("AS5");
	m_Sequences.push_back(s);
lpe::Log("AS6");
	if (m_ActiveSequence == 0) ActivateSequence(name);
	return true;
}

bool Spritesheet::ActivateSequence(const char* seq) {
lpe::Log("Ac1");
	if (m_ActiveSequence != 0) {
	lpe::Log("Ac11");
	std::string a = m_ActiveSequence->sequenceName;
	lpe::Log("Ac12");
		if (a.compare(seq))
			return true;
	}
lpe::Log("Ac2");
	for (unsigned int i = 0; i < m_Sequences.size(); i++) {
		if (m_Sequences[i].sequenceName.compare(seq) == 0) {
lpe::Log("Ac3");
			m_ActiveSequence = &m_Sequences[i];
lpe::Log("Ac4");

			ActivateFrame(m_Sequences[i].frames[0]);
lpe::Log("Ac5");
			m_CurrentSequenceIndex = 0;
lpe::Log("Ac6");
			return true;
		}
	}
	return false;
}

void Spritesheet::tick() {
	if (m_ActiveSequence->frames.size() <= 1 || m_ActiveSequence->intervalMilliseconds == 0) // There's animation!
		return;
	if (m_clk.getElapsedTime().asMilliseconds() >= m_ActiveSequence->intervalMilliseconds) // Let's change frame!
		if (m_CurrentSequenceIndex < m_ActiveSequence->frames.size()) { // Within range
			ActivateFrame(m_ActiveSequence->frames[m_CurrentSequenceIndex]);
			m_CurrentSequenceIndex++;
		}
		else { //Reset
			m_CurrentSequenceIndex = 0;
			ActivateFrame(m_ActiveSequence->frames[m_CurrentSequenceIndex]);
		}
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_ActiveSequence == 0)
		return;
	target.draw(m_sprite, states);
}

bool Spritesheet::ActivateFrame(Frame& frm) {
	// Set the sheet
	m_sprite.setTexture(*m_Sheets[frm.sheet].image);
	// Set the renderet rectangle
	sf::IntRect rect(frm.tileX*m_Sheets[frm.sheet].TileWidth, frm.tileY*m_Sheets[frm.sheet].TileHeight, m_Sheets[frm.sheet].TileWidth, m_Sheets[frm.sheet].TileHeight);
	m_sprite.setTextureRect(rect);
	m_clk.restart();
}
