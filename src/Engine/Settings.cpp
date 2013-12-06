#include "Settings.hpp"
namespace lpe{
Settings::Settings() : m_ShowFps(true),
					   m_DebugLines(true),
					   m_DebugHitboxes(true)
{
	//ctor
}

Settings::~Settings() {
	//dtor
}
}
