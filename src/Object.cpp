#include "Object.hpp"
namespace lpe {
Object::Object() {
	//ctor
}

Object::~Object() {
	//dtor
}

void Object::DoTick() {
	if (m_Logic) {
		tick();
	}
}

void Object::tick() {

}
}
