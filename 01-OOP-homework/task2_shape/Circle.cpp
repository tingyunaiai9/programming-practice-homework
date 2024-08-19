#include "Circle.h"

Circle::Circle(double radius) :
	m_radius(radius)
{
}

double Circle::getarea()
{
	return 3.1416 * m_radius * m_radius;
}
