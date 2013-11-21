#include "Collider.hpp"
#include "SFML/OpenGL.hpp"

Collider::Collider()
{
	//ctor
}

Collider::~Collider()
{
	//dtor
}

void Collider::Collision(Collider* col) {
	/*PolygonCollisionResult result = new PolygonCollisionResult();
	result.Intersect = true;
	result.WillIntersect = true;

	int edgeCountA = polygonA.Edges.Count;
	int edgeCountB = polygonB.Edges.Count;
	float minIntervalDistance = float.PositiveInfinity;
	sf::Vector2f translationAxis;
	sf::Vector2f edge;

	// Loop through all the edges of both polygons
	for (int edgeIndex = 0; edgeIndex < edgeCountA + edgeCountB; edgeIndex++) {
		if (edgeIndex < edgeCountA) {
			edge = polygonA.Edges[edgeIndex];
		} else {
			edge = polygonB.Edges[edgeIndex - edgeCountA];
		}

		// ===== 1. Find if the polygons are currently intersecting =====

		// Find the axis perpendicular to the current edge
		sf::Vector2f axis = new sf::Vector2f(-edge.Y, edge.X);
		axis.Normalize();

		// Find the projection of the polygon on the current axis
		float minA = 0; float minB = 0; float maxA = 0; float maxB = 0;
		ProjectPolygon(axis, polygonA, ref minA, ref maxA);
		ProjectPolygon(axis, polygonB, ref minB, ref maxB);

		// Check if the polygon projections are currentlty intersecting
		if (IntervalDistance(minA, maxA, minB, maxB) > 0) result.Intersect = false;

		// ===== 2. Now find if the polygons *will* intersect =====

		// Project the velocity on the current axis
		float velocityProjection = axis.DotProduct(velocity);

		// Get the projection of polygon A during the movement
		if (velocityProjection < 0) {
			minA += velocityProjection;
		} else {
			maxA += velocityProjection;
		}

		// Do the same test as above for the new projection
		float intervalDistance = IntervalDistance(minA, maxA, minB, maxB);
		if (intervalDistance > 0) result.WillIntersect = false;

		// If the polygons are not intersecting and won't intersect, exit the loop
		if (!result.Intersect && !result.WillIntersect) break;

		// Check if the current interval distance is the minimum one. If so store
		// the interval distance and the current distance.
		// This will be used to calculate the minimum translation sf::Vector2f
		intervalDistance = Math.Abs(intervalDistance);
		if (intervalDistance < minIntervalDistance) {
			minIntervalDistance = intervalDistance;
			translationAxis = axis;

			sf::Vector2f d = polygonA.Center - polygonB.Center;
			if (d.DotProduct(translationAxis) < 0) translationAxis = -translationAxis;
		}
	}

	// The minimum translation sf::Vector2f can be used to push the polygons appart.
	// First moves the polygons by their velocity
	// then move polygonA by MinimumTranslationsf::Vector2f.
	if (result.WillIntersect) result.MinimumTranslationVector = translationAxis * minIntervalDistance;

	return result;*/
}

void Collider::ClearCollisionTable() {
	//m_Intersecting.clear();
}
