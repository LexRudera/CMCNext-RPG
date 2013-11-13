#ifndef Collider_H
#define Collider_H


class Collider
{
public:
	Collider();
	virtual ~Collider();
	static void DetectAndCorrect();
protected:
private:
	bool m_solid;

};

#endif // Collider_H
