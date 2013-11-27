#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML\Graphics.hpp>
#include <vector>

class Spritesheet : public sf::Drawable
{
public:
	struct Sheet {
		const sf::Texture* image;
		int TileWidth;
		int TileHeight;
		int TilesX;
		int TilesY;
		sf::Vector2f OffsetPos;
	};
	struct Frame {
	Frame(int a_sheet, int a_tilex, int a_tiley, float a_durmul = 1) : sheet(a_sheet), tileX(a_tilex), tileY(a_tiley), durationMultiplier(a_durmul) {}

		int sheet;
		int tileX;
		int tileY;
		float durationMultiplier;
	};
	struct SpriteSequence {
		std::string sequenceName;
		std::vector<Frame> frames;
		int intervalMilliseconds;
	};

	// De/Constructors
	Spritesheet();
	virtual ~Spritesheet();

	bool AddSheet(const sf::Texture* tex, int tilesX = 1, int tilesY = 1, int tileWidth = 0, int tileHeight = 0);
	Sheet* GetSheet(int i) {return &m_Sheets[i];}
	bool AddSequence(const char* name, unsigned int frames[][3], int n, int fps);
	bool AddSequence(const char* name, std::vector<Frame>& frames, int fps);
	bool ActivateSequence(const char* seq);
	void Align(int x, int y,int sheet = -1);
	void tick();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	std::vector<Sheet> m_Sheets;
	std::vector<SpriteSequence> m_Sequences;
	int m_ActiveSequenceIndex = -1;
	sf::Sprite m_sprite;
	int m_CurrentSequenceIndex;
	sf::Time m_LastFrameChange;
	sf::Clock m_clk;

	bool ActivateFrame(Frame& frm, bool clocking = true);
	void ReloadFrame();
};

#endif // SPRITESHEET_H
