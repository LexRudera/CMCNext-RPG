#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Object.hpp"
#include "Background.hpp"

namespace lpe{
class Scene {
public:
	/** Default constructor */
	Scene();
	/** Default destructor */
	virtual ~Scene();
	void DoLoad();
	void DoTick();
	void DoRender(sf::RenderTarget& target);
	Background* GetBackground() {
		return m_Background;
	}
	void ApplyBackground(Background* bg) {
		m_Background = bg;
	}

	float GetWidth();
	float GetHeight();
protected:
	virtual void Load() = 0;
	virtual void Tick();
	virtual void Render(sf::RenderTarget& target);
	virtual void OnClose();

	std::vector<Object*> m_Objects;
private:
	Background* m_Background = 0;
};
}
#endif // SCENE_H
