#pragma once

#include "Shape.h"

class Circle :
    public Shape
{
private:
    double m_radius;

public:
	Circle(double radius);
	double getarea();
};

