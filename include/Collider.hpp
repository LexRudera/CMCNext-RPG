#ifndef Collider_H
#define Collider_H

#include <vector>
#include "SFML/Graphics.hpp"

class Entity;
class Collider
{
friend Entity;
typedef std::vector<sf::Vector2f> VectorArray;
public:
	Collider();
	virtual ~Collider();

	void Collision(Collider* col);
	void AddHitboxVertex(const sf::Vector2f& point, int i = 0);
	void AddHitboxVertex(float x, float y, int i = 0);
	void CalculateHitboxes();

	const sf::VertexArray& GetHitbox(int i = 0) const {return m_Points[i];}
	const sf::Vector2f& GetCenter(int i = 0) const {return m_Centers[i];}
	unsigned int GetHitboxCounter() {return m_Points.size();}
	const std::vector<sf::Vector2f>& GetHitboxEdges(int i = 0) const {return m_Edges[i];}
	Entity* GetEntityRoot() { return m_ColliderEntityRoot; }

protected:
private:
	bool m_Solid;
	std::vector<sf::VertexArray> m_Points;
	std::vector<VectorArray> m_Edges;
	std::vector<sf::Vector2f> m_Centers;
	sf::Vector2f* m_ColliderVelocity = 0;
	Entity* m_ColliderEntityRoot = 0;

	void ProjectPolygon(sf::Vector2f axis, Collider*, unsigned int HitboxIndex, float& min, float& max);
	float IntervalDistance(float minA, float maxA, float minB, float maxB);
};

#endif // Collider_H
