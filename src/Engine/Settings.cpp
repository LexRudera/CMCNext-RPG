#include "Settings.hpp"
namespace lpe{
Settings::Settings() : m_ShowFps(true),
					   m_DebugLines(false),
					   m_DebugHitboxes(true)
{
	//ctor
}

Settings::~Settings() {
	//dtor
}
}
