#pragma once

#include "CNode.h"

class CFormula
{
private:
	typedef vector<CNode*> NodeVec;

	string m_instr;
	NodeVec m_treenode;
	NodeVec m_polishorder;
};

