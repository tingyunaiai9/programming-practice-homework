#include "CMember.h"

Member::Member(std::string name, int age) :
	m_name(name), m_age(age)
{
}

Member::~Member()
{
}

ostream& operator<<(ostream& os, const Member& m)
{
	if (m.m_age == -1)
	{
		os << "";
	}
	else
	{
		os << "Name: " << m.m_name << ", Age: " << m.m_age;
	}
	return os;
}

string Member::getName() const
{
	return m_name;
}

int Member::getAge() const
{
	return m_age;
}