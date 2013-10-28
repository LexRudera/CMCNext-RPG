#ifndef CONTROLSSHARED_H_INCLUDED
#define CONTROLSSHARED_H_INCLUDED

namespace lpe {
struct BoxStyle {
	BoxStyle(const sf::Texture* tex, sf::Color fill, sf::Color outl, float thcknss)
		: Background(tex),
		  OutlineColour(outl),
		  FillColour(fill),
		  OutlineThickness(thcknss) {
		/*Background = tex;
		OutlineColour = outl;
		FillColour = fill;
		OutlineThickness = thcknss;*/
	}
	~BoxStyle() {
	}
	const sf::Texture* Background;
	sf::Color OutlineColour;
	sf::Color FillColour;
	float OutlineThickness;
};
}
#endif // CONTROLSSHARED_H_INCLUDED
