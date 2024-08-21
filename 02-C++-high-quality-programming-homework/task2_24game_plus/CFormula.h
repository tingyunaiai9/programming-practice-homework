#pragma once

#include "CNode.h"

class CFormula
{
private:
	typedef vector<CNode*> NodeVec;
	typedef NodeVec::iterator NodeIt;

	string m_instrFormula;
	NodeVec m_treenode;
	NodeVec m_inorder;
	NodeVec m_polishorder;

	CNode* m_binarytree;

	double m_result;
	string m_optimizedFormula;

public:
	CFormula();
	~CFormula();

	bool load_formula(string formula);
	bool calc_formula();
	double get_result() const;

private:
	bool to_treenode();

	bool to_inorder();
	bool to_polishorder();
	bool to_binarytree();

	void dump_nodeVec(NodeVec& nodeVec);
	void dump_nodeIt(NodeIt start, NodeIt end);

	CNode* build_tree(NodeIt ps, NodeIt pe, NodeIt is, NodeIt ie);
};

