#ifndef Collider_H
#define Collider_H

#include <vector>
#include "SFML/Graphics.hpp"

class Collider
{
typedef std::vector<sf::Vector2f> VectorArray;
public:
	Collider();
	virtual ~Collider();

	void Collision(Collider* col);
	void ClearCollisionTable();
	void AddHitboxVertex(const sf::Vector2f& point, int i = 0);
	void AddHitboxVertex(float x, float y, int i = 0);
	void ClearHitbox(int i = 0);
	void CalculateEdges();

	const sf::VertexArray& GetHitbox(int i = 0) const {return m_Points[i];}
	unsigned int GetHitboxCounter() {return m_Points.size();}
	const std::vector<sf::Vector2f>& GetHitboxEdges(int i = 0) const {return m_Edges[i];}

protected:
private:
	bool m_Solid;
	//std::vector<sf::Vector2f> m_Points;
	//sf::VertexArray m_Points;
	//std::vector<sf::Vector2f> m_Edges;
	std::vector<sf::VertexArray> m_Points;
	std::vector<VectorArray> m_Edges;
};

#endif // Collider_H
