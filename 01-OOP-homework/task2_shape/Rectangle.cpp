#include "Rectangle.h"

Rectangle::Rectangle(double w, double h) :
	m_width(w), m_height(h)
{
}

double Rectangle::getarea()
{
	return m_width * m_height;
}