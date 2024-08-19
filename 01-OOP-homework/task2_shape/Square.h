#pragma once

#include "Shape.h"

class Square :
    public Shape
{
private:
    double m_side;

public:
    Square(double side);
	double getarea();
};

