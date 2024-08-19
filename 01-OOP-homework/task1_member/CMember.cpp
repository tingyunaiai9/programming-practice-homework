#include "CMember.h"

Member::Member(std::string name, int age) :
	m_name(name), m_age(age)
{
}

Member::~Member()
{
}

std::ostream& operator<<(std::ostream& os, const Member& m)
{
	os << "Name: " << m.m_name << ", Age: " << m.m_age;
	return os;
}