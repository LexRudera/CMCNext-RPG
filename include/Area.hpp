#ifndef AREA_H
#define AREA_H

#include "Scene.hpp"
#include "AreaCollider.hpp"

class Area : public lpe::Scene, public AreaCollider
{
public:
	Area();
	virtual ~Area();
protected:
private:
};

#endif // AREA_H
