#include "pch.h"

#include "CNode.h"

CNode::CNode()
{
	m_left = NULL;
	m_right = NULL;
}

CNode::~CNode()
{
	SAFE_DELETE(m_left);
	SAFE_DELETE(m_right);
}

CDegital::CDegital(string name) :
	m_name(name)
{
}

CDegital::~CDegital()
{
}

double CDegital::calc()
{
	return stod(m_name);
}

double CPlus::calc()
{
	double left = DBL_MAX;
	double right = DBL_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return DBL_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return DBL_MAX;

	return left + right;
}

double CMinus::calc() // left - right
{
	double left = DBL_MAX;
	double right = DBL_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return DBL_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return DBL_MAX;

	return left - right;
}

double CMultiply::calc()
{
	double left = DBL_MAX;
	double right = DBL_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return DBL_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return DBL_MAX;

	return left * right;
}

double CDivide::calc()
{
	double left = DBL_MAX;
	double right = DBL_MAX;

	if (m_left)
		left = m_left->calc();
	else
		return DBL_MAX;

	if (m_right)
		right = m_right->calc();
	else
		return DBL_MAX;

	if (right == 0)
		return DBL_MAX;

	return left / right;
}