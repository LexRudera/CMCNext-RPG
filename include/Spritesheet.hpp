#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML\Graphics\Drawable.hpp>
#include <vector>

class Spritesheet : public sf::Drawable
{
public:
	Spritesheet();
	virtual ~Spritesheet();
	void AddSheet(sf::Texture* tex, int tileWidth, int tileHeight, int tilesX, int tilesY);
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	struct Sheet {
		sf::Texture* image = 0;
		int TileWidth = 0;
		int TileHeight = 0;
		int TilesX = 0;
		int TilesY = 0;
	};

	std::vector<Sheet> m_Sheets;
};

#endif // SPRITESHEET_H
