#pragma once

#include "CNode.h"

class CFormula
{
private:
	typedef vector<CNode*> NodeVec;

	string m_instrFormula;
	NodeVec m_treenode;
	NodeVec m_inorder;
	NodeVec m_polishorder;

public:
	CFormula();
	~CFormula();

	bool load_formula(string formula);

private:
	bool to_treenode();

	bool to_inorder();
	bool to_polishorder();
	bool to_binarytree();

	void dump_node(NodeVec& nodeVec);
};

