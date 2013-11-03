#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML\Graphics\Drawable.hpp>
#include <vector>

class Spritesheet : public sf::Drawable
{
public:
	Spritesheet();
	virtual ~Spritesheet();
protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	typedef struct {
		sf::Texture* image = 0;
		int TileWidth = 0;
		int TileHeight = 0;
		int TilesX = 0;
		int TilesY = 0;
	} Sheet;

	std::vector<Sheet> m_Sheets;
};

#endif // SPRITESHEET_H
