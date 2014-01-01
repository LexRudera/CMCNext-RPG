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
		s.frames.push_back(Frame(frames[i][0], frames[i][1], frames[i][2]));
	}
	if (fps) s.intervalMilliseconds = 1000/fps;
	else s.intervalMilliseconds = 0;
	m_Sequences.push_back(s);
	if (m_ActiveSequenceIndex == -1) ActivateSequence(name);
	return true;
}
bool Spritesheet::AddSequence(const char* name, std::vector<Frame>& frames, int fps){
	SpriteSequence s;
	s.sequenceName = name;

	s.frames = frames;

	if (fps) s.intervalMilliseconds = 1000/fps;
	else s.intervalMilliseconds = 0;
	m_Sequences.push_back(s);
	if (m_ActiveSequenceIndex == -1) ActivateSequence(name);
	return true;
}

bool Spritesheet::ActivateSequence(const char* seq) {
	if (m_ActiveSequenceIndex != -1) {
		if (m_Sequences[m_ActiveSequenceIndex].sequenceName.compare(seq) == 0) {
			return true;
		}
	}
	for (unsigned int i = 0; i < m_Sequences.size(); i++) {
		if (m_Sequences[i].sequenceName.compare(seq) == 0) {
			m_CurrentSequenceIndex = 0;
			m_ActiveSequenceIndex = i;
			ActivateFrame(m_Sequences[i].frames[m_CurrentSequenceIndex]);
			return true;
		}
	}
	return false;
}

void Spritesheet::tick() {
	if (m_Sequences[m_ActiveSequenceIndex].frames.size() <= 1 || m_Sequences[m_ActiveSequenceIndex].intervalMilliseconds == 0) // There's animation!
		return;
	//Log( to_string(m_CurrentSequenceIndex+1) + "; " + to_string(m_clk.getElapsedTime().asMilliseconds()) + " >= " + to_string(m_Sequences[m_ActiveSequenceIndex].intervalMilliseconds) + " * " + to_string(m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex].durationMultiplier)    + " (" + to_string(m_Sequences[m_ActiveSequenceIndex].intervalMilliseconds * m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex].durationMultiplier) + ")");
	if (m_clk.getElapsedTime().asMilliseconds() >= m_Sequences[m_ActiveSequenceIndex].intervalMilliseconds * m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex-1].durationMultiplier) { // Let's change frame!
		//Log(to_string(m_CurrentSequenceIndex) + ", " + to_string(m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex].durationMultiplier));
		if (m_CurrentSequenceIndex < m_Sequences[m_ActiveSequenceIndex].frames.size()) { // Within range
			ActivateFrame(m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex]);
		}
		else { //Reset
			m_CurrentSequenceIndex = 0;
			ActivateFrame(m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex]);
		}
		m_CurrentSequenceIndex++;
	}
}

void Spritesheet::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (m_ActiveSequenceIndex == -1)
		return;
	target.draw(m_sprite, states);
}

bool Spritesheet::ActivateFrame(Frame& frm, bool clocking) {
	// Set the sheet
	//Log(to_string(m_CurrentSequenceIndex+1) + ", " + to_string(frm.durationMultiplier));
	m_sprite.setTexture(*m_Sheets[frm.sheet].image);
	//m_sprite.setPosition(-(m_Sheets[frm.sheet].TileWidth/2), -(m_Sheets[frm.sheet].TileHeight/2));
	m_sprite.setPosition(m_Sheets[frm.sheet].OffsetPos);
	// Set the renderet rectangle
	//Log(to_string(frm.tileX*m_Sheets[frm.sheet].TileWidth));
	//Log(to_string(frm.tileY*m_Sheets[frm.sheet].TileHeight));
	//Log(to_string(m_Sheets[frm.sheet].TileWidth));
	//Log(to_string(m_Sheets[frm.sheet].TileHeight));
	sf::IntRect rect(frm.tileX*m_Sheets[frm.sheet].TileWidth, frm.tileY*m_Sheets[frm.sheet].TileHeight, m_Sheets[frm.sheet].TileWidth, m_Sheets[frm.sheet].TileHeight);
	m_sprite.setTextureRect(rect);
	if (clocking) m_clk.restart();
}

void Spritesheet::ReloadFrame() {
	ActivateFrame(m_Sequences[m_ActiveSequenceIndex].frames[m_CurrentSequenceIndex], false);
}

void Spritesheet::Align(int x, int y,int sheet) {
	if (sheet != -1)
		m_Sheets[sheet].OffsetPos = sf::Vector2f(x,y);
	else
		for (unsigned int i = 0; i < m_Sheets.size(); i++)
			m_Sheets[i].OffsetPos = sf::Vector2f(x,y);
	ReloadFrame();
}

