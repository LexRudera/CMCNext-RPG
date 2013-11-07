#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML\Graphics.hpp>
#include <vector>

class Spritesheet : public sf::Drawable
{
public:
	Spritesheet();
	virtual ~Spritesheet();
	bool AddSheet(const sf::Texture* tex, int tilesX = 1, int tilesY = 1, int tileWidth = 0, int tileHeight = 0);
	bool AddSequence(const char* name, unsigned int frames[][3], int n, int interval);
	bool ActivateSequence(const char* seq);
	void tick();
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	struct Sheet {
		const sf::Texture* image;
		unsigned int TileWidth;
		unsigned int TileHeight;
		unsigned int TilesX;
		unsigned int TilesY;
	};
	struct Frame {
		int sheet;
		int tileX;
		int tileY;
	};
	struct SpriteSequence {
		std::string sequenceName;
		std::vector<Frame> frames;
		unsigned int intervalMillisec;
	};

	std::vector<Sheet> m_Sheets;
	std::vector<SpriteSequence> m_Sequences;
	SpriteSequence* m_ActiveSequence = 0;
	Frame* m_ActiveFrame = 0;
	sf::Sprite m_sprite;
	unsigned int m_CurrentSequenceIndex;
	sf::Time m_LastFrameChange;

	bool ActivateFrame(Frame& frm);
};

#endif // SPRITESHEET_H
