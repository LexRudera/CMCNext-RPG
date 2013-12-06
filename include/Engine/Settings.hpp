// The Encapsulated Settings
//------------------------------------------------------------------
// The class containing all the in-game settings.

#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML\Graphics.hpp>
namespace lpe{
class Settings {
public:
	/** Default constructor */
	Settings();
	/** Default destructor */
	virtual ~Settings();

	// Accessor functions
	bool ShowFps() 				{return m_ShowFps;}
	void ShowFps(bool a) 		{m_ShowFps = a;}
	bool DebugLines() 			{return m_DebugLines;}
	void DebugLines(bool a) 	{m_DebugLines = a;}
	bool DebugHitboxes() 		{return m_DebugHitboxes;}
	void DebugHitboxes(bool a) 	{m_DebugHitboxes = a;}
protected:
private:
	bool m_ShowFps;
	sf::VideoMode m_VideoMode;
	bool m_DebugLines;
	bool m_DebugHitboxes;
};
}
#endif // SETTINGS_H
