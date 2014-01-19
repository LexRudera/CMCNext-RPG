#include "Collider.hpp"
#include "Utilities.hpp"
#include <limits>
#include "Entity.hpp"
#include "Debugroom.hpp"
#include "Characters\TruffleMint.hpp"

Collider::Collider() : m_Solid(true)
{
	//m_Points.push_back(sf::VertexArray(sf::PrimitiveType::LinesStrip));
	//m_Edges.push_back(VectorArray());
	//ctor
}

Collider::~Collider()
{
	//dtor
}

void Collider::Collision(Collider* col) {
	for (unsigned int i = 0; i < this->GetHitboxCounter(); i++) // This' hitboxes, i
	{
		int thisEdgeCount = this->GetHitboxEdges(i).size();
		for (unsigned int j = 0; j < col->GetHitboxCounter(); j++) //Col' hitboxes, j
		{
			bool Intersect = true;
			bool WillIntersect = true;
			float minIntervalDistance = std::numeric_limits<float>::max();
			sf::Vector2f translationAxis;
			sf::Vector2f edge;

			// Loop through all the edges of both polygons
			int colEdgeCount = col->GetHitboxEdges(j).size();
			for (int edgeIndex = 0; edgeIndex < thisEdgeCount + colEdgeCount; edgeIndex++) {
				if (edgeIndex < thisEdgeCount) {
					edge = this->GetHitboxEdges(i)[edgeIndex];
				} else {
					edge = col->GetHitboxEdges(j)[edgeIndex - thisEdgeCount];
				}

				// ===== 1. Find if the polygons are currently intersecting =====

				// Find the axis perpendicular to the current edge
				sf::Vector2f axis = sf::Vector2f(-edge.y, edge.x);
				//sf::Vector2f axis = sf::Vector2f(-edge.y, edge.x);
				NormalizeRef(axis);

				// Find the projection of the polygon on the current axis
				float minA, minB, maxA, maxB;
				ProjectPolygon(axis, this, i, minA, maxA);
				ProjectPolygon(axis, col, j, minB, maxB);

				// Check if the polygon projections are currentlty intersecting
				if (IntervalDistance(minA, maxA, minB, maxB) > 0) {
					Intersect = false;
				}

				// ===== 2. Now find if the polygons *will* intersect =====

				// Project the velocity on the current axis
				float velocityProjection = DotProduct(axis, *m_ColliderVelocity);

				// Get the projection of polygon A during the movement
				if (velocityProjection < 0) {
					minA += velocityProjection;
				} else {
					maxA += velocityProjection;
				}

				// Do the same test as above for the new projection
				float intervalDistance = IntervalDistance(minA, maxA, minB, maxB);
				if (intervalDistance > 0) WillIntersect = false;

				// If the polygons are not intersecting and won't intersect, exit the loop
				if (!Intersect && !WillIntersect) break;

				// Check if the current interval distance is the minimum one. If so store
				// the interval distance and the current distance.
				// This will be used to calculate the minimum translation sf::Vector2f
				intervalDistance = std::abs(intervalDistance);
				if (intervalDistance < minIntervalDistance)
				{
					minIntervalDistance = intervalDistance;
					translationAxis = axis;

					//sf::Vector2f d = this->GetCenter(i) - col->GetCenter(j);
					sf::Vector2f d;
					if (!this->m_ColliderEntityRoot) 	// Background
						if (!col->m_ColliderEntityRoot) //Background
							d = this->GetCenter(i) - col->GetCenter(j);
						else 							//Entity
							d = this->GetCenter(i) - (col->GetCenter(j)+ static_cast<Entity*>(col)->getPosition());
					else 								// Entity
						if (!col->m_ColliderEntityRoot) //Background
							d = (this->GetCenter(i) + GetEntityRoot()->getPosition()) - col->GetCenter(j);
						else //Entity
							d = (this->GetCenter(i) + GetEntityRoot()->getPosition()) - (col->GetCenter(j)+ static_cast<Entity*>(col)->getPosition());
					if (DotProduct(d, translationAxis) < 0) translationAxis = -translationAxis;
				}
			}
			if (WillIntersect) *m_ColliderVelocity += translationAxis * minIntervalDistance;
		}
	}
}

void Collider::ProjectPolygon(sf::Vector2f axis, Collider* col, unsigned int HitboxIndex, float& min, float& max) {
// To project a point on an axis use the dot product
	float d;
	if (!col->m_ColliderEntityRoot) d = min = max = DotProduct(axis, col->GetHitbox(HitboxIndex)[0].position);
	else 							d = min = max = DotProduct(axis, col->GetHitbox(HitboxIndex)[0].position + col->m_ColliderEntityRoot->getPosition() - col->m_ColliderEntityRoot->getOrigin());

	for (int i = 1; i < col->GetHitbox(HitboxIndex).getVertexCount(); i++) {
		if (!col->m_ColliderEntityRoot) d = DotProduct(col->GetHitbox(HitboxIndex)[i].position, axis);
		else 							d = DotProduct(col->GetHitbox(HitboxIndex)[i].position + col->m_ColliderEntityRoot->getPosition() - col->m_ColliderEntityRoot->getOrigin(), axis);
		if (d < min)
			min = d;
		 else if (d > max)
			max = d;
	}
}

float Collider::IntervalDistance(float minA, float maxA, float minB, float maxB) {
	if (minA < minB) {
		return minB - maxA;
	} else {
		return minA - maxB;
	}
}

void Collider::AddHitboxVertex(const sf::Vector2f& point, int i) {
	if (i >= m_Points.size())
		for (unsigned int j = 0; j < i-m_Points.size()+1; j++) {
			m_Points.push_back(sf::VertexArray(sf::PrimitiveType::LinesStrip));
			m_Edges.push_back(VectorArray());
		}
	m_Points[i].append(sf::Vertex(point));
}

void Collider::AddHitboxVertex(float x, float y, int i) {
	AddHitboxVertex(sf::Vector2f(x,y), i);
}

void Collider::CalculateHitboxes() {
	sf::Vertex* p1;
	sf::Vertex* p2;
	m_Centers.clear();
	for (unsigned int i = 0; i < m_Points.size(); i++) {
		float totalX = 0;
		float totalY = 0;
		m_Edges[i].clear();
		// Edges
		for (unsigned int j = 0; j < m_Points[i].getVertexCount(); j++) {
			p1 = &m_Points[i][j];
			if (i + 1 >= m_Points[i].getVertexCount()) {
			p2 = &m_Points[i][0];
			} else {
				p2 = &m_Points[i][j + 1];
			}
			m_Edges[i].push_back((p2->position) - (p1->position));
			// Center
			totalX += m_Points[i][j].position.x;
			totalY += m_Points[i][j].position.y;
		}
		m_Centers.push_back(sf::Vector2f(totalX / (float)m_Points[i].getVertexCount(), totalY / (float)m_Points[i].getVertexCount()));
	}
}

