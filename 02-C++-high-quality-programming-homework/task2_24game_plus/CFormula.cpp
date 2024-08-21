#include "pch.h"

#include "CFormula.h"

CFormula::CFormula()
{
}

CFormula::~CFormula()
{
	for (auto& node : m_treenode)
		SAFE_DELETE(node);

	m_treenode.clear();
	m_polishorder.clear();
}

bool CFormula::load_formula(string formula)
{
	bool bRet = true;

	m_instrFormula = formula;

	bRet = to_treenode();
	if (false == bRet)
	{
		return bRet;
	}

	bRet = to_inorder();
	if (false == bRet)
	{
		return bRet;
	}

	bRet = to_polishorder();
	if (false == bRet)
	{
		return bRet;
	}

	bRet = to_binarytree();
	if (false == bRet)
	{
		return bRet;
	}

	return bRet;
}

bool CFormula::to_treenode()
{
	bool bRet = true;

	CNode* tree_node = nullptr;
	string tmp_degital = "";

	for (auto it = m_instrFormula.rbegin(); it != m_instrFormula.rend(); ++it)
	{
		if ((*it >= '0') && (*it <= '9'))
		{
			tmp_degital = *it + tmp_degital;

			if (it == m_instrFormula.rend() - 1)
			{
				tree_node = new CDegital(tmp_degital);
				tmp_degital = "";
			}
			else if (*(it + 1) < '0' || *(it + 1) > '9')
			{
				tree_node = new CDegital(tmp_degital);
				tmp_degital = "";
			}
			else
			{
				continue;
			}
		}
		else if (*it == '+')
		{
			tree_node = new CPlus();
		}
		else if (*it == '*')
		{
			tree_node = new CMultiply();
		}
		else
		{
			cout << "formula char '" << *it << "' is wrong." << endl;
			return false;
		}

		m_treenode.push_back(tree_node);
	}

	return bRet;
}

bool CFormula::to_inorder()
{
	bool bRet = true;

	m_inorder.clear();

	for (auto& tree_node : m_treenode)
	{
		if (tree_node->is_rightbracket())
		{
			continue;
		}
		else if (tree_node->is_leftbracket())
		{
			continue;
		}
		else
		{
			m_inorder.push_back(tree_node);
		}
	}

	reverse(m_inorder.begin(), m_inorder.end());

	return bRet;
}

bool CFormula::to_polishorder()
{
	bool bRet = true;

	NodeVec stack1;
	CNode* stack1_pop;

	for (auto& tree_node : m_treenode)
	{
		if (tree_node->is_degital())
		{
			m_polishorder.push_back(tree_node);
		}
		else if (tree_node->is_rightbracket())
		{
			stack1.push_back(tree_node);
		}
		else if (tree_node->is_leftbracket())
		{
			do
			{
				if (stack1.size() == 0)
				{
					cout << "formula logic '" << tree_node->get_name() << "' is wrong." << endl;
					return false;
				}

				stack1_pop = stack1.back();
				stack1.pop_back();

				if (stack1_pop->is_rightbracket())
				{
					break;
				}
				else
				{
					m_polishorder.push_back(stack1_pop);
				}
			} while (true);
		}
		else
		{
			do
			{
				if (stack1.size() == 0)
				{
					stack1.push_back(tree_node);
					break;
				}
				else
				{
					stack1_pop = stack1.back();
					if (tree_node->weight() < stack1_pop->weight())
					{
						m_polishorder.push_back(stack1_pop);
						stack1.pop_back();
					}
					else
					{
						stack1.push_back(tree_node);
						break;
					}
				}
			} while (true);
		}
	}

	while (stack1.size() > 0)
	{
		stack1_pop = stack1.back();
		stack1.pop_back();
		m_polishorder.push_back(stack1_pop);
	}

	reverse(m_polishorder.begin(), m_polishorder.end());

	return bRet;
}

bool CFormula::to_binarytree()
{
	bool bRet = true;

	NodeIt polish_start, polish_end;
	NodeIt inorder_start, inorder_end;

	polish_start = m_polishorder.begin();
	polish_end = m_polishorder.end() - 1;

	inorder_start = m_inorder.begin();
	inorder_end = m_inorder.end() - 1;

	m_binarytree = build_tree(polish_start, polish_end,
		inorder_start, inorder_end);
	if (NULL == m_binarytree)
	{
		cout << "build tree fail." << endl;
		return false;
	}

	return bRet;
}

CNode* CFormula::build_tree(NodeIt ps, NodeIt pe, NodeIt is, NodeIt ie)
{
	CNode* tree_node = *ps;

	NodeIt ri = find(is, ie, tree_node);
	size_t left_len = ri - is;
	size_t right_len = ie - ri;

	if (left_len > 0)
	{
		CNode* left_node = build_tree(ps + 1, ps + left_len, is, ri - 1);
		tree_node->set_leftnode(left_node);
	}

	if (right_len > 0)
	{
		CNode* right_node = build_tree(ps + left_len + 1, pe, ri + 1, ie);
		tree_node->set_rightnode(right_node);
	}

	return tree_node;
}

bool CFormula::calc_formula()
{
	bool bRet = true;

	if (!m_binarytree)
	{
		cout << "binary tree is null." << endl;
		m_result = DBL_MAX;
		return false;
	}

	m_result = m_binarytree->calc();

	return bRet;
}

long long CFormula::get_result() const
{
	return m_result;
}

void CFormula::dump_nodeVec(NodeVec& nodeVec)
{
	for (auto& k : nodeVec)
	{
		cout << k->get_name();
	}
	cout << endl;
}

void CFormula::dump_nodeIt(NodeIt start, NodeIt end)
{
	for (auto it = start; it != end; it++)
	{
		cout << (*it)->get_name();
	}
	cout << endl;
}