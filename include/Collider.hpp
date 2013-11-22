#ifndef Collider_H
#define Collider_H

#include <vector>
#include "SFML/Graphics.hpp"

class Collider
{
public:
	Collider();
	virtual ~Collider();

	void Collision(Collider* col);
	void ClearCollisionTable();
	void AddHitboxVertex(const sf::Vector2f& point);
	void ClearHitbox();
	void CalculateEdges();

	const sf::VertexArray& GetHitbox() const {return m_Points;}
	const std::vector<sf::Vector2f>& GetEdges() const {return m_Edges;}
protected:
private:
	bool m_Solid;
	//std::vector<sf::Vector2f> m_Points;
	sf::VertexArray m_Points;
	std::vector<sf::Vector2f> m_Edges;
};

#endif // Collider_H
