#include "pch.h"

#include "CNode.h"

CNode::CNode()
{
	m_left = nullptr;
	m_right = nullptr;
}

CNode::~CNode()
{
}

CDegital::CDegital(string name) :
	m_name(name)
{
}

CDegital::~CDegital()
{
}

long long CDegital::calc()
{
	return stoll(m_name);
}

long long CPlus::calc()
{
	long long left = LLONG_MAX;
	long long right = LLONG_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return LLONG_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return LLONG_MAX;

	return left + right;
}

long long CMultiply::calc()
{
	long long left = LLONG_MAX;
	long long right = LLONG_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return LLONG_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return LLONG_MAX;

	return left * right;
}