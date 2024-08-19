#include "Square.h"

Square::Square(double side) :
	m_side(side)
{
}

double Square::getarea()
{
	return m_side * m_side;
}